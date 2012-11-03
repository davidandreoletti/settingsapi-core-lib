//
//  SettingsReader.h
//  libsettingsapi
//
//  Created by Andreoletti David on 7/24/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#include <cstring>  // for strcpy(...)
#include <string>
#include "settingsapi/readers/impl/json/libjson0/SettingsReader.h"
#include "libjson/libjson.h"

namespace settingsapi {
namespace readers {
namespace impl {
namespace json {
namespace libjson0 {

typedef settingsapi::nodes::SettingNodeInterface SNI;
typedef settingsapi::nodes::SettingNode SN;

/**
 *  Identifies node type and returns its SettingNodeInterface::SettingNodeType equivalent
 *  \param n A libjson's node instance
 *\ \return Equivalent in SettingNodeInterface
 */
SNI::Type identifyNodeType(JSONNODE* n) {
    char nodeType = json_type(n);
    if (nodeType == JSON_NODE) {
        return SNI::TYPE_OBJECT;
    }
    if (nodeType == JSON_ARRAY) {
        return SNI::TYPE_ARRAY;
    }
    return SNI::TYPE_VALUE;
}

/**
 * Parses node recusively
 * \param parentLjn Libjson node to parse. NULL if no parent
 * \return SettingNode equivalent to parentLjn including children
 */
SN* parseRecusively(JSONNODE* parentLjn) {
    if (parentLjn == NULL || parentLjn == JSON_NULL) { return NULL;}

    SN* parentNode = new SN();
    parentNode->setType(identifyNodeType(parentLjn));
    parentNode->setKey(json_name(parentLjn));

    char* valueAsCString = json_as_string(parentLjn);
    std::string valueAsCPPString(valueAsCString);
    parentNode->setValue(valueAsCPPString);

    JSONNODE_ITERATOR it = json_begin(parentLjn);
    while (it != json_end(parentLjn)) {
        JSONNODE* child = *it;
        if (child == NULL || child == JSON_NULL) {
            return NULL;
        } else {
            SN* cn = parseRecusively(child);
            parentNode->addChildNode(reinterpret_cast<SNI*>(cn));
            ++it;
        }
    }
    return parentNode;
}

SettingsReader::~SettingsReader() {}

SN* SettingsReader::parse(std::string content) {
    char* contentAsCString = new char[content.size()+1];
    // Cannot use snprintf (defined from C++11)
    strcpy(contentAsCString, content.c_str());  // NOLINT(runtime/printf)
    JSONNODE* n = json_parse(contentAsCString);
    // Build node tree
    return parseRecusively(n);
}

}}}}}  // namespaces

//
//  SettingsWriter.h
//  libsettingsapi
//
//  Created by Andreoletti David on 7/24/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#include "./settingsapi/impl/json/libjson0/SettingsWriter.h"
#include <vector>
#include <string>
#include "libjson/libjson.h"

namespace settingsapi {
namespace impl {
namespace json {
namespace libjson0 {

/**
 *  Identifies node type and returns its libjson equivalent
 *  \param nodeType A SettingsAPI' settings type
 *\ \return Equivalent in libjson type
 */
    char identifyNodeType(settingsapi::SettingNodeInterface::Type nodeType) {
    if (nodeType == settingsapi::SettingNodeInterface::TYPE_OBJECT) {
        return JSON_NODE;
    }
    if (nodeType == settingsapi::SettingNodeInterface::TYPE_ARRAY) {
        return JSON_ARRAY;
    }
    return JSON_STRING;
}

/**
 * Builds Native Libjson Node tree recusively
 * \param pANode A SettingsAPI's Node.
 * \return libjson's equivalent to SettingNode including children. 
 *          If parentAbstractNode is null, then empty native node is returned
 */
JSONNODE* buildNativeJSONTreeNode(settingsapi::SettingNodeInterface* pANode) {
    if (pANode == NULL) {
        return json_new(identifyNodeType(settingsapi::SettingNodeInterface::TYPE_OBJECT));  // NOLINT(whitespace/line_length)
    }

    JSONNODE* pNNode = json_new(identifyNodeType(pANode->getType()));
    json_set_name(pNNode, pANode->getKey().c_str());

    switch (pANode->getType()) {
        case settingsapi::SettingNodeInterface::TYPE_VALUE:
        {
            json_set_a(pNNode, pANode->readString().c_str());
            break;
        }
        case settingsapi::SettingNodeInterface::TYPE_OBJECT:
        case settingsapi::SettingNodeInterface::TYPE_ARRAY:
        {
            std::vector<settingsapi::SettingNodeInterface*> children = pANode->getChildren();  // NOLINT(whitespace/line_length)
            std::vector<settingsapi::SettingNodeInterface*>::iterator it = children.begin();  // NOLINT(whitespace/line_length)
            while (it != children.end()) {
                settingsapi::SettingNodeInterface* cANode = *it;
                JSONNODE* cNChild = buildNativeJSONTreeNode(cANode);
                json_insert(pNNode, json_end(pNNode), cNChild);
                ++it;
            }
            break;
        }
        default:
            // Node is undefined type.
            break;
    }
    return pNNode;
}

SettingsWriter::~SettingsWriter() {}

std::string SettingsWriter::write(settingsapi::SettingNodeInterface* node) {
    JSONNODE* rootNode = buildNativeJSONTreeNode(node);
    std::string confContent = json_write_formatted(rootNode);
    return confContent;
}

}}}}  // namespaces

//
//  SettingsWriter.h
//  libsettingsapi
//
//  Created by Andreoletti David on 7/24/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#include "settingsapi/writers/impl/json/libjson0/SettingsWriter.h"
#include <vector>
#include <string>
#include "libjson/libjson.h"

namespace settingsapi {
namespace writers {
namespace impl {
namespace json {
namespace libjson0 {

typedef settingsapi::nodes::SettingNodeInterface SNI;

/**
 *  Identifies node type and returns its libjson equivalent
 *  \param nodeType A SettingsAPI' settings type
 *\ \return Equivalent in libjson type
 */
char identifyNodeType(SNI::Type nodeType) {
    if (nodeType == SNI::TYPE_OBJECT) {
        return JSON_NODE;
    }
    if (nodeType == SNI::TYPE_ARRAY) {
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
JSONNODE* buildNativeJSONTreeNode(SNI* pANode) {
    if (pANode == NULL) {
        return json_new(identifyNodeType(SNI::TYPE_OBJECT));
    }

    JSONNODE* pNNode = json_new(identifyNodeType(pANode->getType()));
    json_set_name(pNNode, pANode->getKey().c_str());

    switch (pANode->getType()) {
        case SNI::TYPE_VALUE:
        {
            json_set_a(pNNode, pANode->readString().c_str());
            break;
        }
        case SNI::TYPE_OBJECT:
        case SNI::TYPE_ARRAY:
        {
            std::vector<SNI*> children = pANode->getChildren();
            std::vector<SNI*>::iterator it = children.begin();
            while (it != children.end()) {
                SNI* cANode = *it;
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

std::string SettingsWriter::write(SNI* node) {
    JSONNODE* rootNode = buildNativeJSONTreeNode(node);
    std::string confContent = json_write_formatted(rootNode);
    return confContent;
}

}}}}}  // namespaces

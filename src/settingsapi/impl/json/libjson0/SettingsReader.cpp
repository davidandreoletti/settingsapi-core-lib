//
//  SettingsReader.h
//  libsettingsapi
//
//  Created by Andreoletti David on 7/24/12. 
//  Copyright 2012 IO Stark. All rights reserved.
//

#include <cstring> //  for strcpy(...)
#include "./settingsapi/impl/json/libjson0/SettingsReader.h"
#include "libjson/libjson.h"

namespace settingsapi {
namespace impl {
namespace json {
namespace libjson0 {
    
/**
 *  Identifies node type and returns its SettingNodeInterface::SettingNodeType equivalent
 *  \param n A libjson's node instance
 *\ \return Equivalent in SettingNodeInterface
 */
SettingNodeInterface::SettingNodeType identifyNodeType(JSONNODE* n)
{
    char nodeType = json_type(n);
    if (nodeType == JSON_NODE) {
        return SettingNodeInterface::SettingNodeType::OBJECT;
    }
    if (nodeType == JSON_ARRAY) {
        return SettingNodeInterface::SettingNodeType::ARRAY;
    }
    return SettingNodeInterface::SettingNodeType::VALUE;
}
    
/**
 * Parses node recusively
 * \param parentLjn Libjson node to parse. NULL if no parent
 * \return SettingNode equivalent to parentLjn including children
 */
SettingNode* parseRecusively(JSONNODE* parentLjn)
{
    if (parentLjn == NULL || parentLjn == JSON_NULL){ return NULL;}
    
    SettingNode* parentNode = new SettingNode();
    parentNode->setType(identifyNodeType(parentLjn));
    parentNode->setInternalNode((void*)parentLjn);
    parentNode->setKey(json_name(parentLjn));
    
    char* valueAsCString = json_as_string(parentLjn);
    std::string valueAsCPPString(valueAsCString);
    parentNode->setValue(valueAsCPPString);
    
    JSONNODE_ITERATOR it = json_begin(parentLjn);
    while (it != json_end(parentLjn)){
        JSONNODE* child = *it;
        if (child == NULL || child == JSON_NULL){
            return NULL;
        }
        else{
            SettingNode* cn = parseRecusively(child);
            parentNode->addChildNode((SettingNodeInterface*)cn);
            // Increment the iterator
            ++it;
        }
    }
    return parentNode;
}

SettingsReader::~SettingsReader(){

}
    
SettingNode* SettingsReader::parse(std::string content) {
    char* contentAsCString = new char[content.size()+1];
    strcpy(contentAsCString, content.c_str());
    JSONNODE* n = json_parse(contentAsCString);
    // Build node tree
    return parseRecusively(n);
}
    
}}}}  // namespaces

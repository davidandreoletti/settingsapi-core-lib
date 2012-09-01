//
//  SettingNode.cpp
//  libsettingsapi
//
//  Created by Andreoletti David on 7/24/12. 
//  Copyright 2012 IO Stark. All rights reserved.
//

#include <errno.h>
#include <cstdlib>
#include "./settingsapi/SettingNode.h"

namespace settingsapi {

SettingNodeInterface::SettingNodeType SettingNode::getType() {
    return this->type_;
}
    
void SettingNode::setType(SettingNodeInterface::SettingNodeType type) {
    this->type_ = type;
}

std::string SettingNode::getKey() {
    return this->key_;
}
    
void SettingNode::setKey(std::string key)
{
    this->key_ = key;
}

std::string SettingNode::readString() {
    return this->value_;
}
    
int SettingNode::readInt32(stringToInt32_Status &r) {
    const char* valueAsCString = this->value_.c_str();
    char *end;
    long  l;
    errno = 0;
    l = strtol(valueAsCString, &end, 0);
    if ((errno == ERANGE && l == LONG_MAX) || l > INT_MAX) {
        r = OVERFLOW;
        return l;
    }
    if ((errno == ERANGE && l == LONG_MIN) || l < INT_MIN) {
        r =  UNDERFLOW;
        return l;
    }
    if (*valueAsCString == '\0' || *end != '\0') {
        r = INCONVERTIBLE;
        return l;
    }
    r = SUCCESS;
    return l;
}

void SettingNode::lookupValue(std::string key, SettingNodeInterface* value) {
    std::vector<SettingNodeInterface*>::iterator it = this->childrenNodes_.begin();
    bool valueNodeFound = false;
    while(it != this->childrenNodes_.end())
    {
        if (!valueNodeFound && ((*it)->getKey() == key))
        {
            value = *it;
            valueNodeFound = true;
        }
        ++it;
    }
}
    
void SettingNode::setValue(std::string value){
    this->value_ = value;
}

bool SettingNode::empty() {
    return this->childrenNodes_.empty();
}

SettingNodeInterface* SettingNode::getParentNode() {
    return this->parentNode_;
}

void SettingNode::setParentNode(SettingNodeInterface* node) {
    this->parentNode_ = node;
}

void SettingNode::addChildNode(SettingNodeInterface* node)
{
    this->childrenNodes_.push_back(node);
    node->setParentNode(this);
}

std::vector<SettingNodeInterface*> SettingNode::getChildren() {

    return this->childrenNodes_;
}
    
void* SettingNode::getInternalNode() {
    return this->internalNode_;
}
    
void SettingNode::setInternalNode(void* node) {
    this->internalNode_ = node;
}

}  // namespaces

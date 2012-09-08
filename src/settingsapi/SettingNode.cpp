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

SettingNode::SettingNode() {
    this->type_ = SettingNodeType::UNDEFINED;
    this->key_ = "";
    this->value_= "";
    this->childrenNodes_ = std::vector<SettingNodeInterface*>();
    this->parentNode_ = NULL;
    this->internalNode_ = NULL;
}

    
SettingNode::~SettingNode() {

}
    
SettingNodeInterface::SettingNodeType SettingNode::getType() const {
    return this->type_;
}
    
void SettingNode::setType(SettingNodeInterface::SettingNodeType type) {
    this->type_ = type;
}

std::string SettingNode::getKey() const {
    return this->key_;
}
    
void SettingNode::setKey(std::string key)
{
    this->key_ = key;
}

std::string SettingNode::readString() const {
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
    
void SettingNode::setValue(std::string value){
    if (this->getType() == SettingNodeType::VALUE)
    {
        this->value_ = value;
    }
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
    if (this->getType() == SettingNodeType::OBJECT
        || this->getType() == SettingNodeType::ARRAY)
    {
        this->childrenNodes_.push_back(node);
        node->setParentNode(this);
    }
}

std::vector<SettingNodeInterface*> SettingNode::getChildren() const {

    return this->childrenNodes_;
}
    
bool SettingNode::equalsTreeNode(const SettingNodeInterface& node) const {
    if (this == &node) {return true;}
    
    // Check nodes themselves are equal
    if (!this->equalsNode(node)) {return false;}

    // Check nodes have same number of children
    size_t aSize = this->childrenNodes_.size();
    size_t bSize = node.getChildren().size();
    if (aSize != bSize) {return false;}
    if (aSize == 0) {return true;}
    
    // Check each child in both nodes are equals 
    std::vector<SettingNodeInterface*>::const_iterator ita = this->childrenNodes_.begin();
    std::vector<SettingNodeInterface*>::const_iterator itb = node.getChildren().begin();
    
    bool isTreeNodeEqual = false;
    while (ita != this->childrenNodes_.end()
           && itb != node.getChildren().end()) {
        isTreeNodeEqual = ((*ita)->equalsTreeNode(*(*itb)));
        ++ita;
        ++itb;
    }
//
//    
//    while (ita != this->childrenNodes_.end()
//           && itb != node.getChildren().end()
//           && (*ita)->equalsTreeNode(*(*itb))) {
//        ++ita;
//        ++itb;
//    }
    return isTreeNodeEqual;
}
    
bool SettingNode::equalsNode(const SettingNodeInterface& node) const {
    if (&node == NULL) {return false;}
    if (this == &node) {return true;}
    if ((this->getKey().compare(node.getKey()) != 0)
        || (this->readString().compare(node.readString()) != 0)
        || (this->getType() != node.getType()))
    {
        return false;
    }
    return true;
}

    
void* SettingNode::getInternalNode() {
    return this->internalNode_;
}
    
void SettingNode::setInternalNode(void* node) {
    this->internalNode_ = node;
}

}  // namespaces

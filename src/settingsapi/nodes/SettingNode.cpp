//
//  SettingNode.cpp
//  libsettingsapi
//
//  Created by Andreoletti David on 7/24/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#include <errno.h>
#include <cstdlib>
#include <climits>
#include <vector>
#include <string>
#include "settingsapi/nodes/SettingNode.h"

namespace settingsapi {
namespace nodes {

typedef settingsapi::nodes::SettingNodeInterface SNI;

SettingNode::SettingNode() {
    this->type_ = SettingNodeInterface::TYPE_UNDEFINED;
    this->key_ = "";
    this->value_= "";
    this->childrenNodes_ = std::vector<SettingNodeInterface*>();
    this->parentNode_ = NULL;
}

SettingNode::~SettingNode() {}

SNI::Type SettingNode::getType() const {
    return this->type_;
}

void SettingNode::setType(SNI::Type type) {
    this->type_ = type;
}

std::string SettingNode::getKey() const {
    return this->key_;
}

void SettingNode::setKey(std::string key) {
    this->key_ = key;
}

std::string SettingNode::readString() const {
    return this->value_;
}

int SettingNode::readInt32(StringToInt32ConversionStatus& r) const {  // NOLINT(*) runtime/references, whitespace/line_length
    const char* valueAsCString = this->value_.c_str();
    char *end;
    int32_t  l;
    errno = 0;
    l = strtol(valueAsCString, &end, 0);
    if ((errno == ERANGE && l == LONG_MAX) || l > INT_MAX) {
        r = STRINGTOINT32CONVERTIONSTATUS_OVERFLOW;
        return l;
    }
    if ((errno == ERANGE && l == LONG_MIN) || l < INT_MIN) {
        r =  STRINGTOINT32CONVERTIONSTATUS_UNDERFLOW;
        return l;
    }
    if (*valueAsCString == '\0' || *end != '\0') {
        r = STRINGTOINT32CONVERTIONSTATUS_INCONVERTIBLE;
        return l;
    }
    r = STRINGTOINT32CONVERTIONSTATUS_SUCCESS;
    return l;
}

void SettingNode::setValue(std::string value) {
    if (this->getType() == SettingNodeInterface::TYPE_VALUE) {
        this->value_ = value;
    }
}

bool SettingNode::empty() {
    return this->childrenNodes_.empty();
}

SNI* SettingNode::getParentNode() {
    return this->parentNode_;
}

void SettingNode::setParentNode(SNI* node) {
    this->parentNode_ = node;
}

void SettingNode::addChildNode(SNI* node) {
    if (this->getType() == SNI::TYPE_OBJECT
        || this->getType() == SNI::TYPE_ARRAY) {
        this->childrenNodes_.push_back(node);
        node->setParentNode(this);
    }
}

std::vector<SNI*> SettingNode::getChildren() const {
    return this->childrenNodes_;
}

bool SettingNode::equalsTreeNode(const SNI& node) const {
    if (this == &node) {return true;}

    // Check nodes themselves are equal
    if (!this->equalsNode(node)) {return false;}

    // Check nodes have same number of children
    size_t aSize = this->childrenNodes_.size();
    size_t bSize = node.getChildren().size();
    if (aSize != bSize) {return false;}
    if (aSize == 0) {return true;}

    // Check each child in both nodes are equals
    std::vector<SNI*>::const_iterator ita = this->childrenNodes_.begin();
    std::vector<SNI*>::const_iterator itb = node.getChildren().begin();

    bool isTreeNodeEqual = false;
    while (ita != this->childrenNodes_.end()
           && itb != node.getChildren().end()) {
        isTreeNodeEqual = ((*ita)->equalsTreeNode(*(*itb)));
        ++ita;
        ++itb;
    }
    return isTreeNodeEqual;
}

bool SettingNode::equalsNode(const SNI& node) const {
    if (&node == NULL) {return false;}
    if (this == &node) {return true;}
    if ((this->getKey().compare(node.getKey()) != 0)
        || (this->readString().compare(node.readString()) != 0)
        || (this->getType() != node.getType())) {
        return false;
    }
    return true;
}

}}  // namespaces

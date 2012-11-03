//
//  SettingNode.h
//  libsettingsapi
//
//  Created by Andreoletti David on 7/24/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#ifndef INCLUDE_SETTINGSAPI_NODES_SETTINGNODE_H_
#define INCLUDE_SETTINGSAPI_NODES_SETTINGNODE_H_

#include <string>
#include <vector>
#include "settingsapi/nodes/SettingNodeInterface.h"

namespace settingsapi {
namespace nodes {

/**
 *  SettingNode is a Node representing a setting
 */
class SettingNode :  public settingsapi::nodes::SettingNodeInterface {
 public:
    typedef settingsapi::nodes::SettingNodeInterface SNI;

    /**
     * Default constructor
     */
    SettingNode();

    // Inherited from SettingNodeInterface
    virtual ~SettingNode();
    virtual SNI::Type getType() const;
    virtual void setType(SNI::Type type);
    virtual std::string getKey() const;
    virtual void setKey(std::string key);
    virtual std::string readString() const;
    virtual int readInt32(StringToInt32ConversionStatus& r) const;  // NOLINT(*) whitespace/line_length,runtime/references
    virtual void setValue(std::string value);
    virtual bool empty();
    virtual SNI* getParentNode();
    virtual void setParentNode(SNI* node);
    virtual void addChildNode(SNI* node);
    virtual std::vector<SettingNodeInterface*> getChildren() const;
    virtual bool equalsTreeNode(const SNI& node) const;
    virtual bool equalsNode(const SNI& node) const;

 private:
 	/**
 	 * Node type
 	 */ 
    SNI::Type type_;

 	/**
 	 * Node's key
 	 */ 
    std::string key_;

 	/**
 	 * Node's value
 	 */
    std::string value_;

 	/**
 	 * Node's parent
 	 */ 
    SNI* parentNode_;

 	/**
 	 * Node's children
 	 */ 
    std::vector<SNI*> childrenNodes_;
};

}}  // namespaces

#endif  // INCLUDE_SETTINGSAPI_NODES_SETTINGNODE_H_


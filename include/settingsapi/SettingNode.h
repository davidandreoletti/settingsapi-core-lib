//
//  SettingNode.h
//  libsettingsapi
//
//  Created by Andreoletti David on 7/24/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#ifndef INCLUDE_SETTINGSAPI_SETTINGNODE_H_
#define INCLUDE_SETTINGSAPI_SETTINGNODE_H_

#include <string>
#include <vector>
#include "settingsapi/SettingNodeInterface.h"

namespace settingsapi {

/**
 *  SettingNode is a Node representing a setting
 */
class SettingNode :  public SettingNodeInterface {
 public:
    /**
     * Default constructor
     */
    SettingNode();

    // Inherited from SettingNodeInterface
    virtual ~SettingNode();
    virtual SettingNodeInterface::Type getType() const;
    virtual void setType(SettingNodeInterface::Type type);
    virtual std::string getKey() const;
    virtual void setKey(std::string key);
    virtual std::string readString() const;
    virtual int readInt32(StringToInt32ConversionStatus& r) const;  // NOLINT(*) whitespace/line_length,runtime/references
    virtual void setValue(std::string value);
    virtual bool empty();
    virtual SettingNodeInterface* getParentNode();
    virtual void setParentNode(SettingNodeInterface* node);
    virtual void addChildNode(SettingNodeInterface* node);
    virtual std::vector<SettingNodeInterface*> getChildren() const;
    virtual bool equalsTreeNode(const SettingNodeInterface& node) const;
    virtual bool equalsNode(const SettingNodeInterface& node) const;

    /**
     * Gets internal node as returned by parser
     * \return Internal node
     */
    virtual void* getInternalNode();

    /**
     * Sets the internal node returned by parser to this node
     * \param node Library specific node representation
     */
    virtual void setInternalNode(void* node);

 private:
 	/**
 	 * Node type
 	 */ 
    SettingNodeInterface::Type type_;

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
    SettingNodeInterface* parentNode_;

 	/**
 	 * Node's children
 	 */ 
    std::vector<SettingNodeInterface*> childrenNodes_;

 	/**
 	 * Node's internal node
 	 */
    void* internalNode_;
};

}  // namespaces

#endif  // INCLUDE_SETTINGSAPI_SETTINGNODE_H_


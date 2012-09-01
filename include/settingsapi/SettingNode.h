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
#include "./SettingNodeInterface.h"

namespace settingsapi {

/**
 *  SettingNode is a Node representing a setting
 */
class SettingNode :  SettingNodeInterface {
 public:
    // Inherited from SettingNodeInterface
    virtual SettingNodeInterface::SettingNodeType getType();
    virtual void setType(SettingNodeInterface::SettingNodeType type);
    virtual std::string getKey();
    virtual void setKey(std::string key);
    virtual std::string readString();
    virtual int readInt32(stringToInt32_Status &r);
    virtual void lookupValue(std::string key, SettingNodeInterface* value);
    virtual void setValue(std::string value);
    virtual bool empty();
    virtual SettingNodeInterface* getParentNode();
    virtual void setParentNode(SettingNodeInterface* node);
    virtual void addChildNode(SettingNodeInterface* node);
    virtual std::vector<SettingNodeInterface*> getChildren();
    
    /**
     * Gets internal node as returned by parser
     * \return Internal node
     */
    virtual void* getInternalNode();
    
    /**
     * Sets the internal node returned by parser to this node
     * \param Internal node
     */
    virtual void setInternalNode(void* node);
 private:
 	/**
 	 * Node type
 	 */ 
 	SettingNodeInterface::SettingNodeType type_;

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

#endif // INCLUDE_SETTINGSAPI_SETTINGNODE_H_


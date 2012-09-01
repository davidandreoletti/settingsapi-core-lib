//
//  SettingNodeInterface.h
//  libsettingsapi
//
//  Created by Andreoletti David on 7/24/12. 
//  Copyright 2012 IO Stark. All rights reserved.
//

#ifndef INCLUDE_SETTINGSAPI_SETTINGNODEINTERFACE_H_
#define INCLUDE_SETTINGSAPI_SETTINGNODEINTERFACE_H_

#include <string>
#include <vector>

namespace settingsapi {

/**
 *  A setting node represents a key and associated value
 */
class SettingNodeInterface {
 public:

    /**
     * Node's types
     */
    enum SettingNodeType {
        OBJECT,
        ARRAY,
        VALUE
    };

    /**
     * Gets node's type
     * \return Type.
     */
    virtual SettingNodeType getType() = 0;
    
    /**
     * Sets this node's type
     * \param Type.
     */
    virtual void setType(SettingNodeType type) = 0;
    
    /**
     * Gets key
     * \return Key
     */
    virtual std::string getKey() = 0;
    
    /**
     * Sets key
     * \param key The key
     */
    virtual void setKey(std::string key) = 0;
    
    /**
     * Read a setting's value as string
     * \return String value
     */
    virtual std::string readString() = 0;
    
    enum stringToInt32_Status { SUCCESS, OVERFLOW, UNDERFLOW, INCONVERTIBLE };
    
    /**
     * Read a setting's value as 32 bits integer
     * \param r Conversion status. Valid values: any in stringToint32_Status
     * \return Integer value
     */
    virtual int readInt32(stringToInt32_Status &r) = 0;
    
    /**
     * Get the value associated to the key from this node
     * \param key Key
     * \param value Pointer to value. NULL if no node found
     */
    virtual void lookupValue(std::string key, SettingNodeInterface* value) = 0;
    
    /**
     * Set the value associated to the key
     * \param value The value
     */
    virtual void setValue(std::string value) = 0;
    
    /**
     * Gets whether node has children
     * \return False if node has no child.
     */
    virtual bool empty() = 0;
    
    /**
     * Gets the parent node
     * \return Null if root node
     */
    virtual SettingNodeInterface* getParentNode() = 0;
    
    /**
     * Sets the parent node
     * \param New parent node
     */
    virtual void setParentNode(SettingNodeInterface* node) = 0;
    
    /**
     * Add a child to this node
     * \param node New child
     */
    virtual void addChildNode(SettingNodeInterface* node) = 0;

    /**
     * Returns this node's children
     * \return Children
     */
    virtual std::vector<SettingNodeInterface*> getChildren() = 0;
};

}  // namespaces

#endif  // INCLUDE_SETTINGSAPI_SETTINGNODEINTERFACE_H_

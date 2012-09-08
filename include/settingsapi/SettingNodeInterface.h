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
 *  Represents a node with a key, a value and some children, etc
 */
class SettingNodeInterface {
 public:

    /**
     *  Destructor
     */
    virtual ~SettingNodeInterface() = 0;
    
    /**
     * Types
     */
    enum SettingNodeType {
        UNDEFINED,         /** Undefined */
        OBJECT,            /** Object */
        ARRAY,             /** Array */
        VALUE              /** Value */
    };

    /**
     * Gets type
     * \return Type.
     */
    virtual SettingNodeType getType() const = 0;
    
    /**
     * Sets type
     * \param Type.
     */
    virtual void setType(SettingNodeType type) = 0;
    
    /**
     * Gets key
     * \return Key
     */
    virtual std::string getKey() const = 0;
    
    /**
     * Sets key
     * \param key The key
     */
    virtual void setKey(std::string key) = 0;
    
    /**
     * Read a setting's value as string
     * \return String value
     */
    virtual std::string readString() const = 0;
    
    enum stringToInt32_Status { SUCCESS, OVERFLOW, UNDERFLOW, INCONVERTIBLE };
    
    /**
     * Read a setting's value as 32 bits integer
     * \param r Conversion status. Valid values: any in stringToint32_Status
     * \return Integer value
     */
    virtual int readInt32(stringToInt32_Status &r) = 0;
    
    /**
     * Set the value associated to the key:
     * - if type is \link SettingNodeType::VALUE \endlink, then this node value is set
     * - if type is NOT \link SettingNodeType::VALUE \endlink, then this node value is NOT set
     * \param value The value
     */
    virtual void setValue(std::string value) = 0;
    
    /**
     * Gets whether this node has children
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
     * Adds a child to this node if and only if this node is of type \link SettingNodeType::OBJECT \endlink or \link SettingNodeType::ARRAY \endlink
     * 
     * \param node New child
     */
    virtual void addChildNode(SettingNodeInterface* node) = 0;

    /**
     * Gets children
     * \return Children
     */
    virtual std::vector<SettingNodeInterface*> getChildren() const = 0;
    
    /**
     * Check if both -trees node- are equals
     *
     * Two tree nodes are equals if and only if:
     * - each tree has the same tree structures
     * - each nodes within the tree structure are equal. See \link ::equalsNode(const SettingNodeInterface&) \endlink
     * \param node Tree Node to check against
     * \return True if both are equal
     */
    virtual bool equalsTreeNode(const SettingNodeInterface& node) const = 0;
    
    /**
     * Check if both -node- are equals
     *
     * Two nodes are equals if and only if:
     * - types are identical
     * - keys are identical
     * - values are identical
     * \param node Tree Node to check against
     * \return True if both are equal
     */
    virtual bool equalsNode(const SettingNodeInterface& node) const = 0;
    
};

inline SettingNodeInterface::~SettingNodeInterface(){}
    
}  // namespaces

#endif  // INCLUDE_SETTINGSAPI_SETTINGNODEINTERFACE_H_

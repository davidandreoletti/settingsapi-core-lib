//
//  SettingsReaderInterface.h
//  libsettingsapi
//
//  Created by Andreoletti David on 7/24/12. 
//  Copyright 2012 IO Stark. All rights reserved.
//

#ifndef INCLUDE_SETTINGSAPI_SETTINGSREADERINTERFACE_H_
#define INCLUDE_SETTINGSAPI_SETTINGSREADERINTERFACE_H_

#include "./SettingNode.h"

#include <string>

namespace settingsapi {

/**
 *  Settings Reader interface
 */
class SettingsReaderInterface {
 public:
    
    /**
     *  Destructor
     */
    virtual ~SettingsReaderInterface() = 0;
    
    /**
     * Parses a settings file content
     * \param content File content to parse
     * \return Root node of the full node tree. NULL if parsing failed
     */
    virtual SettingNode* parse(std::string content) = 0;
};
    
/**
 * Pure virtual destructor implementation is required.
 * See http://stackoverflow.com/questions/630950/pure-virtual-destructor-in-c
 */
inline SettingsReaderInterface::~SettingsReaderInterface(){}

}  // namespaces

#endif  // INCLUDE_SETTINGSAPI_SETTINGSREADERINTERFACE_H_

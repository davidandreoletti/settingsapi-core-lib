//
//  SettingsAPI.h
//  libsettingsapi
//
//  Created by Andreoletti David on 7/24/12. 
//  Copyright 2012 IO Stark. All rights reserved.
//

#ifndef INCLUDE_SETTINGSAPI_SETTINGSAPI_H_
#define INCLUDE_SETTINGSAPI_SETTINGSAPI_H_

#include <string>

namespace settingsapi {

class SettingNodeInterface;

/**
 *  Public Settings API
 */
class SettingsAPI {
 public:
    /**
     * Reads a configuration file's content
     * \param settingsFileContent File's content
     * \return Root SettingNodeInterface representing root of the entire tree node
     */
    SettingNodeInterface* readConfigurationFile(std::string configurationFileContent);

    /**
     * Writes configuration file
     * \param node Root node of the full tree node hierarchy
     * \return String representation of the node tree hierarchy
     */
    std::string writeConfigurationFile(SettingNodeInterface* node);
    
    /**
     * Creates an empty SettingNodeInterface instance
     * \return A new node instance
     */
    SettingNodeInterface* createNode();
};

}  // namespaces

#endif  // INCLUDE_SETTINGSAPI_SETTINGSAPI_H_

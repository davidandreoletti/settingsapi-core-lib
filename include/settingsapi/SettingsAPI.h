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
     * Reads configuration file
     * \param settingsFileContent File's content to extract settings from
     * \return Parsed Settings file.
     */
    SettingNodeInterface* readConfigurationFile(std::string configurationFileContent);
 private:
    /**
     * Concrete implementation.
     */
//    class SettingsAPIImpl;
//    SettingsAPIImpl* settingsAPIImpl;
};

}  // namespaces

#endif  // INCLUDE_SETTINGSAPI_SETTINGSAPI_H_

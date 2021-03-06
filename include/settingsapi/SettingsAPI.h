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
namespace nodes { class SettingNodeInterface; }

/**
 *  Public Settings API
 */
class SettingsAPI {
 public:
    typedef settingsapi::nodes::SettingNodeInterface SNI;

    /**
     * Reads a configuration file's content
     * \param configurationFileContent File's content
     * \return Root SettingNodeInterface representing root of the entire tree node. Caller owns the pointer.
     */
    SNI* readConfigurationFile(std::string configurationFileContent);

    /**
     * Writes configuration file
     * \param node Root node of the full tree node hierarchy. Caller owns the pointer.
     * \return String representation of the full node tree hierarchy
     *
     * A note can be created with:
     * \code[.cpp]
     * SettingNodeInterface* node = reinterpret_cast<SettingNodeInterface*> (new settingsapi::SettingNode());
     * \endcode
     */
    std::string writeConfigurationFile(SNI* node);
};

}  // namespaces

#endif  // INCLUDE_SETTINGSAPI_SETTINGSAPI_H_

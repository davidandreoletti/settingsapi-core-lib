//
//  SettingsReaderInterface.h
//  libsettingsapi
//
//  Created by Andreoletti David on 7/24/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#ifndef INCLUDE_SETTINGSAPI_READERS_SETTINGSREADERINTERFACE_H_
#define INCLUDE_SETTINGSAPI_READERS_SETTINGSREADERINTERFACE_H_

#include "settingsapi/nodes/SettingNode.h"

#include <string>  // NOLINT(build/include_order)

namespace settingsapi {
namespace readers {

/**
 *  Settings Reader interface
 */
class SettingsReaderInterface {
 public:
    typedef settingsapi::nodes::SettingNode SN;

    /**
     *  Destructor
     */
    virtual ~SettingsReaderInterface() = 0;

    /**
     * Reads a settings file content
     * \param content File content
     * \return Root node of the full node tree hierarchy. NULL if parsing failed
     */
    virtual SN* parse(std::string content) = 0;
};

/**
 * Pure virtual destructor implementation is required.
 * See http://stackoverflow.com/questions/630950/pure-virtual-destructor-in-c
 */
inline SettingsReaderInterface::~SettingsReaderInterface() {}

}}  // namespaces

#endif  // INCLUDE_SETTINGSAPI_READERS_SETTINGSREADERINTERFACE_H_

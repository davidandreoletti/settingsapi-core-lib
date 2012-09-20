//
//  SettingsReader.h
//  libsettingsapi
//
//  Created by Andreoletti David on 7/24/12. 
//  Copyright 2012 IO Stark. All rights reserved.
//

#ifndef INCLUDE_SETTINGSAPI_IMPL_JSON_LIBJSON_SETTINGSREADER_H_
#define INCLUDE_SETTINGSAPI_IMPL_JSON_LIBJSON_SETTINGSREADER_H_

#include "./settingsapi/SettingsReaderInterface.h"

namespace settingsapi {
namespace impl {
namespace json {
namespace libjson0 {

/**
 *  Settings JSON Reader using libjson (http://sourceforge.net/projects/libjson/)
 */
class SettingsReader : settingsapi::SettingsReaderInterface {
 private:
    // Inherits from SettingsReaderInterface
    virtual ~SettingsReader();
    virtual settingsapi::SettingNode* parse(std::string content);
};

}}}}  // namespaces

#endif  // INCLUDE_SETTINGSAPI_IMPL_JSON_LIBJSON_SETTINGSREADER_H_

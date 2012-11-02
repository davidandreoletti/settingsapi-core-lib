//
//  SettingsReader.h
//  libsettingsapi
//
//  Created by Andreoletti David on 7/24/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#ifndef INCLUDE_SETTINGSAPI_READERS_IMPL_JSON_LIBJSON0_SETTINGSREADER_H_
#define INCLUDE_SETTINGSAPI_READERS_IMPL_JSON_LIBJSON0_SETTINGSREADER_H_

#include "settingsapi/readers/SettingsReaderInterface.h"

#include <string>  // NOLINT(build/include_order)

namespace settingsapi {
namespace readers {
namespace impl {
namespace json {
namespace libjson0 {

/**
 *  Settings JSON Reader using libjson (http://sourceforge.net/projects/libjson/)
 */
class SettingsReader : settingsapi::readers::SettingsReaderInterface {
 private:
    typedef settingsapi::nodes::SettingNode SN;

    // Inherits from SettingsReaderInterface
    virtual ~SettingsReader();
    virtual SN* parse(std::string content);
};

}}}}}  // namespaces

#endif  // INCLUDE_SETTINGSAPI_READERS_IMPL_JSON_LIBJSON0_SETTINGSREADER_H_

//
//  SettingsWriter.h
//  libsettingsapi
//
//  Created by Andreoletti David on 7/24/12. 
//  Copyright 2012 IO Stark. All rights reserved.
//

#ifndef INCLUDE_SETTINGSAPI_IMPL_JSON_LIBJSON_SETTINGSWRITER_H_
#define INCLUDE_SETTINGSAPI_IMPL_JSON_LIBJSON_SETTINGSWRITER_H_

#include "./settingsapi/SettingsWriterInterface.h"

namespace settingsapi {
namespace impl {
namespace json {
namespace libjson0 {

/**
 *  Settings JSON Writer using libjson (http://sourceforge.net/projects/libjson/)
 */
class SettingsWriter : settingsapi::SettingsWriterInterface {
 private:
    // Inherits from SettingsWriterInterface
    virtual ~SettingsWriter();
    virtual std::string write(settingsapi::SettingNodeInterface* node);
};

}}}}  // namespaces

#endif  // INCLUDE_SETTINGSAPI_IMPL_JSON_LIBJSON_SETTINGSWRITER_H_

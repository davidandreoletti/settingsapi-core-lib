//
//  SettingsWriter.h
//  libsettingsapi
//
//  Created by Andreoletti David on 7/24/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#ifndef INCLUDE_SETTINGSAPI_WRITERS_IMPL_JSON_LIBJSON0_SETTINGSWRITER_H_
#define INCLUDE_SETTINGSAPI_WRITERS_IMPL_JSON_LIBJSON0_SETTINGSWRITER_H_

#include "settingsapi/writers/SettingsWriterInterface.h"

#include <string>  // NOLINT(build/include_order)

namespace settingsapi {
namespace writers {
namespace impl {
namespace json {
namespace libjson0 {

/**
 *  Settings JSON Writer using libjson (http://sourceforge.net/projects/libjson/)
 */
class SettingsWriter : settingsapi::writers::SettingsWriterInterface {
 private:
    typedef settingsapi::nodes::SettingNodeInterface SNI;

    // Inherits from SettingsWriterInterface
    virtual ~SettingsWriter();
    virtual std::string write(SNI* node);
};

}}}}}  // namespaces

#endif  // INCLUDE_SETTINGSAPI_WRITERS_IMPL_JSON_LIBJSON0_SETTINGSWRITER_H_

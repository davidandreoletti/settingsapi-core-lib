//
//  SettingsAPI.cpp
//  libsettingsapi
//
//  Created by Andreoletti David on 7/24/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#include <stack>
#include <string>

#include "./settingsapi/SettingsAPI.h"
#include "./settingsapi/SettingsReaderInterface.h"
#include "./settingsapi/SettingNodeInterface.h"

#if defined(USE_LIBRARY_LIBJSON)
//  Use libjson library as implementation backend
#   include "./settingsapi/impl/json/libjson0/SettingsReader.h"
#   include "./settingsapi/impl/json/libjson0/SettingsWriter.h"
#endif

namespace settingsapi {

settingsapi::SettingNodeInterface* SettingsAPI::readConfigurationFile(std::string configurationFileContent) {  // NOLINT(whitespace/line_length)
    typedef settingsapi::SettingsReaderInterface SRI;
    typedef settingsapi::SettingNodeInterface SNI;
    SNI* n = NULL;
    SRI* sni = NULL;
#if defined(USE_LIBRARY_LIBJSON)
    namespace ijl = impl::json::libjson0;
    typedef ijl::SettingsReader SR;
    sni = reinterpret_cast<SRI*>(new SR());
    n = reinterpret_cast<SNI*>(sni->parse(configurationFileContent));
#else
#   error No underlying library specified. Read documentation for further info.
#endif
    delete sni;
    return n;
}

std::string SettingsAPI::writeConfigurationFile(settingsapi::SettingNodeInterface* node) {  // NOLINT(whitespace/line_length)
    typedef settingsapi::SettingsWriterInterface SWI;
    typedef settingsapi::SettingNodeInterface SNI;
#if defined(USE_LIBRARY_LIBJSON)
    namespace ijl = impl::json::libjson0;
    typedef ijl::SettingsWriter SW;
    SWI* swi = NULL;
    swi = reinterpret_cast<SWI*>(new SW());
    return swi->write(node);
#else
#   error No underlying library specified. Read documentation for further info.
#endif
}

}  // namespaces

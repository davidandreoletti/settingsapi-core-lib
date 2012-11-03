//
//  SettingsAPI.cpp
//  libsettingsapi
//
//  Created by Andreoletti David on 7/24/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#include <stack>
#include <string>

#include "settingsapi/SettingsAPI.h"
#include "settingsapi/readers/SettingsReaderInterface.h"
#include "settingsapi/nodes/SettingNodeInterface.h"

#if defined(USE_LIBRARY_LIBJSON)
//  Use libjson library as implementation backend
#   include "./settingsapi/readers//impl/json/libjson0/SettingsReader.h"
#   include "./settingsapi/writers/impl/json/libjson0/SettingsWriter.h"
#endif

namespace settingsapi {

typedef settingsapi::readers::SettingsReaderInterface SRI;
typedef settingsapi::nodes::SettingNodeInterface SNI;
typedef settingsapi::writers::SettingsWriterInterface SWI;
typedef settingsapi::nodes::SettingNodeInterface SNI;
#if defined(USE_LIBRARY_LIBJSON)
typedef settingsapi::readers::impl::json::libjson0::SettingsReader SR;
typedef settingsapi::writers::impl::json::libjson0::SettingsWriter SW;
#endif

SNI* SettingsAPI::readConfigurationFile(std::string configurationFileContent) {
    SNI* n = NULL;
    SRI* sni = NULL;
#if defined(USE_LIBRARY_LIBJSON)
    sni = reinterpret_cast<SRI*>(new SR());
    n = reinterpret_cast<SNI*>(sni->parse(configurationFileContent));
#else
#   error No underlying library specified. Read documentation for further info.
#endif
    delete sni;
    return n;
}

std::string SettingsAPI::writeConfigurationFile(SNI* node) {
#if defined(USE_LIBRARY_LIBJSON)
    SWI* swi = NULL;
    swi = reinterpret_cast<SWI*>(new SW());
    std::string s = swi->write(node);
    delete swi;
    return s;
#else
#   error No underlying library specified. Read documentation for further info.
#endif
}

}  // namespaces

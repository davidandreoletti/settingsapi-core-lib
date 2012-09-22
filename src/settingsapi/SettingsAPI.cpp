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

#define USE_LIBRARY_LIBJSON 1

#if defined(USE_LIBRARY_LIBJSON)
#   include "./settingsapi/impl/json/libjson0/SettingsReader.h"
#   include "./settingsapi/impl/json/libjson0/SettingsWriter.h"
#endif

namespace settingsapi {

SettingNodeInterface* SettingsAPI::readConfigurationFile(std::string configurationFileContent) {  // NOLINT(whitespace/line_length)
    SettingNodeInterface* n = NULL;
    SettingsReaderInterface* sni = NULL;
#if defined(USE_LIBRARY_LIBJSON)
    namespace ijl = impl::json::libjson0;
    sni = reinterpret_cast<SettingsReaderInterface*>(new ijl::SettingsReader());
    n = reinterpret_cast<SettingNodeInterface*>(sni->parse(configurationFileContent));  // NOLINT(whitespace/line_length)
#else
#   error No underlying library specified. Read documentation for further info.
#endif
    delete sni;
    return n;
}

std::string SettingsAPI::writeConfigurationFile(SettingNodeInterface* node) {
#if defined(USE_LIBRARY_LIBJSON)
    namespace ijl = impl::json::libjson0;
    SettingsWriterInterface* swi = NULL;
    swi = reinterpret_cast<SettingsWriterInterface*>(new ijl::SettingsWriter());
    return swi->write(node);
#else
#   error No underlying library specified. Read documentation for further info.
#endif
}

SettingNodeInterface* SettingsAPI::createNode() {
    return reinterpret_cast<SettingNodeInterface*> (new SettingNode());
}

}  // namespaces

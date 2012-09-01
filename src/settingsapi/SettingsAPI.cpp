//
//  SettingsAPI.cpp
//  libsettingsapi
//
//  Created by Andreoletti David on 7/24/12. 
//  Copyright 2012 IO Stark. All rights reserved.
//

#include <stack>

#include "./targetconditionals/TargetConditionals.h"
#include "./settingsapi/SettingsAPI.h"
#include "./settingsapi/SettingsReaderInterface.h"
#include "./settingsapi/impl/json/libjson0/SettingsReader.h"
#include "./settingsapi/SettingNodeInterface.h"

namespace settingsapi {

SettingNodeInterface* SettingsAPI::readConfigurationFile(std::string configurationFileContent)
{
    SettingNodeInterface* n = NULL;
    SettingsReaderInterface* sni = NULL;
#if defined(TC_PLATFORMS_PLATFORM_APPLE_IOS)
    namespace ijl = impl::json::libjson0;
    sni = (SettingsReaderInterface*) new ijl::SettingsReader();
    n = (SettingNodeInterface*) sni->parse(configurationFileContent);
#else
#   error Platform NOT supported
#endif
    delete sni;
    return n;
}

}  // namespaces

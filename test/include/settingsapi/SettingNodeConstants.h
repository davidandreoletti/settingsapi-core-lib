//
//  SettingNodeConstants.cpp
//  libsettingapi
//
//  Created by Andreoletti David on 3/31/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#ifndef TEST_INCLUDE_SETTINGSAPI_SETTINGNODECONSTANTS_H_
#define TEST_INCLUDE_SETTINGSAPI_SETTINGNODECONSTANTS_H_

#include <string>
#include "settingsapi/SettingNodeInterface.h"

namespace settingsapi {
namespace test {

class SettingNodeConstants {
 public:
// Predefiend JSON Nodes Types
static const settingsapi::SettingNodeInterface::Type kMyNode0Type;
static const std::string kMyNode0Key;
static const std::string kMyNode0Value;
static const settingsapi::SettingNodeInterface::Type kMyNode1Type;
static const std::string kMyNode1Key;
static const settingsapi::SettingNodeInterface::Type kMyNode2Type;
static const std::string kMyNode2Key;

static settingsapi::SettingNodeInterface* createNewValueNode();
static settingsapi::SettingNodeInterface* createNewEmptyArrayNode();
static settingsapi::SettingNodeInterface* createNewEmptyObjectNode();
static settingsapi::SettingNodeInterface* createNewNotEmptyArrayNode();
static settingsapi::SettingNodeInterface* createNewNotEmptyObjectNode();
};
}}

#endif  // TEST_INCLUDE_SETTINGSAPI_SETTINGNODECONSTANTS_H_

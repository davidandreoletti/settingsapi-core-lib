//
//  SettingNodeConstants.cpp
//  libsettingapi
//
//  Created by Andreoletti David on 3/31/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#ifndef TEST_INCLUDE_SETTINGSAPI_NODES_SETTINGNODECONSTANTS_H_
#define TEST_INCLUDE_SETTINGSAPI_NODES_SETTINGNODECONSTANTS_H_

#include <string>
#include "settingsapi/nodes/SettingNodeInterface.h"

namespace settingsapi {
namespace nodes {
namespace test {

class SettingNodeConstants {
 public:
// Predefiend JSON Nodes Types
static const settingsapi::nodes::SettingNodeInterface::Type kMyNode0Type;
static const std::string kMyNode0Key;
static const std::string kMyNode0Value;
static const settingsapi::nodes::SettingNodeInterface::Type kMyNode1Type;
static const std::string kMyNode1Key;
static const settingsapi::nodes::SettingNodeInterface::Type kMyNode2Type;
static const std::string kMyNode2Key;

static settingsapi::nodes::SettingNodeInterface* createNewValueNode();
static settingsapi::nodes::SettingNodeInterface* createNewEmptyArrayNode();
static settingsapi::nodes::SettingNodeInterface* createNewEmptyObjectNode();
static settingsapi::nodes::SettingNodeInterface* createNewNotEmptyArrayNode();
static settingsapi::nodes::SettingNodeInterface* createNewNotEmptyObjectNode();
};
}}}  // namespaces

#endif  // TEST_INCLUDE_SETTINGSAPI_NODES_SETTINGNODECONSTANTS_H_

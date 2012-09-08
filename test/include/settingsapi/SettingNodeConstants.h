#ifndef INCLUDE_SETTINGSAPI_SETTINGNODECONSTANTS_H_
#define INCLUDE_SETTINGSAPI_SETTINGNODECONSTANTS_H_

#include "./settingsapi/SettingNodeInterface.h"

namespace settingsapi {
namespace test {

class SettingNodeConstants
{
 public:
// Predefiend JSON Nodes Types
static const settingsapi::SettingNodeInterface::SettingNodeType kMyNode0Type;
static const std::string kMyNode0Key;
static const std::string kMyNode0Value;
static const settingsapi::SettingNodeInterface::SettingNodeType kMyNode1Type;
static const std::string kMyNode1Key;
static const settingsapi::SettingNodeInterface::SettingNodeType kMyNode2Type;
static const std::string kMyNode2Key;

static settingsapi::SettingNodeInterface* createNewValueNode();
static settingsapi::SettingNodeInterface* createNewEmptyArrayNode();
static settingsapi::SettingNodeInterface* createNewEmptyObjectNode();
static settingsapi::SettingNodeInterface* createNewNotEmptyArrayNode();
static settingsapi::SettingNodeInterface* createNewNotEmptyObjectNode();
};
    
}}

#endif //  INCLUDE_SETTINGSAPI_SETTINGNODECONSTANTS_H_
//
//  SettingNodeConstants.cpp
//  libsettingapi
//
//  Created by Andreoletti David on 3/31/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#include "./settingsapi/SettingNodeConstants.h"
#include "./settingsapi/SettingNode.h"

namespace settingsapi {
namespace test {
    
const settingsapi::SettingNodeInterface::Type SettingNodeConstants::kMyNode0Type = settingsapi::SettingNodeInterface::TYPE_VALUE;
const std::string SettingNodeConstants::kMyNode0Key = "david";
const std::string SettingNodeConstants::kMyNode0Value = "ling";
const settingsapi::SettingNodeInterface::Type SettingNodeConstants::kMyNode1Type = settingsapi::SettingNodeInterface::TYPE_ARRAY;
const std::string SettingNodeConstants::kMyNode1Key = "tiny";
const settingsapi::SettingNodeInterface::Type SettingNodeConstants::kMyNode2Type = settingsapi::SettingNodeInterface::TYPE_OBJECT;
const std::string SettingNodeConstants::kMyNode2Key = "lola";
    
settingsapi::SettingNodeInterface* SettingNodeConstants::createNewValueNode()
{
    namespace api = settingsapi;
    api::SettingNodeInterface* n = (api::SettingNodeInterface*) new api::SettingNode();
    n->setType(SettingNodeConstants::kMyNode0Type);
    n->setKey(SettingNodeConstants::kMyNode0Key);
    n->setValue(SettingNodeConstants::kMyNode0Value);
    return n;
}

settingsapi::SettingNodeInterface* SettingNodeConstants::createNewEmptyArrayNode()
{
    namespace api = settingsapi;
    api::SettingNodeInterface* n = (api::SettingNodeInterface*) new api::SettingNode();
    n->setType(SettingNodeConstants::kMyNode1Type);
    n->setKey(SettingNodeConstants::kMyNode1Key);
    return n;
}

settingsapi::SettingNodeInterface* SettingNodeConstants::createNewEmptyObjectNode()
{
    namespace api = settingsapi;
    api::SettingNodeInterface* n = (api::SettingNodeInterface*) new api::SettingNode();
    n->setType(SettingNodeConstants::kMyNode2Type);
    n->setKey(SettingNodeConstants::kMyNode2Key);
    return n;
}

settingsapi::SettingNodeInterface* SettingNodeConstants::createNewNotEmptyArrayNode()
{
    namespace api = settingsapi;
    api::SettingNodeInterface* n = createNewEmptyArrayNode();
    n->addChildNode(createNewValueNode());
    
    api::SettingNodeInterface* n1 = createNewEmptyArrayNode();
    api::SettingNodeInterface* n1_n0 = createNewValueNode();
    n1->addChildNode(n1_n0);
    n->addChildNode(n1);

    api::SettingNodeInterface* n2 = createNewEmptyObjectNode();
    api::SettingNodeInterface* n2_n0 = createNewValueNode();
    n2->addChildNode(n2_n0);
    n->addChildNode(n2);
    
    return n;
}

settingsapi::SettingNodeInterface* SettingNodeConstants::createNewNotEmptyObjectNode()
{
    namespace api = settingsapi;
    api::SettingNodeInterface* n = createNewEmptyObjectNode();
    n->addChildNode(createNewValueNode());
    
    n->addChildNode(createNewNotEmptyArrayNode());
    
    api::SettingNodeInterface* n2 = createNewEmptyObjectNode();
    api::SettingNodeInterface* n2_n0 = createNewValueNode();
    n2->addChildNode(n2_n0);
    n->addChildNode(n2);
    
    return n;
}

}}
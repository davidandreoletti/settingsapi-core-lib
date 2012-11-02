//
//  SettingNodeConstants.cpp
//  libsettingapi
//
//  Created by Andreoletti David on 3/31/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#include <string>
#include "settingsapi/nodes/SettingNodeConstants.h"
#include "settingsapi/nodes/SettingNode.h"

namespace settingsapi {
namespace nodes {
namespace test {

typedef  settingsapi::nodes::SettingNodeInterface SNI;
typedef  settingsapi::nodes::SettingNode SN;

const SNI::Type SettingNodeConstants::kMyNode0Type = SNI::TYPE_VALUE;
const std::string SettingNodeConstants::kMyNode0Key = "david";
const std::string SettingNodeConstants::kMyNode0Value = "ling";
const SNI::Type SettingNodeConstants::kMyNode1Type = SNI::TYPE_ARRAY;
const std::string SettingNodeConstants::kMyNode1Key = "tiny";
const SNI::Type SettingNodeConstants::kMyNode2Type = SNI::TYPE_OBJECT;
const std::string SettingNodeConstants::kMyNode2Key = "lola";

SNI* SettingNodeConstants::createNewValueNode() {
    SNI* n = reinterpret_cast<SNI*> (new SN());
    n->setType(SettingNodeConstants::kMyNode0Type);
    n->setKey(SettingNodeConstants::kMyNode0Key);
    n->setValue(SettingNodeConstants::kMyNode0Value);
    return n;
}

SNI* SettingNodeConstants::createNewEmptyArrayNode() {
    SNI* n = reinterpret_cast<SNI*> (new SN());
    n->setType(SettingNodeConstants::kMyNode1Type);
    n->setKey(SettingNodeConstants::kMyNode1Key);
    return n;
}

SNI* SettingNodeConstants::createNewEmptyObjectNode() {
    SNI* n = reinterpret_cast<SNI*> (new SN());  // NOLINT(whitespace/line_length)
    n->setType(SettingNodeConstants::kMyNode2Type);
    n->setKey(SettingNodeConstants::kMyNode2Key);
    return n;
}

SNI* SettingNodeConstants::createNewNotEmptyArrayNode() {
    namespace api = settingsapi;
    SNI* n = createNewEmptyArrayNode();
    n->addChildNode(createNewValueNode());

    SNI* n1 = createNewEmptyArrayNode();
    SNI* n1_n0 = createNewValueNode();
    n1->addChildNode(n1_n0);
    n->addChildNode(n1);

    SNI* n2 = createNewEmptyObjectNode();
    SNI* n2_n0 = createNewValueNode();
    n2->addChildNode(n2_n0);
    n->addChildNode(n2);

    return n;
}

SNI* SettingNodeConstants::createNewNotEmptyObjectNode() {
    SNI* n = createNewEmptyObjectNode();
    n->addChildNode(createNewValueNode());

    n->addChildNode(createNewNotEmptyArrayNode());

    SNI* n2 = createNewEmptyObjectNode();
    SNI* n2_n0 = createNewValueNode();
    n2->addChildNode(n2_n0);
    n->addChildNode(n2);

    return n;
}
}}}

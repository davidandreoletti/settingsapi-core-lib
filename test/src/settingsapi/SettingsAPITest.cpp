//
//  SettingsAPITest.cpp
//  libsettingapi
//
//  Created by Andreoletti David on 3/31/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#include <boost/test/unit_test.hpp>
#include <string>
#include <vector>
#include "./settingsapi/SettingsAPI.h"
#include "./settingsapi/SettingNodeInterface.h"

namespace settingsapi {
namespace test {

// JSON Content
const int kRootNodeChildren = 3;
const int kMyArrayLength = 3;
const int kMyAbjectLgthength = 2;
const settingsapi::SettingNodeInterface::SettingNodeType kMyNode0Type = settingsapi::SettingNodeInterface::SettingNodeType::VALUE;
const std::string kMyNode0Key = "david";
const std::string kMyNode0Value = "ling";
const settingsapi::SettingNodeInterface::SettingNodeType kMyNode1Type = settingsapi::SettingNodeInterface::SettingNodeType::ARRAY;
const std::string kMyNode1Key = "tiny";
const settingsapi::SettingNodeInterface::SettingNodeType kMyNode1_Node0Type = settingsapi::SettingNodeInterface::SettingNodeType::VALUE;
const std::string kMyNode1_Node0Value = "sara";
const settingsapi::SettingNodeInterface::SettingNodeType kMyNode1_Node1Type = settingsapi::SettingNodeInterface::SettingNodeType::VALUE;
const std::string kMyNode1_Node1Value = "nina";
const settingsapi::SettingNodeInterface::SettingNodeType kMyNode1_Node2Type = settingsapi::SettingNodeInterface::SettingNodeType::VALUE;
const std::string kMyNode1_Node2Value = "123456";
const int kMyNode1_Node2ValueAsInt32 = 123456;
const settingsapi::SettingNodeInterface::SettingNodeType kMyNode2Type = settingsapi::SettingNodeInterface::SettingNodeType::OBJECT;
const std::string kMyNode2Key = "lola";
const settingsapi::SettingNodeInterface::SettingNodeType kMyNode2_Node0Type = settingsapi::SettingNodeInterface::SettingNodeType::VALUE;
const std::string kMyNode2_Node0Key = "dorine";
const std::string kMyNode2_Node0Value = "papa";
const settingsapi::SettingNodeInterface::SettingNodeType kMyNode2_Node1Type = settingsapi::SettingNodeInterface::SettingNodeType::VALUE;
const std::string kMyNode2_Node1Key = "maman";
const std::string kMyNode2_Node1Value = "yu-chien";
const std::string kJSONContent = "{"
"\""+kMyNode0Key+"\": \""+kMyNode0Value+"\","
"\""+kMyNode1Key+"\" : [\""+kMyNode1_Node0Value+"\", \""+kMyNode1_Node1Value+"\", \""+kMyNode1_Node2Value+"\"],"
"\""+kMyNode2Key+"\" : {\""+kMyNode2_Node0Key+"\": \""+kMyNode2_Node0Value+"\", \""+kMyNode2_Node1Key+"\": \""+kMyNode2_Node1Value+"\"}"
"}";

struct SettingsAPIFixture {
    settingsapi::SettingsAPI* api;
    SettingsAPIFixture() {
        api = new settingsapi::SettingsAPI();
    }
    ~SettingsAPIFixture() {
        delete api;
    }
};

BOOST_FIXTURE_TEST_SUITE(SettingsAPITestSuite, SettingsAPIFixture)

BOOST_AUTO_TEST_CASE(readConfigurationFile) {
	SettingNodeInterface* rootNode = api->readConfigurationFile(test::kJSONContent);
    std::vector<SettingNodeInterface*> rootNodeChildren = rootNode->getChildren();
    BOOST_REQUIRE_EQUAL(rootNodeChildren.size(), kRootNodeChildren);

    SettingNodeInterface* myNode0 = rootNodeChildren[0];
    BOOST_REQUIRE_EQUAL(myNode0->getType(), kMyNode0Type);
    BOOST_REQUIRE_EQUAL(myNode0->getKey(), kMyNode0Key);
    BOOST_REQUIRE_EQUAL(myNode0->readString(), kMyNode0Value);

    SettingNodeInterface* myNode1 = rootNodeChildren[1];
    BOOST_REQUIRE_EQUAL(myNode1->getType(), kMyNode1Type);
    std::vector<SettingNodeInterface*> myNode1Children = myNode1->getChildren();
    
    SettingNodeInterface* myNode1_Node0 = myNode1Children[0];
    BOOST_REQUIRE_EQUAL(myNode1_Node0->getType(), kMyNode1_Node0Type);
    BOOST_REQUIRE_EQUAL(myNode1_Node0->readString(), kMyNode1_Node0Value);

    SettingNodeInterface* myNode1_Node1 = myNode1Children[1];
    BOOST_REQUIRE_EQUAL(myNode1_Node1->getType(), kMyNode1_Node1Type);
    BOOST_REQUIRE_EQUAL(myNode1_Node1->readString(), kMyNode1_Node1Value);
    
    SettingNodeInterface* myNode1_Node2 = myNode1Children[2];
    BOOST_REQUIRE_EQUAL(myNode1_Node2->getType(), kMyNode1_Node2Type);
    BOOST_REQUIRE_EQUAL(myNode1_Node2->readString(), kMyNode1_Node2Value);
    settingsapi::SettingNodeInterface::stringToInt32_Status status;
    BOOST_REQUIRE_EQUAL(myNode1_Node2->readInt32(status), kMyNode1_Node2ValueAsInt32);
    BOOST_REQUIRE_EQUAL(status, settingsapi::SettingNodeInterface::stringToInt32_Status::SUCCESS);
    
    SettingNodeInterface* myNode2 = rootNodeChildren[2];
    BOOST_REQUIRE_EQUAL(myNode2->getType(), kMyNode2Type);
    std::vector<SettingNodeInterface*> myNode2Children = myNode2->getChildren();
    
    SettingNodeInterface* myNode2_Node0 = myNode2Children[0];
    BOOST_REQUIRE_EQUAL(myNode2_Node0->getType(), kMyNode2_Node0Type);
    BOOST_REQUIRE_EQUAL(myNode2_Node0->getKey(), kMyNode2_Node0Key);
    BOOST_REQUIRE_EQUAL(myNode2_Node0->readString(), kMyNode2_Node0Value);
    
    SettingNodeInterface* myNode2_Node1 = myNode2Children[1];
    BOOST_REQUIRE_EQUAL(myNode2_Node1->getType(), kMyNode2_Node1Type);
    BOOST_REQUIRE_EQUAL(myNode2_Node1->getKey(), kMyNode2_Node1Key);
    BOOST_REQUIRE_EQUAL(myNode2_Node1->readString(), kMyNode2_Node1Value);
}

BOOST_AUTO_TEST_SUITE_END()

}}  // namespaces

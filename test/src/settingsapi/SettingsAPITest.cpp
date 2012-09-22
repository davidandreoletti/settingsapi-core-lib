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
#include "./settingsapi/SettingNodeConstants.h"

namespace settingsapi {
namespace test {

const int kRootNodeChildren = 3;
const int kMyArrayLength = 3;
const int kMyObjectLgthength = 2;

struct SettingsAPIFixture {
    settingsapi::SettingsAPI* api;
    std::string kJSONContent;
    SettingsAPIFixture() {
        api = new settingsapi::SettingsAPI();
        kJSONContent =
        "{"
        "   \""+SettingNodeConstants::kMyNode0Key+"\": \""+SettingNodeConstants::kMyNode0Value+"\","  // NOLINT(whitespace/line_length)
        "   \""+SettingNodeConstants::kMyNode1Key+"\" : "
                "["
                    "\""+SettingNodeConstants::kMyNode0Value+"\","
                    "["
                        "{"
                        "\""+SettingNodeConstants::kMyNode0Key+"\" : \""+SettingNodeConstants::kMyNode0Value+"\""  // NOLINT(whitespace/line_length)
                        "}"
                    "],"
                    "{\""+SettingNodeConstants::kMyNode0Key+"\": \""+SettingNodeConstants::kMyNode0Value+"\"}"  // NOLINT(whitespace/line_length)
                "],"
            "\""+SettingNodeConstants::kMyNode2Key+"\" : "
                "{"
                    "\""+SettingNodeConstants::kMyNode0Key+"\" : \""+SettingNodeConstants::kMyNode0Value+"\","  // NOLINT(whitespace/line_length)
                    "\""+SettingNodeConstants::kMyNode0Key+"\" : \""+SettingNodeConstants::kMyNode0Value+"\""  // NOLINT(whitespace/line_length)
                "}"
        "}";
//        printf("JSON = %s", kJSONContent.c_str());
    }
    ~SettingsAPIFixture() {
        delete api;
    }
};

BOOST_FIXTURE_TEST_SUITE(SettingsAPITestSuite, SettingsAPIFixture)

BOOST_AUTO_TEST_CASE(readConfigurationFile) {
    SettingNodeInterface* rootNode = api->readConfigurationFile(kJSONContent);
    std::vector<SettingNodeInterface*> rootNodeChildren = rootNode->getChildren();  // NOLINT(whitespace/line_length)
    BOOST_REQUIRE_EQUAL(rootNode->getType(), SettingNodeConstants::kMyNode2Type);  // NOLINT(whitespace/line_length)
    BOOST_REQUIRE_EQUAL(rootNodeChildren.size(), kRootNodeChildren);

    SettingNodeInterface* myNode0 = rootNodeChildren[0];
    BOOST_REQUIRE_EQUAL(myNode0->getType(), SettingNodeConstants::kMyNode0Type);
    BOOST_REQUIRE_EQUAL(myNode0->getKey(), SettingNodeConstants::kMyNode0Key);
    BOOST_REQUIRE_EQUAL(myNode0->readString(), SettingNodeConstants::kMyNode0Value);  // NOLINT(whitespace/line_length)

    SettingNodeInterface* myNode1 = rootNodeChildren[1];
    BOOST_REQUIRE_EQUAL(myNode1->getKey(), SettingNodeConstants::kMyNode1Key);
    BOOST_REQUIRE_EQUAL(myNode1->getType(), SettingNodeConstants::kMyNode1Type);
    std::vector<SettingNodeInterface*> myNode1Children = myNode1->getChildren();
    BOOST_REQUIRE_EQUAL(myNode1Children.size(), kMyArrayLength);

    SettingNodeInterface* myNode1_Node0 = myNode1Children[0];
    BOOST_REQUIRE_EQUAL(myNode1_Node0->getType(), SettingNodeConstants::kMyNode0Type);  // NOLINT(whitespace/line_length)
    BOOST_REQUIRE_EQUAL(myNode1_Node0->readString(), SettingNodeConstants::kMyNode0Value);  // NOLINT(whitespace/line_length)

    SettingNodeInterface* myNode1_Node1 = myNode1Children[1];
    BOOST_REQUIRE_EQUAL(myNode1_Node1->getType(), SettingNodeConstants::kMyNode1Type);  // NOLINT(whitespace/line_length)
    std::vector<SettingNodeInterface*> myNode1_Node1Children = myNode1_Node1->getChildren();  // NOLINT(whitespace/line_length)
    BOOST_REQUIRE_EQUAL(myNode1_Node1Children.size(), 1);
    SettingNodeInterface* myNode1_Node1_Node0 = myNode1_Node1Children[0];
    BOOST_REQUIRE_EQUAL(myNode1_Node1_Node0->getType(), SettingNodeConstants::kMyNode2Type);  // NOLINT(whitespace/line_length)

    SettingNodeInterface* myNode1_Node2 = myNode1Children[2];
    BOOST_REQUIRE_EQUAL(myNode1_Node2->getType(), SettingNodeConstants::kMyNode2Type);  // NOLINT(whitespace/line_length)
    std::vector<SettingNodeInterface*> myNode1_Node2Children = myNode1_Node2->getChildren();  // NOLINT(whitespace/line_length)
    BOOST_REQUIRE_EQUAL(myNode1_Node2Children.size(), 1);
    SettingNodeInterface* myNode1_Node2_Node0 = myNode1_Node2Children[0];
    BOOST_REQUIRE_EQUAL(myNode1_Node2_Node0->getType(), SettingNodeConstants::kMyNode0Type);  // NOLINT(whitespace/line_length)

    SettingNodeInterface* myNode2 = rootNodeChildren[2];
    BOOST_REQUIRE_EQUAL(myNode2->getType(), SettingNodeConstants::kMyNode2Type);
    std::vector<SettingNodeInterface*> myNode2Children = myNode2->getChildren();
    BOOST_REQUIRE_EQUAL(myNode2Children.size(), kMyObjectLgthength);

    for (int i = 0; i < myNode2Children.size(); i++) {
        SettingNodeInterface* myNode2_Node0 = myNode2Children[i];
        BOOST_REQUIRE_EQUAL(myNode2_Node0->getType(), SettingNodeConstants::kMyNode0Type);  // NOLINT(whitespace/line_length)
        BOOST_REQUIRE_EQUAL(myNode2_Node0->getKey(), SettingNodeConstants::kMyNode0Key);  // NOLINT(whitespace/line_length)
        BOOST_REQUIRE_EQUAL(myNode2_Node0->readString(), SettingNodeConstants::kMyNode0Value);  // NOLINT(whitespace/line_length)
    }
}

BOOST_AUTO_TEST_CASE(createNode) {
    SettingNodeInterface* node = api->createNode();
    BOOST_REQUIRE(node != NULL);
//    delete node;
}

BOOST_AUTO_TEST_CASE(writeConfigurationFile) {
    SettingNodeInterface* rootNodeA = api->readConfigurationFile(kJSONContent);
    BOOST_REQUIRE(rootNodeA != NULL);
    std::string fileContentA = api->writeConfigurationFile(rootNodeA);
    SettingNodeInterface* rootNodeB = api->readConfigurationFile(fileContentA);
    BOOST_REQUIRE(rootNodeA->equalsTreeNode(*rootNodeB));

    delete rootNodeA;
    delete rootNodeB;
}

BOOST_AUTO_TEST_SUITE_END()

}}  // namespaces

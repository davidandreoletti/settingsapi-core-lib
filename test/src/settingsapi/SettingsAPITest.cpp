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
#include "settingsapi/SettingsAPI.h"
#include "settingsapi/nodes/SettingNodeInterface.h"
#include "settingsapi/nodes/SettingNode.h"
#include "settingsapi/nodes/SettingNodeConstants.h"

namespace settingsapi {
namespace test {

typedef nodes::test::SettingNodeConstants SNC;
typedef settingsapi::nodes::SettingNodeInterface SNI;
typedef settingsapi::nodes::SettingNode SN;

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
        "   \""+SNC::kMyNode0Key+"\": \""+SNC
        ::kMyNode0Value+"\","  // NOLINT(whitespace/line_length)
        "   \""+SNC::kMyNode1Key+"\" : "
                "["
                    "\""+SNC::kMyNode0Value+"\","
                    "["
                        "{"
                        "\""+SNC::kMyNode0Key+"\" : \""+SNC::kMyNode0Value+"\""
                        "}"
                    "],"
                    "{\""+SNC::kMyNode0Key+"\": \""+SNC::kMyNode0Value+"\"}"
                "],"
            "\""+SNC::kMyNode2Key+"\" : "
                "{"
                    "\""+SNC::kMyNode0Key+"\" : \""+SNC::kMyNode0Value+"\","
                    "\""+SNC::kMyNode0Key+"\" : \""+SNC::kMyNode0Value+"\""
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
    SNI* rootNode = api->readConfigurationFile(kJSONContent);
    std::vector<SNI*> rootNodeChildren = rootNode->getChildren();
    BOOST_REQUIRE_EQUAL(rootNode->getType(), SNC::kMyNode2Type);
    BOOST_REQUIRE_EQUAL(rootNodeChildren.size(), kRootNodeChildren);

    SNI* myNode0 = rootNodeChildren[0];
    BOOST_REQUIRE_EQUAL(myNode0->getType(), SNC::kMyNode0Type);
    BOOST_REQUIRE_EQUAL(myNode0->getKey(), SNC::kMyNode0Key);
    BOOST_REQUIRE_EQUAL(myNode0->readString(), SNC::kMyNode0Value);

    SNI* myNode1 = rootNodeChildren[1];
    BOOST_REQUIRE_EQUAL(myNode1->getKey(), SNC::kMyNode1Key);
    BOOST_REQUIRE_EQUAL(myNode1->getType(), SNC::kMyNode1Type);
    std::vector<SNI*> myNode1Children = myNode1->getChildren();
    BOOST_REQUIRE_EQUAL(myNode1Children.size(), kMyArrayLength);

    SNI* myNode1_Node0 = myNode1Children[0];
    BOOST_REQUIRE_EQUAL(myNode1_Node0->getType(), SNC::kMyNode0Type);
    BOOST_REQUIRE_EQUAL(myNode1_Node0->readString(), SNC::kMyNode0Value);

    SNI* myNode1_Node1 = myNode1Children[1];
    BOOST_REQUIRE_EQUAL(myNode1_Node1->getType(), SNC::kMyNode1Type);
    std::vector<SNI*> myNode1_Node1Children = myNode1_Node1->getChildren();
    BOOST_REQUIRE_EQUAL(myNode1_Node1Children.size(), 1);
    SNI* myNode1_Node1_Node0 = myNode1_Node1Children[0];
    BOOST_REQUIRE_EQUAL(myNode1_Node1_Node0->getType(), SNC::kMyNode2Type);

    SNI* myNode1_Node2 = myNode1Children[2];
    BOOST_REQUIRE_EQUAL(myNode1_Node2->getType(), SNC::kMyNode2Type);
    std::vector<SNI*> myNode1_Node2Children = myNode1_Node2->getChildren();
    BOOST_REQUIRE_EQUAL(myNode1_Node2Children.size(), 1);
    SNI* myNode1_Node2_Node0 = myNode1_Node2Children[0];
    BOOST_REQUIRE_EQUAL(myNode1_Node2_Node0->getType(), SNC::kMyNode0Type);

    SNI* myNode2 = rootNodeChildren[2];
    BOOST_REQUIRE_EQUAL(myNode2->getType(), SNC::kMyNode2Type);
    std::vector<SNI*> myNode2Children = myNode2->getChildren();
    BOOST_REQUIRE_EQUAL(myNode2Children.size(), kMyObjectLgthength);

    for (int i = 0; i < myNode2Children.size(); i++) {
        SNI* myNode2_Node0 = myNode2Children[i];
        BOOST_REQUIRE_EQUAL(myNode2_Node0->getType(), SNC::kMyNode0Type);
        BOOST_REQUIRE_EQUAL(myNode2_Node0->getKey(), SNC::kMyNode0Key);
        BOOST_REQUIRE_EQUAL(myNode2_Node0->readString(), SNC::kMyNode0Value);
    }
}

BOOST_AUTO_TEST_CASE(createNode) {
    SNI* node = reinterpret_cast<SNI*> (new SN());
    BOOST_REQUIRE(node != NULL);
    delete node;
}

BOOST_AUTO_TEST_CASE(writeConfigurationFile) {
    SNI* rootNodeA = api->readConfigurationFile(kJSONContent);
    BOOST_REQUIRE(rootNodeA != NULL);
    std::string fileContentA = api->writeConfigurationFile(rootNodeA);
    SNI* rootNodeB = api->readConfigurationFile(fileContentA);
    BOOST_REQUIRE(rootNodeA->equalsTreeNode(*rootNodeB));

    delete rootNodeA;
    delete rootNodeB;
}

BOOST_AUTO_TEST_SUITE_END()

}}  // namespaces

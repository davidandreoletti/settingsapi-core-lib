//
//  SettingNodeTest.cpp
//  libsettingapi
//
//  Created by Andreoletti David on 3/31/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#include <boost/test/unit_test.hpp>
#include <string>
#include <vector>
#include "./settingsapi/SettingNodeInterface.h"
#include "./settingsapi/SettingNode.h"
#include "./settingsapi/SettingNodeConstants.h"

namespace settingsapi {
namespace test {
    
struct SettingNodeFixture {
    settingsapi::SettingNodeInterface* node;
    SettingNodeFixture() {
        node = (SettingNodeInterface*) new settingsapi::SettingNode();
    }
    ~SettingNodeFixture() {
        delete node;
    }
};

BOOST_FIXTURE_TEST_SUITE(SettingNodeTestSuite, SettingNodeFixture)

BOOST_AUTO_TEST_CASE(setType) {
    node->setType(SettingNodeConstants::kMyNode0Type);
    BOOST_REQUIRE_EQUAL(node->getType(),SettingNodeConstants::kMyNode0Type);
}

BOOST_AUTO_TEST_CASE(setKey) {
    node->setKey(SettingNodeConstants::kMyNode0Key);
    BOOST_REQUIRE_EQUAL(node->getKey(),SettingNodeConstants::kMyNode0Key);
}
    
BOOST_AUTO_TEST_CASE(setValue) {
    node->setValue(SettingNodeConstants::kMyNode0Value);
    BOOST_REQUIRE_NE(node->readString(),SettingNodeConstants::kMyNode0Value);

    node->setType(SettingNodeConstants::kMyNode0Type);
    node->setValue(SettingNodeConstants::kMyNode0Value);
    BOOST_REQUIRE_EQUAL(node->readString(),SettingNodeConstants::kMyNode0Value);
}
    
BOOST_AUTO_TEST_CASE(equalsNode) {
    SettingNodeInterface* nodeA = (SettingNodeInterface*) new SettingNode();
    nodeA->setType(SettingNodeInterface::SettingNodeType::OBJECT);
    nodeA->setKey(SettingNodeConstants::kMyNode0Key);
    nodeA->setValue(SettingNodeConstants::kMyNode0Value);
    
    SettingNodeInterface* nodeB = (SettingNodeInterface*) new SettingNode();
    nodeB->setType(SettingNodeInterface::SettingNodeType::OBJECT);
    nodeB->setKey(SettingNodeConstants::kMyNode0Key);
    nodeB->setValue(SettingNodeConstants::kMyNode0Value);
    
    BOOST_REQUIRE(nodeA->equalsNode(*nodeB));
    
    SettingNodeInterface* nodeC = (SettingNodeInterface*) new SettingNode();
    BOOST_REQUIRE(!(nodeA->equalsNode(*nodeC)));
    nodeC->setType(SettingNodeConstants::kMyNode0Type);
    BOOST_REQUIRE(!(nodeA->equalsNode(*nodeC)));
    nodeC->setKey(SettingNodeConstants::kMyNode0Key);
    BOOST_REQUIRE(!(nodeA->equalsNode(*nodeC)));
    nodeC->setValue("DIFFERENT");
    BOOST_REQUIRE(!(nodeA->equalsNode(*nodeC)));
    
    delete nodeA;
    delete nodeB;
    delete nodeC;
}
    
BOOST_AUTO_TEST_CASE(equalsTreeNode) {
    SettingNodeInterface* rootNodeA = SettingNodeConstants::createNewNotEmptyObjectNode();
    SettingNodeInterface* rootNodeB = SettingNodeConstants::createNewNotEmptyObjectNode();
    
    BOOST_REQUIRE(rootNodeA->equalsTreeNode(*rootNodeB));
    
    SettingNodeInterface* nodeC = (SettingNodeInterface*) new SettingNode();
    rootNodeB->addChildNode(nodeC);

    BOOST_REQUIRE(!(rootNodeA->equalsTreeNode(*rootNodeB)));
        
    delete rootNodeA;
    delete rootNodeB;
}

    
BOOST_AUTO_TEST_SUITE_END()

}}  // namespaces

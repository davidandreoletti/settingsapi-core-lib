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
#include "settingsapi/nodes/SettingNodeInterface.h"
#include "settingsapi/nodes/SettingNode.h"
#include "settingsapi/nodes/SettingNodeConstants.h"

namespace settingsapi {
namespace nodes {
namespace test {

struct SettingNodeFixture {
    settingsapi::nodes::SettingNodeInterface* node;
    SettingNodeFixture() {
        node = reinterpret_cast<nodes::SettingNodeInterface*>(new settingsapi::nodes::SettingNode());  // NOLINT(whitespace/line_length)
    }
    ~SettingNodeFixture() {
        delete node;
    }
};

BOOST_FIXTURE_TEST_SUITE(SettingNodeTestSuite, SettingNodeFixture)

BOOST_AUTO_TEST_CASE(setType) {
    node->setType(SettingNodeConstants::kMyNode0Type);
    BOOST_REQUIRE_EQUAL(node->getType(), SettingNodeConstants::kMyNode0Type);
}

BOOST_AUTO_TEST_CASE(setKey) {
    node->setKey(SettingNodeConstants::kMyNode0Key);
    BOOST_REQUIRE_EQUAL(node->getKey(), SettingNodeConstants::kMyNode0Key);
}

BOOST_AUTO_TEST_CASE(readInt32) {
    node->setType(SettingNodeConstants::kMyNode0Type);
    node->setValue("2147483647");  // 2^31 - 1 = 2147483647
    settingsapi::nodes::SettingNodeInterface::StringToInt32ConversionStatus cs;
    int value = node->readInt32(cs);
    BOOST_REQUIRE_EQUAL(value, 2147483647);
    BOOST_REQUIRE_EQUAL(cs, settingsapi::nodes::SettingNodeInterface::STRINGTOINT32CONVERTIONSTATUS_SUCCESS);  // NOLINT(whitespace/line_length)

    node->setValue("2147483648");  // 2^31 = 2147483648
    value = node->readInt32(cs);
    BOOST_REQUIRE_NE(value, 2147483648);
    BOOST_REQUIRE_EQUAL(cs, settingsapi::nodes::SettingNodeInterface::STRINGTOINT32CONVERTIONSTATUS_OVERFLOW);  // NOLINT(whitespace/line_length)

    node->setValue("-2147483649");  // -2^31+1 = -2147483649
    value = node->readInt32(cs);
    BOOST_REQUIRE_NE(value, -2147483649);
    BOOST_REQUIRE_EQUAL(cs, settingsapi::nodes::SettingNodeInterface::STRINGTOINT32CONVERTIONSTATUS_UNDERFLOW);  // NOLINT(whitespace/line_length)

    node->setValue("");
    value = node->readInt32(cs);
    BOOST_REQUIRE_EQUAL(cs, settingsapi::nodes::SettingNodeInterface::STRINGTOINT32CONVERTIONSTATUS_INCONVERTIBLE);  // NOLINT(whitespace/line_length)
}


BOOST_AUTO_TEST_CASE(setValue) {
    node->setValue(SettingNodeConstants::kMyNode0Value);
    BOOST_REQUIRE_NE(node->readString(), SettingNodeConstants::kMyNode0Value);

    node->setType(SettingNodeConstants::kMyNode0Type);
    node->setValue(SettingNodeConstants::kMyNode0Value);
    BOOST_REQUIRE_EQUAL(node->readString(), SettingNodeConstants::kMyNode0Value);  // NOLINT(whitespace/line_length)
}

BOOST_AUTO_TEST_CASE(equalsNode) {
    nodes::SettingNodeInterface* nodeA = reinterpret_cast<nodes::SettingNodeInterface*>(new nodes::SettingNode());  // NOLINT(whitespace/line_length)
    nodeA->setType(nodes::SettingNodeInterface::TYPE_OBJECT);
    nodeA->setKey(SettingNodeConstants::kMyNode0Key);
    nodeA->setValue(SettingNodeConstants::kMyNode0Value);

    nodes::SettingNodeInterface* nodeB = reinterpret_cast<nodes::SettingNodeInterface*>(new nodes::SettingNode());  // NOLINT(whitespace/line_length)
    nodeB->setType(nodes::SettingNodeInterface::TYPE_OBJECT);
    nodeB->setKey(SettingNodeConstants::kMyNode0Key);
    nodeB->setValue(SettingNodeConstants::kMyNode0Value);

    BOOST_REQUIRE(nodeA->equalsNode(*nodeB));

    nodes::SettingNodeInterface* nodeC = reinterpret_cast<nodes::SettingNodeInterface*>(new nodes::SettingNode());  // NOLINT(whitespace/line_length)
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
    nodes::SettingNodeInterface* rootNodeA = SettingNodeConstants::createNewNotEmptyObjectNode();  // NOLINT(whitespace/line_length)
    nodes::SettingNodeInterface* rootNodeB = SettingNodeConstants::createNewNotEmptyObjectNode();  // NOLINT(whitespace/line_length)

    BOOST_REQUIRE(rootNodeA->equalsTreeNode(*rootNodeB));

    nodes::SettingNodeInterface* nodeC = reinterpret_cast<nodes::SettingNodeInterface*> (new nodes::SettingNode());  // NOLINT(whitespace/line_length)
    rootNodeB->addChildNode(nodeC);

    BOOST_REQUIRE(!(rootNodeA->equalsTreeNode(*rootNodeB)));

    delete rootNodeA;
    delete rootNodeB;
}

BOOST_AUTO_TEST_SUITE_END()

}}}  // namespaces

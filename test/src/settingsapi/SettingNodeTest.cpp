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
#include "settingsapi/SettingNodeInterface.h"
#include "settingsapi/SettingNode.h"
#include "settingsapi/SettingNodeConstants.h"

namespace settingsapi {
namespace test {

struct SettingNodeFixture {
    settingsapi::SettingNodeInterface* node;
    SettingNodeFixture() {
        node = reinterpret_cast<SettingNodeInterface*>(new settingsapi::SettingNode());  // NOLINT(whitespace/line_length)
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
    settingsapi::SettingNodeInterface::StringToInt32ConversionStatus cs;
    int value = node->readInt32(cs);
    BOOST_REQUIRE_EQUAL(value, 2147483647);
    BOOST_REQUIRE_EQUAL(cs, settingsapi::SettingNodeInterface::STRINGTOINT32CONVERTIONSTATUS_SUCCESS);  // NOLINT(whitespace/line_length)

    node->setValue("2147483648");  // 2^31 = 2147483648
    value = node->readInt32(cs);
    BOOST_REQUIRE_NE(value, 2147483648);
    BOOST_REQUIRE_EQUAL(cs, settingsapi::SettingNodeInterface::STRINGTOINT32CONVERTIONSTATUS_OVERFLOW);  // NOLINT(whitespace/line_length)

    node->setValue("-2147483649");  // -2^31+1 = -2147483649
    value = node->readInt32(cs);
    BOOST_REQUIRE_NE(value, -2147483649);
    BOOST_REQUIRE_EQUAL(cs, settingsapi::SettingNodeInterface::STRINGTOINT32CONVERTIONSTATUS_UNDERFLOW);  // NOLINT(whitespace/line_length)

    node->setValue("");
    value = node->readInt32(cs);
    BOOST_REQUIRE_EQUAL(cs, settingsapi::SettingNodeInterface::STRINGTOINT32CONVERTIONSTATUS_INCONVERTIBLE);  // NOLINT(whitespace/line_length)
}


BOOST_AUTO_TEST_CASE(setValue) {
    node->setValue(SettingNodeConstants::kMyNode0Value);
    BOOST_REQUIRE_NE(node->readString(), SettingNodeConstants::kMyNode0Value);

    node->setType(SettingNodeConstants::kMyNode0Type);
    node->setValue(SettingNodeConstants::kMyNode0Value);
    BOOST_REQUIRE_EQUAL(node->readString(), SettingNodeConstants::kMyNode0Value);  // NOLINT(whitespace/line_length)
}

BOOST_AUTO_TEST_CASE(equalsNode) {
    SettingNodeInterface* nodeA = reinterpret_cast<SettingNodeInterface*>(new SettingNode());  // NOLINT(whitespace/line_length)
    nodeA->setType(SettingNodeInterface::TYPE_OBJECT);
    nodeA->setKey(SettingNodeConstants::kMyNode0Key);
    nodeA->setValue(SettingNodeConstants::kMyNode0Value);

    SettingNodeInterface* nodeB = reinterpret_cast<SettingNodeInterface*>(new SettingNode());  // NOLINT(whitespace/line_length)
    nodeB->setType(SettingNodeInterface::TYPE_OBJECT);
    nodeB->setKey(SettingNodeConstants::kMyNode0Key);
    nodeB->setValue(SettingNodeConstants::kMyNode0Value);

    BOOST_REQUIRE(nodeA->equalsNode(*nodeB));

    SettingNodeInterface* nodeC = reinterpret_cast<SettingNodeInterface*>(new SettingNode());  // NOLINT(whitespace/line_length)
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
    SettingNodeInterface* rootNodeA = SettingNodeConstants::createNewNotEmptyObjectNode();  // NOLINT(whitespace/line_length)
    SettingNodeInterface* rootNodeB = SettingNodeConstants::createNewNotEmptyObjectNode();  // NOLINT(whitespace/line_length)

    BOOST_REQUIRE(rootNodeA->equalsTreeNode(*rootNodeB));

    SettingNodeInterface* nodeC = reinterpret_cast<SettingNodeInterface*> (new SettingNode());  // NOLINT(whitespace/line_length)
    rootNodeB->addChildNode(nodeC);

    BOOST_REQUIRE(!(rootNodeA->equalsTreeNode(*rootNodeB)));

    delete rootNodeA;
    delete rootNodeB;
}

BOOST_AUTO_TEST_SUITE_END()

}}  // namespaces

//
//  TestRunner.cpp
//  libsettingsapi
//
//  Created by Andreoletti David on 3/31/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#ifndef TEST_INCLUDE_TESTRUNNER_H_
#define TEST_INCLUDE_TESTRUNNER_H_

namespace test {
namespace settingsapi {

/*
 * Execute unit tests
 */
class TestRunner {
    /*
     * All tests success ran
     */
    static const int success;
    /*
     * Some tests failed
     */
    static const int failure;

 public:
    /*
     * Runs master test suite
     * \return TestRunner::success or TestRunner::failure.
     */
    int run();
};

}}  // namespaces

#endif  // TEST_INCLUDE_TESTRUNNER_H_

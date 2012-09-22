//
//  TestRunner.cpp
//  libpomodoro
//
//  Created by Andreoletti David on 3/31/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#include "./TestRunner.h"

//  Boost Exit codes
#include "./boost/cstdlib.hpp"
//  Boost Test Library
#define BOOST_TEST_MAIN
#include "./boost/test/unit_test.hpp"

#include "./targetconditionals/TargetConditionals.h"

namespace test {
namespace settingsapi {

const int TestRunner::success = 0;
const int TestRunner::failure = 1;

int TestRunner::run() {
    char *args[] = {const_cast<char *>(""), const_cast<char *>("--log_level=all"), const_cast<char *>("--auto_start_dbg=yes")};  // NOLINT(whitespace/line_length)
    int result = ::boost::unit_test::unit_test_main(&init_unit_test_suite, sizeof(args) / sizeof(char*), args);  // NOLINT(*) NOLINT(whitespace/line_length) NOLINT(runtime/sizeof)
    if (result == ::boost::exit_success) {
        return TestRunner::success;
    }
    return TestRunner::failure;
}

}}  // namespaces

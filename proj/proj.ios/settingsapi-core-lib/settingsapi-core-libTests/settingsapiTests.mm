//
//  settingsapi_core_libTests.m
//  settingsapi-core-libTests
//
//  Created by David Andreoletti on 8/24/12.
//  Copyright (c) 2012 IO Stark. All rights reserved.
//

#import "settingsapiTests.h"

#import "./TestRunner.h"

@implementation settingsapiTests

- (void)setUp
{
    [super setUp];
    
    // Set-up code here.
}

- (void)tearDown
{
    // Tear-down code here.
    
    [super tearDown];
}

- (void)testPomodoroMasterTestSuite
{
    ::test::settingsapi::TestRunner* testRunner = new ::test::settingsapi::TestRunner();
    int testSuiteResult = testRunner->run();
    STAssertEquals(0, testSuiteResult, @"Pomodoro Master Test Suite Failed.");

}

@end

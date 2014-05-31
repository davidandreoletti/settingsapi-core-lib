# Cross platform sources
FILE (GLOB cross_platform_test_souces_files0 ${CMAKE_CURRENT_SOURCE_DIR}/src/**.cpp)
FILE (GLOB cross_platform_test_souces_files1 ${CMAKE_CURRENT_SOURCE_DIR}/src/*/**.cpp)
SET (CROSS_PLATFORM_TEST_SOURCES ${cross_platform_test_souces_files0} ${cross_platform_test_souces_files1} PARENT_SCOPE)

# Cross platform headers
SET (cross_platform_test_headers_dir0 ${CMAKE_CURRENT_SOURCE_DIR}/include)
FILE (GLOB cross_platform_test_headers_files ${cross_platform_test_headers_dir0}/**.h)
SET (CROSS_PLATFORM_TEST_HEADERS ${cross_platform_test_headers_files} PARENT_SCOPE)
SET (CROSS_PLATFORM_TEST_HEADERS_DIR ${cross_platform_test_headers_dir0} PARENT_SCOPE)

# iOS platform sources
#SET (IOS_PLATFORM_TEST_OBJC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../proj/proj.ios/settingsapi-core-lib/settingsapi-core-libTests)
#FILE (GLOB ios_platform_test_souces_files0 ${IOS_PLATFORM_TEST_OBJC_DIR}/*.mm)
#SET (IOS_PLATFORM_TEST_SOURCES ${ios_platform_test_souces_files0} PARENT_SCOPE)

# iOS platform headers
#FILE (GLOB ios_platform_test_headers_files ${IOS_PLATFORM_TEST_OBJC_DIR}/*.h)
#SET (IOS_PLATFORM_TEST_OBJC_HEADERS_DIR ${ios_platform_test_headers_files} PARENT_SCOPE)
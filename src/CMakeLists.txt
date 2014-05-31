# Cross platform sources
FILE (GLOB cross_platform_souces_files ${CMAKE_CURRENT_SOURCE_DIR}/settingsapi/*.cpp)
SET (CROSS_PLATFORM_SOURCES ${cross_platform_souces_files} PARENT_SCOPE)

# iOS platform sources
FILE (GLOB ios_platform_souces_files ${CMAKE_CURRENT_SOURCE_DIR}/settingsapi/impl/json/libjson0/*.cpp)
SET (IOS_PLATFORM_SOURCES ${ios_platform_souces_files} PARENT_SCOPE)
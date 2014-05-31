# Cross platform headers
SET (CROSS_PLATFORM_HEADERS_DIR ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)
#file(GLOB cross_platform_headers_files ${CROSS_PLATFORM_HEADERS_DIR}/settingsapi/*.h)
#SET (CROSS_PLATFORM_HEADERS ${cross_platform_headers_files} PARENT_SCOPE)

# iOS platform headers
SET (IOS_PLATFORM_HEADERS_DIR ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)
#file(GLOB ios_platform_headers_files ${IOS_PLATFORM_HEADERS_DIR}/settingsapi/impl/json/libjson0/*.h)
#SET (IOS_PLATFORM_HEADERS ${ios_platform_headers_files} PARENT_SCOPE)
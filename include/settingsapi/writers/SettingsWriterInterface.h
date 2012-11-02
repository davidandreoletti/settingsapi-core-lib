//
//  SettingsWriterInterface.h
//  libsettingsapi
//
//  Created by Andreoletti David on 7/24/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#ifndef INCLUDE_SETTINGSAPI_WRITERS_SETTINGSWRITERINTERFACE_H_
#define INCLUDE_SETTINGSAPI_WRITERS_SETTINGSWRITERINTERFACE_H_

#include "settingsapi/nodes/SettingNodeInterface.h"

#include <string>  // NOLINT(build/include_order)

namespace settingsapi {
namespace writers {

/**
 *  Settings API parser interface
 */
class SettingsWriterInterface {
 public:
    typedef settingsapi::nodes::SettingNodeInterface SNI;

    /**
     *  Destructor
     */
    virtual ~SettingsWriterInterface() = 0;

    /**
     * Writes string representation of full tree node hierarchy settings's content as string
     * \param node Root node of the tree node hierarchy
     * \return String representation
     */
    virtual std::string write(SNI* node) = 0;
};

/**
 * Pure virtual destructor implementation is required.
 * See http://stackoverflow.com/questions/630950/pure-virtual-destructor-in-c
 */
inline SettingsWriterInterface::~SettingsWriterInterface() {}

}}  // namespaces

#endif  // INCLUDE_SETTINGSAPI_WRITERS_SETTINGSWRITERINTERFACE_H_

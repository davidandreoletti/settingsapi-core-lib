libsettingapi

ABOUT
================================================================================

libsettingapi is cross platform/storage independent API to read/write configuration files.

See CHANGELOG file for further details.

MOTIVATION:
================================================================================

I am writing C++ cross-platform libraries and I needed a cross platform API 
to to read/write configurations files

INSTALLATION:
================================================================================

    cd proj
    # To build for iOS
    make build-ios

DOCUMENTATION
================================================================================

The source code is fully documented.

The library is designed to work with 3rd party library to bring support:

- to read/write JSON formats.

Library's default
------------------

By default, the library stores settings in JSON format via library libjson 
(http://sourceforge.net/projects/libjson/).

JSON format storage is enabled with:

- preprocessor macro USE\_LIBRARY\_LIBJSON=1.
- linking against libjson library. 

NOTE: An iOS version of libjson can be found at
sourceforge-libjson (https://github.com/davidandreoletti/sourceforge-libjson.git)

SOURCE
================================================================================

Main source repository: 

https://github.com/davidandreoletti/settingsapi-core-lib.git

DEVELOPMENT STATUS
================================================================================

This implementation is in ALPHA version. I only implements features required 
for my own needs but feel free to extend it.

CHANGELOG
================================================================================

See CHANGELOG file

REQUIREMENTS
================================================================================

See CHANGELOG file

CONTRIBUTORS:
================================================================================

If you would like to contribute, feel free to drop me an email or contribute 
patches.

AUTHOR
================================================================================
- David Andreoletti http://davidandreoletti.com

THANKS TO
================================================================================
- Jonathan Wallace for producing libjson library which is used internaly
  to read/write JSON based configuration files.

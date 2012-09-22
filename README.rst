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

- Go to proj/proj.ios/settingsapi-core-lib/
- Open Xcode and build the library

DOCUMENTATION
================================================================================

The source code is fully documented.

The library is designed to work with 3rd party library to bring support for:
- read/write new formats (eg: XML).

Library's default
------------------

- JSON format via http://sourceforge.net/projects/libjson/ and macro USE\_LIBRARY\_LIBJSON is defined.

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
- Jonathan Wallace for producing such the libjson library which is used internaly
  to read/write JSON based configuration files.

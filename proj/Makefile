#
#  Makefile
#  Builds library for various platorms
#
#  For full documentation: make usage

#
THIS_MAKEFILE_DIR = $(dir $(CURDIR)/$(word $(words $(MAKEFILE_LIST)),$(MAKEFILE_LIST)))

INTERNAL_PREFIX_DIR_NAME=prefix
INTERNAL_PREFIX_DIR=$(THIS_MAKEFILE_DIR)../$(INTERNAL_PREFIX_DIR_NAME)

PREFIX_DIR_NAME=prefix
PREFIX=$(THIS_MAKEFILE_DIR)../$(PREFIX_DIR_NAME)

LIBS_DIR_NAME=libs
LIBS_DIR=$(THIS_MAKEFILE_DIR)../$(LIBS_DIR_NAME)

# Usage
usage : 
	@echo "iOS platform:"
	@echo " make build-ios [PREFIX=/mypath/to/prefix/directory]"
	@echo "  PREFIX : Absolute path to directory to copy built library to. Default: $(PREFIX)"

#
# iOS 
#

# Retrieve Mandatory iOS dependencies
dependencies-ios : 
	mkdir -p $(LIBS_DIR)
	(cd $(LIBS_DIR) && (test -d target-conditionals.git) || (git clone git://github.com/davidandreoletti/target-conditionals.git target-conditionals.git && cd target-conditionals.git && git checkout tags/1.0.0f0)) \
	&& (cd $(LIBS_DIR) && (test -d sourceforge-libjson.git) || (git clone git://github.com/davidandreoletti/sourceforge-libjson.git sourceforge-libjson.git && cd sourceforge-libjson.git && git checkout tags/1.0.0f0)) \
	&& (cd $(LIBS_DIR) && (test -d boostoniphone-generic.git) || (git clone git://github.com/davidandreoletti/boostoniphone-generic.git boostoniphone-generic.git && cd boostoniphone-generic.git && git checkout tags/1.2.0f0))

# Build Mandatory iOS dependencies
build-dependencies-ios : 
	(cd $(LIBS_DIR)/sourceforge-libjson.git && make)
	(cd $(LIBS_DIR)/boostoniphone-generic.git && export BOOST_LIBS=test && export BOOST_VERSION=1_50_0 && export IPHONE_SDKVERSION=5.1 && ./boost.sh)	
	
# Clean iOS build
clean-ios :
	rm -rf $(PREFIX_DIR)

# Build for iOS
build-ios : clean-ios dependencies-ios build-dependencies-ios
	xcrun --verbose xcodebuild -verbose -project ./proj.ios/settingsapi-core-lib/settingsapi-core-lib.xcodeproj -target settingsapi -configuration Release -sdk iphoneos -arch "armv6 armv7" clean install || false
	([ "$(INTERNAL_PREFIX_DIR)" != "$(PREFIX)" ] && cp -v $(INTERNAL_PREFIX_DIR)/* $(PREFIX)/ ) || [ "$(INTERNAL_PREFIX_DIR)" == "$(PREFIX)" ]

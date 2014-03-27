# This file is part of CE3D. License: GPL3

# this makefile is a wrapper for the projects in here.

CE3D_DEBUG_BUILD_DIR	= build/CE3D_debug
CE3D_RELEASE_BUILD_DIR	= build/CE3D_release
CE3D_SRC_FROM_BUILD	= ../../src
CE3D_MAKE_FLAGS		= --no-print-directory -j4
CE3D_CLEAN_TARGET	= clean

CMAKE := $(shell which cmake)
CMAKE_DEBUG_FLAGS = -DCMAKE_BUILD_TYPE=Debug
CMAKE_RELEASE_FLAGS = -DCMAKE_BUILD_TYPE=Release

ifeq ($(CMAKE),)
$(error ERROR. Missing dependency: cmake)
endif

default:
	@echo "No target chosen. Please select one of the following:"
	@echo "  debug       : builds the CE3D library with tests and debugging symbols"
	@echo "  cleandebug  : cleans everything generated by 'debug' target"
	@echo ""
	@echo "  release     : builds the CE3D library"
	@echo "  cleanrelease: cleans everything generated by 'release' target"

debug: BUILD_CE3D_DEBUG
cleandebug: CLEAN_CE3D_DEBUG

release: BUILD_CE3D_RELEASE
cleanrelease: CLEAN_CE3D_RELEASE

CE3D_DEBUG_BUILD_DIR:
	@if ! test -d $(CE3D_DEBUG_BUILD_DIR);			\
	 then							\
		echo -n "Creating build directory... ";		\
		mkdir -p $(CE3D_DEBUG_BUILD_DIR);		\
		echo "Done.";					\
	 fi

CE3D_RELEASE_BUILD_DIR:
	@if ! test -d $(CE3D_RELEASE_BUILD_DIR);		\
	 then							\
		echo -n "Creating build directory... ";		\
		mkdir -p $(CE3D_RELEASE_BUILD_DIR);		\
		echo "Done.";					\
	 fi

CONF_CE3D_DEBUG: CE3D_DEBUG_BUILD_DIR
	@echo "Invoking CMake."
	@cd $(CE3D_DEBUG_BUILD_DIR);				\
	 $(CMAKE) $(CE3D_SRC_FROM_BUILD) $(CMAKE_DEBUG_FLAGS)

CONF_CE3D_RELEASE: CE3D_RELEASE_BUILD_DIR
	@echo "Invoking CMake."
	@cd $(CE3D_RELEASE_BUILD_DIR);				\
	 $(CMAKE) $(CE3D_SRC_FROM_BUILD) $(CMAKE_RELEASE_FLAGS)

BUILD_CE3D_DEBUG: CONF_CE3D_DEBUG
	@echo "Building CE3D library..."
	@$(MAKE) -C $(CE3D_DEBUG_BUILD_DIR) $(CE3D_MAKE_FLAGS)
	@echo "Done."

BUILD_CE3D_RELEASE: CONF_CE3D_RELEASE
	@echo "Building CE3D library..."
	@$(MAKE) -C $(CE3D_RELEASE_BUILD_DIR) $(CE3D_MAKE_FLAGS)
	@echo "Done."

CLEAN_CE3D_DEBUG:
	@$(MAKE) -C $(CE3D_DEBUG_BUILD_DIR) $(CE3D_MAKE_FLAGS)	\
	$(CE3D_CLEAN_TARGET)

CLEAN_CE3D_RELEASE:
	@$(MAKE) -C $(CE3D_RELEASE_BUILD_DIR) $(CE3D_MAKE_FLAGS)	\
	$(CE3D_CLEAN_TARGET)


# This file is part of CE3D. License: GPL3

# this makefile is a wrapper for the projects in here.

CE3D_BUILD_DIR = build/CE3D
CE3D_SRC_FROM_BUILD = ../../src
CE3D_MAKE_FLAGS = --no-print-directory
CE3D_CLEAN_TARGET = clean

CMAKE := $(shell which cmake)

ifeq ($(CMAKE),)
$(error ERROR. Missing dependency: cmake)
endif

default:
	@echo "No target chosen. Please select one of the following:"
	@echo "  lib     : builds the CE3D library"
	@echo "  cleanlib: cleans the CE3D library"

lib: BUILD_CE3D
cleanlib: CLEAN_CE3D

CE3D_BUILD_DIR:
	@if ! test -d $(CE3D_BUILD_DIR);			\
	 then							\
		echo -n "Creating build directory... ";		\
		mkdir -p $(CE3D_BUILD_DIR);			\
		echo "Done.";					\
	 fi

CONF_CE3D: CE3D_BUILD_DIR
	@echo "Invoking CMake."
	@cd $(CE3D_BUILD_DIR);					\
	 $(CMAKE) $(CE3D_SRC_FROM_BUILD)

BUILD_CE3D: CONF_CE3D
	@echo "Building CE3D library..."
	@$(MAKE) -C $(CE3D_BUILD_DIR) $(CE3D_MAKE_FLAGS)
	@echo "Done."

CLEAN_CE3D:
	@$(MAKE) -C $(CE3D_BUILD_DIR) $(CE3D_MAKE_FLAGS) $(CE3D_CLEAN_TARGET)

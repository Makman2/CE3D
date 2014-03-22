# This file is part of CE3D. License: GPL3

# this makefile is a wrapper for the projects in here.

CE3D_BUILD_DIR = build/CE3D
CE3D_SRC_FROM_BUILD = ../../src

CMAKE := $(shell which cmake)

CE3D: BUILD_CE3D

CE3D_BUILD_DIR:
	@if ! test -d $(CE3D_BUILD_DIR);			\
	 then							\
		echo -n "Creating build directory... ";		\
		mkdir -p $(CE3D_BUILD_DIR);			\
		echo "Done.";					\
	 fi

BUILD_CE3D: CE3D_BUILD_DIR
	@echo "Invoking CMake."
	@cd $(CE3D_BUILD_DIR);					\
	 $(CMAKE) $(CE3D_SRC_FROM_BUILD)
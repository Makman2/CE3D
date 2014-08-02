# This file is part of CE3D. License: GPL3

# this makefile is a wrapper for the projects in here.

CE3D_DEBUG_BUILD_DIR	= build/CE3D_debug
CE3D_RELEASE_BUILD_DIR	= build/CE3D_release
CE3D_CODEBLOCKS_PROJ_DIR= build/Codeblocks
CE3D_ECLIPSE_PROJ_DIR   = build/Eclipse
CE3D_SRC_FROM_BUILD	= ../../CE3D
CE3D_MAKE_FLAGS		= --no-print-directory -j8
CE3D_CLEAN_TARGET	= clean
CE3D_INSTALL_TARGET	= install

CMAKE := $(shell which cmake)
CMAKE_DEBUG_FLAGS = -DCMAKE_BUILD_TYPE=Debug -DTESTS_ENABLED=true
CMAKE_RELEASE_FLAGS = -DCMAKE_BUILD_TYPE=Release
CMAKE_CODEBLOCKS_FLAGS = -G "CodeBlocks - Unix Makefiles" -DTESTS_ENABLED=true
CMAKE_ECLIPSE_FLAGS = -G "Eclipse CDT4 - Unix Makefiles" -DTESTS_ENABLED=true

ifeq ($(CMAKE),)
$(error ERROR. Missing dependency: cmake)
endif

help:
	@echo "No target chosen. Please select one of the following:"
	@echo "  debug       : builds the CE3D library with tests and debugging symbols"
	@echo "  cleandebug  : cleans everything generated by 'debug' target"
	@echo ""
	@echo "  release     : builds the CE3D library"
	@echo "  install     : installs the CE3D library"
	@echo "  cleanrelease: cleans everything generated by 'release' target"
	@echo ""
	@echo "  doc         : builds the documentation"
	@echo ""
	@echo "  codeblocks  : generates a Code::Blocks project file"
	@echo "  eclipse     : generates an Eclipse project file"

debug: BUILD_CE3D_DEBUG
cleandebug: CLEAN_CE3D_DEBUG

release: BUILD_CE3D_RELEASE
install: INSTALL_CE3D_RELEASE
cleanrelease: CLEAN_CE3D_RELEASE

doc: BUILD_CE3D_DOC

codeblocks: CODEBLOCKS_PROJ
eclipse: ECLIPSE_PROJ

CE3D_DEBUG_BUILD_DIR:
	@if ! test -d $(CE3D_DEBUG_BUILD_DIR);			\
	 then							\
		echo -n "Creating debug build directory... ";	\
		mkdir -p $(CE3D_DEBUG_BUILD_DIR);		\
		echo "Done.";					\
	 fi

CE3D_RELEASE_BUILD_DIR:
	@if ! test -d $(CE3D_RELEASE_BUILD_DIR);		\
	 then							\
		echo -n "Creating release build directory... ";	\
		mkdir -p $(CE3D_RELEASE_BUILD_DIR);		\
		echo "Done.";					\
	 fi

CE3D_CODEBLOCKS_PROJ_DIR:
	@if ! test -d $(CE3D_CODEBLOCKS_PROJ_DIR);			\
	 then								\
		echo -n "Creating Code::Blocks project directory... ";	\
		mkdir -p $(CE3D_CODEBLOCKS_PROJ_DIR);			\
		echo "Done.";						\
	 fi

CE3D_ECLIPSE_PROJ_DIR:
	@if ! test -d $(CE3D_ECLIPSE_PROJ_DIR);				\
	 then								\
		echo -n "Creating eclipse project directory... ";	\
		mkdir -p $(CE3D_ECLIPSE_PROJ_DIR);			\
		echo "Done.";						\
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
	@echo "Building CE3D library (debug)..."
	@$(MAKE) -C V=1 $(CE3D_DEBUG_BUILD_DIR) $(CE3D_MAKE_FLAGS)
	@echo "Done."

BUILD_CE3D_DOC: CONF_CE3D_DEBUG
	@echo "Building CE3D documentation..."
	@$(MAKE) doc -C $(CE3D_DEBUG_BUILD_DIR) $(CE3D_MAKE_FLAGS)
	@echo "Done."

BUILD_CE3D_RELEASE: CONF_CE3D_RELEASE
	@echo "Building CE3D library (release)..."
	@$(MAKE) -C $(CE3D_RELEASE_BUILD_DIR) $(CE3D_MAKE_FLAGS)
	@echo "Done."

INSTALL_CE3D_RELEASE: CONF_CE3D_RELEASE
	@echo "Installing CE3D library (release)..."
	@$(MAKE) -C $(CE3D_RELEASE_BUILD_DIR) $(CE3D_MAKE_FLAGS)	\
	$(CE3D_INSTALL_TARGET)
	@echo "Done."

CLEAN_CE3D_DEBUG:
	@echo "Cleaning CE3D library (debug)..."
	@$(MAKE) -C $(CE3D_DEBUG_BUILD_DIR) $(CE3D_MAKE_FLAGS)	\
	$(CE3D_CLEAN_TARGET)

CLEAN_CE3D_RELEASE:
	@echo "Cleaning CE3D library (release)..."
	@$(MAKE) -C $(CE3D_RELEASE_BUILD_DIR) $(CE3D_MAKE_FLAGS)	\
	$(CE3D_CLEAN_TARGET)

CODEBLOCKS_PROJ: CE3D_CODEBLOCKS_PROJ_DIR
	@echo "Generating Code::Blocks project file..."
	@cd $(CE3D_CODEBLOCKS_PROJ_DIR);				\
	 $(CMAKE) $(CE3D_SRC_FROM_BUILD) $(CMAKE_CODEBLOCKS_FLAGS)
	@echo "Code::Blocks project file lies in $(CE3D_CODEBLOCKS_PROJ_DIR)"

ECLIPSE_PROJ: CE3D_ECLIPSE_PROJ_DIR
	@echo "Generating Eclipse project file..."
	@cd $(CE3D_ECLIPSE_PROJ_DIR);					\
	 $(CMAKE) $(CE3D_SRC_FROM_BUILD) $(CMAKE_ECLIPSE_FLAGS)
	@echo "Eclipse project files lies in $(CE3D_ECLIPSE_PROJ_DIR)"

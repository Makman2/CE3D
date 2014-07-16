# This file is part of CE3D. License: GPL3

SRCS	= main.cpp
GPP	= g++
GPPFLAGS= -std=c++11
TARGET	= cube
LIBS	= -lCE3D

default: help

help:
	@echo "No target chosen. Please select one of the following:"
	@echo "  build : builds example application"
	@echo "  clean : cleans build files for example application"
	@echo "  run   : runs the example application"

build: $(TARGET)

$(TARGET):
	@echo "Building cube..."
	@$(GPP) $(SRCS) -o $(TARGET) $(LIBS) $(GPPFLAGS)
	@echo "Done."

clean:
	@echo "Cleaning build files for cube..."
	@$(RM) -f $(TARGET)
	@echo "Done."

run: build
	@echo "Running cube..."
	@./cube
	@echo "Done."

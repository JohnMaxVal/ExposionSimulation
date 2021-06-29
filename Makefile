EXE = explosion

SRC_PATH = ./src/*.cpp
MAIN_FILE = main.cpp

CC = g++
COMPILER_FLAGS = -subsystem,windows
DBG_FLAG = -g

DEBUG_PATH = ./Debug
RELEASE_PATH = ./Release

# Source file include
INCLUDE_FILES_PATH = -I./include
SRC_FILES_PATH = ./src/*.cpp

# SDL include and library
SDL2_INCLUDE_PATH = -IC:/mingw_dev_lib/include/SDL2
SDL2_LIBS_PATH = -LC:/mingw_dev_lib/lib
SDL2_LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2.dll -lSDL2_test

COMPILER_FLAGS = -std=c++17

build:
	$(CC) \
	$(COMPILER_FLAGS) \
	$(DBG_FLAG) \
	$(MAIN_FILE) \
	$(INCLUDE_FILES_PATH) \
	$(SRC_FILES_PATH) \
	$(SDL2_INCLUDE_PATH) \
	$(SDL2_LIBS_PATH) \
	$(SDL2_LINKER_FLAGS) \
	-o $(DEBUG_PATH)/$(EXE)
	
run:
	./Debug/$(EXE)
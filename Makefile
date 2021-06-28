EXE = explosion

SRC_PATH = ./src/*.cpp

CC = g++
COMPILER_FLAGS = -subsystem,windows
DBG_FLAG = -g

DEBUG_PATH = ./Debug
RELEASE_PATH = ./Release

SDL2_INCLUDE_PATH = -IC:/mingw_dev_lib/include/SDL2
SDL2_LIBS_PATH = -LC:/mingw_dev_lib/lib

SDL2_LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2.dll -lSDL2_test

COMPILER_FLAGS = -std=c++17

build:
	$(CC) \
	$(COMPILER_FLAGS) \
	$(DBG_FLAG) \
	$(SRC_PATH) \
	$(SDL2_INCLUDE_PATH) \
	$(SDL2_LIBS_PATH) \
	$(SDL2_LINKER_FLAGS) \
	-o $(DEBUG_PATH)/$(EXE)
	
run:
	./Debug/$(EXE)
CC = g++
CFLAGS  = -g -Wall

#OBJS specifies which files to compile as part of the project
OBJS = Game.cpp TextureManager.cpp Map.cpp GameObject.cpp Tile.cpp TileGraph.cpp main.cpp
#OBJS = win.cpp
TARGET = main

BUILD_DIR = ./build
LIBS:= -lSDL2 -lSDL2_image #`sdl2-config --cflags --libs`
LIBSNEW = -I include -lSDL2 `sdl2-config --cflags --libs` -std=c++17
SRC_DIR= ./src
#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
# COMPILER_FLAGS = -w

.DEFAULT:
	@echo make all to build and run
	@echo make build to build
	@echo make run to run the build
	@echo make clean to remove build files

all: build run

clean:
	@echo Removing old build files :
	$(RM) -r $(BUILD_DIR)
build:
	@echo Building project :
# mkdir $(BUILD_DIR)
	cd $(SRC_DIR); $(CC) -o .$(BUILD_DIR)/$(TARGET) $(OBJS) $(LIBSNEW) $(CFLAGS)
	@echo Generated the executable without errors ...

run:
	cd $(BUILD_DIR); ./$(TARGET)

.PHONY: all build
maze:
	g++ -o ./build/maze-generator ./src/maze-generator.cpp -std=c++17
	cd ./build; ./maze-generator
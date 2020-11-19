SRC_DIR := src
OBJ_DIR := out
BIN_DIR := bin
EXE := $(BIN_DIR)/game
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))
CXX := g++
CXXFLAGS := -Wall -g -I include -I /home/marvin/lib/stb -lSDL2main -lSDL2 -lGL -lGLU -lGLEW

all: $(EXE)

.PHONY: all

$(EXE):	$(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(EXE)

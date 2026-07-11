CXX = g++
CXXFLAGS = -w

# Added -I. so subdirectories can see root header files
INCLUDE_PATHS = -I/opt/homebrew/include/SDL2 -I.
LIBRARY_PATHS = -L/opt/homebrew/lib

LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

OBJ_NAME = game.out

all:
	$(CXX) *.cpp Extra\ Classes/*.cpp $(CXXFLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(LINKER_FLAGS) -o $(OBJ_NAME)

clean:
	rm $(OBJ_NAME)

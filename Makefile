# Compiler and flags
CXX = g++
CXXFLAGS = -I. -Iinclude

# Libraries
LDFLAGS = -Llib -lraylib -lopengl32 -lgdi32 -lwinmm

# Auto-detect all .cpp files
SRC = $(wildcard *.cpp) $(wildcard classes/**/*.cpp)
OBJ = $(SRC:.cpp=.o)

# Output binary name
OUT = main

default: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(SRC) -o $(OUT) $(CXXFLAGS) $(LDFLAGS)

clean:
	del /Q *.o $(OUT).exe 2>nul || rm -f *.o $(OUT)

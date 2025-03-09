# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g

# Libraries
LIBS = -lSDL2 -lSDL2_gfx -lSDL2_mixer

# Source files
SRC = main.cpp physics.cpp enemy/Enemy.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Output executable
OUT = main

# Default target
all: $(OUT)

# Link the program
$(OUT): $(OBJ)
	$(CXX) $(OBJ) -o $(OUT) $(LIBS)

# Compile .cpp files to .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJ) $(OUT)

# Run the program
run: $(OUT)
	./$(OUT)


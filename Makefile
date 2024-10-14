# Compiler and flags
CXX = g++
CXXFLAGS = -g -Wall -std=c++17

# Target executable name
TARGET = Main.exe

# Source files
SOURCES = Main.cpp Utility.cpp

# Object files (generated from source files)
OBJECTS = $(SOURCES:.cpp=.o)

# Default target to build the executable
all: $(TARGET)

# Rule to link object files into the final executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

# Rule to compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target to remove object files and the executable
clean:
	rm -f $(OBJECTS) $(TARGET)

# PHONY targets are not actual files
.PHONY: all clean

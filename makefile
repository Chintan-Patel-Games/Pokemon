# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++11 -Iinclude

# Directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

# Source files
SRCS = Main.cpp \
       $(wildcard $(SRC_DIR)/Battle/*.cpp) \
       $(wildcard $(SRC_DIR)/Character/*.cpp) \
       $(wildcard $(SRC_DIR)/Character/Player/*.cpp) \
       $(wildcard $(SRC_DIR)/Main/*.cpp) \
       $(wildcard $(SRC_DIR)/Pokemon/*.cpp) \
       $(wildcard $(SRC_DIR)/Pokemon/Pokemons/*.cpp) \
       $(wildcard $(SRC_DIR)/Pokemon/StatusEffects/*.cpp) \
       $(wildcard $(SRC_DIR)/Utility/*.cpp)

# Object files
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# The final target (executable)
TARGET = Pokemon

# Default rule to build the final executable
all: $(TARGET)

# Link object files into the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile each source file to an object file
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)  # Create directories if needed
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove build directory and executable
clean:
	rm -rf $(BUILD_DIR) $(TARGET)
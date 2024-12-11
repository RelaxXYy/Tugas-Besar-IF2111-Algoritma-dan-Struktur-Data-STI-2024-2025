# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Isrc/include

# Source directories
SRC_DIR = src
FUNCTION_DIR = $(SRC_DIR)/function
ADT_DIR = $(SRC_DIR)/ADT

# Source files
SRC_FILES = $(wildcard $(FUNCTION_DIR)/*.c) $(wildcard $(ADT_DIR)/*.c)

# Output executable
OUTPUT = main

# Default target
all: $(OUTPUT)

# Build the executable
$(OUTPUT): $(SRC_FILES)
	$(CC) $(SRC_FILES) -o $(OUTPUT) $(CFLAGS)

# Clean target
clean:
	rm -f $(OUTPUT)

# Phony targets
.PHONY: all clean
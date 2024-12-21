# Compiler
CC = gcc

# Compiler flags
CFLAGS = 

# Source directories
SRC_DIR = src
FUNCTION_DIR = $(SRC_DIR)/function
ADT_BARANG = $(SRC_DIR)/ADT/Barang
ADT_CART = $(SRC_DIR)/ADT/Cart
ADT_HISTORY = $(SRC_DIR)/ADT/History
ADT_MESIN_KARAKTER = $(SRC_DIR)/ADT/Mesin\ Karakter
ADT_MESIN_KATA = $(SRC_DIR)/ADT/Mesin\ Kata
ADT_MESIN_USER = $(SRC_DIR)/ADT/User
ADT_MESIN_WISHLIST = $(SRC_DIR)/ADT/Wishlist

# Source files
SRC_FILES = $(wildcard $(ADT_DIR)/*.c) $(wildcard $(FUNCTION_DIR)/*.c)

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
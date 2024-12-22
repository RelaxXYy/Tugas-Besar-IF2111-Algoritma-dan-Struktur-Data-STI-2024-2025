# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Isrc \
         -Isrc/function \
         -Isrc/ADT/Barang \
         -Isrc/ADT/Cart \
         -Isrc/ADT/History \
         -Isrc/ADT/Mesin_Karakter \
         -Isrc/ADT/Mesin_Kata \
         -Isrc/ADT/User \
         -Isrc/ADT/Wishlist

# Source directories
SRC_DIR = src
FUNCTION_DIR = $(SRC_DIR)/function
ADT_BARANG = $(SRC_DIR)/ADT/Barang
ADT_CART = $(SRC_DIR)/ADT/Cart
ADT_HISTORY = $(SRC_DIR)/ADT/History
ADT_MESIN_KARAKTER = $(SRC_DIR)/ADT/Mesin_Karakter
ADT_MESIN_KATA = $(SRC_DIR)/ADT/Mesin_Kata
ADT_USER = $(SRC_DIR)/ADT/User
ADT_MESIN_WISHLIST = $(SRC_DIR)/ADT/Wishlist

# Source files
SRC_FILES = $(wildcard $(FUNCTION_DIR)/*.c) \
            $(ADT_BARANG)/barang.c \
            $(ADT_CART)/cart.c \
            $(ADT_HISTORY)/history.c \
            $(ADT_MESIN_KARAKTER)/mesin_karakter.c \
            $(ADT_MESIN_KATA)/mesin_kata.c \
            $(ADT_USER)/user.c \
            $(ADT_WISHLIST)/wishlist.c

# Output executable
OUTPUT = "best_purrmart_in_STI"

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
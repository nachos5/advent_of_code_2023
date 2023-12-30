# Makefile

# Example to run problem 1: make && build/main 1

# Compiler and compiler flags
CC = gcc
CFLAGS = -Wall -Wextra

# Target executable name
TARGET = main

# Source and build directories
SRCDIR = src
BUILDDIR = build

# Source and object files
SOURCES = $(SRCDIR)/main.c $(SRCDIR)/problem_1/problem_1.c
OBJECTS = $(SOURCES:.c=.o)

# Default rule
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(BUILDDIR)/$(TARGET)

# To start over from scratch
clean:
	rm -f $(SRCDIR)/*.o $(SRCDIR)/1/*.o $(BUILDDIR)/$(TARGET)

# Rule for building object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Makefile for your C program

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -std=c99

# Source files
SRCS = main.c functions.c

# Header files
HEADERS = header.h

# Object files (automatically generated from source files)
OBJS = $(SRCS:.c=.o)

# Executable name
EXECUTABLE = main

# Default target
all: $(EXECUTABLE)

# Linking step
$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Compilation step for source files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -f $(OBJS) $(EXECUTABLE)

# Run the program
run: $(EXECUTABLE)
	./$(EXECUTABLE)


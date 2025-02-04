# Makefile for C programming projects
# Compiler and flags
CC = clang
CFLAGS = -std=c18 -Wall -Wextra -Wnull-dereference -Wformat=2 -Wno-newline-eof \
         -Wno-comment -pedantic -g
LDFLAGS = -lm  # Link math library by default

# Directories
SRCDIR = .
OBJDIR = obj
BINDIR = bin

# Project name and files
TARGET = $(BINDIR)/textadventure
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Ensure build directories exist
$(shell mkdir -p $(OBJDIR) $(BINDIR))

# ANSI color codes
BLUE = \033[1;34m
GREEN = \033[1;32m
YELLOW = \033[1;33m
RED = \033[1;31m
RESET = \033[0m

.PHONY: all clean rebuild force help logs

# Default target
all: $(TARGET)

# Compile object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo "$(BLUE)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Link executable
$(TARGET): $(OBJECTS)
	@echo "$(BLUE)Linking $@...$(RESET)"
	@$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	@echo "$(GREEN)Finished building $@$(RESET)"

# Generate compilation logs
logs: CFLAGS += -fdiagnostics-format=json
logs: all
	@for source in $(SOURCES); do \
		$(CC) $(CFLAGS) $$source 2> "$${source%.c}.log"; \
		echo "$(YELLOW)Generated log for $$source$(RESET)"; \
	done

# Force recompilation of all files
rebuild: clean all
	@echo "$(GREEN)Rebuilt all files!$(RESET)"

# Force recompilation without cleaning
force:
	@echo "$(YELLOW)Forcing recompilation of all files...$(RESET)"
	@touch $(SOURCES)
	@$(MAKE) all

# Clean all generated files
clean:
	@echo "$(RED)Cleaning up...$(RESET)"
	@rm -rf $(OBJDIR) $(BINDIR) *.log
	@echo "$(GREEN)Cleanup complete$(RESET)"

# Help message
help:
	@echo "Usage:"
	@echo "  make          - Compile the project"
	@echo "  make logs     - Compile and generate warning/error logs"
	@echo "  make clean    - Remove all compiled files and logs"
	@echo "  make rebuild  - Clean and rebuild all files"
	@echo "  make force    - Force recompilation without cleaning"
	@echo "  make help     - Display this help message"
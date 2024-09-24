TARGET = tetris
CC = gcc

PREF_SRC = ./src/
PREF_OBJ = ./obj/

# list all .c files in the current directory and it's subdirectories
SRC = $(shell find . -name "*.c")
# transforms each .c source file path in SRC to an .o object file
# path in OBJ
# % sign is a placeholder for any sequence of characters
OBJ = $(patsubst $(PREF_SRC)%.c, $(PREF_OBJ)%.o, $(SRC))

# compiles all object files into the final executable
# Make uses the first target as the default target
# It doesn't matter what the name is (all: doesn't mean anything)
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -lncurses -o $(TARGET)

# $< is an automatic variable that represents the first prerequisite
# (the source file in this case, e.g. file.c)

# $@ is another automatic variable that represents the target of the
# rule (the object file, e.g. file.o)

# line mkdir -p (dir $@) ensures that directory for the object file
# exists before attempting to create the .o file (i.e. ./obj)
$(PREF_OBJ)%.o : $(PREF_SRC)%.c
	mkdir -p $(dir $@)
	$(CC) -c $< -o $@

clean:
	rm $(TARGET) $(OBJ)

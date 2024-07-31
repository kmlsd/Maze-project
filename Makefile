# CC specifies the compiler to be used
CC = gcc

# SRC specifies the .c files
SRC = src/main.c src/Player_cntrol.c src/Wall_rend1.c src/Wall_rend2.c \
	src/Wall_rend3.c src/bool_int.c src/game_loop1.c src/game_loop2.c \
	src/sky_floo.c src/wrlmap.c

# OBJ specifies the .o files
OBJ = $(SRC:.c=.o)

# NAME specifies the name of our exectuable
NAME = 'Maz-Project'

# RM specifies the program to delete files
RM = rm -f

# SDL2 runs the sdl2-config program with the necessary flags
SDL2 := $$(sdl2-config --cflags --libs)

# CFLAGS specifies your favorite compiler flags
CFLAGS = -Wall -Werror -Wextra -pedantic
LDFLAGS = -lm
# LFLAGS specifies the linker flags
# LFLAGS =

# Makefile should work even if there is a file in the folder
# that has the same name as rule
.PHONY: all clean oclean fclean re
# This rule builds our executable
# Makefile should not compile if the header file main.h is missing
all: header/main.h $(OBJ)
	$(CC)  $(OBJ) $(CFLAGS)  $(LDFLAGS) $(SDL2) -o $(NAME)

# This rule deletes all Emacs and Vim temporary files along with the executable
clean:
	$(RM) *~ $(NAME)


# This rule deletes the object files
oclean:
	$(RM) $(OBJ)

# This rule deletes all Emacs and Vim temporary files, the executable, and the object files
fclean: clean oclean

# This rule forces recompilation of all source
re: fclean all

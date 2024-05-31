#*******************************  VARIABLES  **********************************#

# --------------- UTILS --------------- #

RED			=	\033[1;31m
GREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
BLUE		=	\033[1;34m
CYAN		=	\033[1;36m
DEFAULT		=	\033[0m
SUPPR		=	\r\033[2K
NAME		=	libasm.a
TEST		=	test_main

# --------------- FILES --------------- #

LIST_SRC	=	hello_world.s

TEST_SRC	=	srcs/test/main.c

# ------------ DIRECTORIES ------------ #

DIR_BUILD		=		.build/
DIR_SRC			=		srcs/

# ------------- SHORTCUTS ------------- #

OBJ				=		$(patsubst %.s, $(DIR_BUILD)%.o, $(SRC))
SRC				=		$(addprefix $(DIR_SRC),$(LIST_SRC))

# ------------ COMPILATION ------------ #

NASM			=		nasm -f elf64

AR				=		ar rcs

LD				=		ld

# -------------  COMMANDS ------------- #

RM				=		rm -rf
MKDIR			=		mkdir -p

#***********************************  RULES  **********************************#

all:		$(NAME)

# ---------- VARIABLES RULES ---------- #

$(NAME):	$(OBJ)
			$(AR) $(NAME) $(OBJ)

# ---------- COMPILED RULES ----------- #

$(DIR_BUILD)%.o: %.s
			mkdir -p $(shell dirname $@)
			$(NASM) $< -o $@

clean:
			$(RM) $(DIR_BUILD)
			$(RM) $(TEST)

fclean:	clean
			$(RM) $(NAME)

re:		fclean
			$(MAKE) all

test:	all
		gcc -o $(TEST) $(TEST_SRC) -L. -lasm


.PHONY: all, clean, fclean, re, test

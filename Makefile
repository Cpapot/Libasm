#*******************************  VARIABLES  **********************************#

# --------------- UTILS --------------- #

RED				=	\033[1;31m
GREEN			=	\033[1;32m
YELLOW			=	\033[1;33m
BLUE			=	\033[1;34m
CYAN			=	\033[1;36m
DEFAULT			=	\033[0m
SUPPR			=	\r\033[2K
NAME			=	libasm.a
TEST_NAME		=	test_main

# --------------- FILES --------------- #

LIST_SRC	=	ft_strlen.s		\
				ft_strcpy.s

TEST_SRC	=	main.c				\
				ft_strlen_test.c	\
				ft_strcpy_test.c

# ------------ DIRECTORIES ------------ #

DIR_BUILD		=		.build/
DIR_SRC			=		srcs/
DIR_TEST		=		test/

# ------------- SHORTCUTS ------------- #

OBJ				=		$(patsubst %.s, $(DIR_BUILD)%.o, $(SRC))
SRC				=		$(addprefix $(DIR_SRC),$(LIST_SRC))
TEST			=		$(addprefix $(DIR_TEST),$(TEST_SRC))

# ------------ COMPILATION ------------ #

NASM			=		nasm -f elf64

AR				=		ar rcs

LD				=		ld

GCC				=		gcc -g -fsanitize=address

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
			$(RM) $(TEST_NAME)

fclean:	clean
			$(RM) $(NAME)

re:		fclean
			$(MAKE) all

test:	all
		$(GCC) -o $(TEST_NAME) $(TEST) -L. -lasm


.PHONY: all, clean, fclean, re, test

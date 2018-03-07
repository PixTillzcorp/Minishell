.PHONY: clean, fclean, re

.SUFFIXES:

#~~~~~~~~~~~~~~~~COLORS~~~~~~~~~~~~~~

FONT_NOIR = \033[40m
BLACK = \033[30m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
PINK = \033[35m
CYAN = \033[36m
GREY = \033[37m

NORMAL = \033[0m

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

NAME = minishell

LIB_PATH = libft/

CC = gcc

SRCC =	execute.c env.c builtins.c ft_change_dir.c ft_echo.c get_command.c	\
		minishell.c

SRCO =	execute.o env.o builtins.o ft_change_dir.o ft_echo.o get_command.o	\
		minishell.o

LIB_SRC = libft/libft.a

CFLAGS = -g -Wall -Wextra -Werror

all: lib $(NAME)

#Display rules~~~~~~~~~~~~

cleared:
	@ echo "$(YELLOW)$(FONT_NOIR)$(NAME) : $(RED).o files destruction\t\t[$(GREEN)\xe2\x9c\x94$(RED)]$(NORMAL)"

full_clear:
	@ echo "$(YELLOW)$(FONT_NOIR)$(NAME) : $(RED)executable file destruction\t[$(GREEN)\xe2\x9c\x94$(RED)]$(NORMAL)"

re_init:
	@ echo "$(BLUE)$(FONT_NOIR)Reseting $(NAME) }~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~$(NORMAL)"

re_done:
	@ echo "$(BLUE)$(FONT_NOIR)~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~{ Reset Complete[$(GREEN)\xe2\x9c\x94$(BLUE)]$(NORMAL)"

#Lib rules~~~~~~~~~~~~~~~~

lib:
	@ make -C $(LIB_PATH)

lib_re:
	@ make -C $(LIB_PATH) re

%.o: %.c
	@ $(CC) $(CFLAGS) -c $<

$(NAME): $(SRCO) minishell.h
	@ echo "$(PINK)$(FONT_NOIR).o successfully created\t\t\t[$(GREEN)\xe2\x9c\x94$(PINK)]$(NORMAL)"
	@ $(CC) $(CFLAGS) -o $(NAME) $(SRCO) $(LIB_SRC)
	@ echo "$(PINK)$(FONT_NOIR)Compilation of $(NAME)\t\t\t[$(GREEN)\xe2\x9c\x94$(PINK)]$(NORMAL)"

clean: cleared
	@ make -C $(LIB_PATH) clean
	@ rm -f $(SRCO)

fclean: full_clear clean
	@ make -C $(LIB_PATH) fclean
	@ rm -f $(NAME)

re: re_init fclean lib_re $(NAME) re_done
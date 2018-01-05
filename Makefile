# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: eruaud <marvin@le-101.fr>                  +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/12/28 15:26:42 by eruaud       #+#   ##    ##    #+#        #
#    Updated: 2018/01/05 15:04:10 by eruaud      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = printf
DNAME = debug
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUG = -ggdb
FUNC = printf main
SRC = $(addprefix src/, $(addsuffix .c, $(FUNC)))
OBJ = $(addprefix build/, $(addsuffix .o, $(FUNC)))
HEADER = -I tests/includes/ -I libft/includes/ -I framework/includes/
LDLIBS = -lft -lunit
LDFLAGS = -L libft/ -Lframework/
RED = \033[1;31m
GREEN = \033[1;92m
BLUE = \033[34;1m
YELLOW = \033[0;33m

all: $(NAME)

print:
	@echo "\n$(YELLOW)(╯°□°)–︻╦╤─ – – – PRINTF - - - \n"

lib:
	@echo "  $(RED)Compiling libft..."
	@make -C libft
	@echo "    $(GREEN)Success !"
	@echo "  $(RED)Compiling libunit..."
	@make -C framework
	@echo "    $(GREEN)Success !\n"

$(NAME): print lib $(OBJ)
	@echo "  $(RED)Compiling project..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(HEADER) $(LDLIBS) $(LDFLAGS)
	@echo "    $(GREEN)Success !\n"

debug : fclean lib $(OBJ)
	@echo "  $(RED)Compiling project for debugging..."
	@$(CC) $(DEBUG) $(CFLAGS) -o $(DNAME) $(OBJ) $(HEADER) $(LDLIBS) $(LDFLAGS)
	@echo "    $(GREEN)Success !\n"
	@lldb ./$(DNAME)

grind : $(NAME)
	@valgrind --leak-check=full --tool=memcheck ./$(NAME) tests/manual/in1
	@rm -rf $(NAME).dSYM

norm :
	@norminette $(FUNC)

./build/%.o : ./src/%.c
	@echo "     $(YELLOW) → Compiling $<"
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADER)

clean:
	@/bin/rm -f $(OBJ)
	@make -C libft clean
	@make -C framework clean
	@echo "  $(BLUE)Project has been cleaned !"

fclean: clean
	@/bin/rm -f $(NAME) $(DNAME)
	@make -C libft fclean
	@make -C framework fclean
	@echo "  $(BLUE)Project has been removed !\n"

re: fclean $(NAME)

.PHONY = all clean fclean re norm lib


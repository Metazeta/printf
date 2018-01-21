# **************************************************************************** #
#                                                          LE - /              #
#                                                              /               #
#   Makefile                                         .::    .:/ .      .::     #
#                                                 +:+:+   +:    +:  +:+:+      #
#   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+       #
#                                                 #+#   #+    #+    #+#        #
#   Created: 2017/12/28 15:26:42 by eruaud       #+#   ##    ##    #+#         #
#   Updated: 2018/01/20 19:27:45 by eruaud      ###    #+. /#+    ###.fr       #
#                                                         /                    #
#                                                        /                     #
# **************************************************************************** #

# FILES
SRC = main.c
TESTS = 00_launcher.c \
		01_test.c \
		02_test.c \
		03_test.c
TESTS_PATH = $(addprefix printf/, $(TESTS))
TESTS_OBJ = $(TESTS_PATH:.c=.o)
ALL_SRC = $(SRC) $(TESTS_PATH)
ALL_OBJ = $(ALL_SRC:.c=.o)

# CC PARAMETERS
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUG = -ggdb
HEADER = -I ../includes/ -I includes/ -I ../libft/includes/ -I ../framework/includes/
LDLIBS = -lft -lunit -lftprintf
LDFLAGS = -L ../libft/ -L ../framework/ -L ../
NAME = run_test
DNAME = debug

# STYLING
RED = \033[1;31m
GREEN = \033[1;92m
BLUE = \033[34;1m
YELLOW = \033[0;33m

# RULES

all: $(NAME)

label:
	@echo "\n  $(YELLOW)------FRESHLY BAKED UNIT TESTER-------\n"
	@echo "  $(RED)Compiling project..."

lib:
	@echo "$(BLUE)Compiling libraries..."
	@echo "  $(RED)libft..."
	@make -C ../libft
	@echo "    $(GREEN)Success !"
	@echo "  $(RED)libunit..."
	@make -C ../framework
	@echo "    $(GREEN)Success !\n"
	@echo "  $(RED)libftprintf..."
	@make -C ../
	@echo "    $(GREEN)Success !\n"

$(NAME): lib label $(ALL_OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(ALL_OBJ) $(HEADER) $(LDLIBS) $(LDFLAGS)
	@echo "    $(GREEN)Success !\n"

try : lib label try.o
	@g++ $(DEBUG) $(CFLAGS) -o try try.o $(HEADER) $(LDLIBS) $(LDFLAGS)
	@echo "    $(GREEN)Success !\n"

debug : fclean lib $(ALL_OBJ)
	@echo "  $(RED)Compiling project for debugging..."
	@$(CC) $(DEBUG) $(CFLAGS) -o $(DNAME) $(ALL_OBJ) $(HEADER) $(LDLIBS) $(LDFLAGS)
	@echo "    $(GREEN)Success !\n"
	@lldb ./$(DNAME)

norm :
	@echo "$(YELLOW)"
	@norminette $(ALL_SRC)

test: fclean norm $(NAME)
	@./$(NAME)

%.o : %.c
	@echo "     $(YELLOW) → Compiling $<"
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADER)

clean:
	@/bin/rm -f $(ALL_OBJ)
	@make -C ../ clean
	@make -C ../libft clean
	@make -C ../framework clean
	@echo "  $(BLUE)Project has been cleaned !\n"

fclean:
	@/bin/rm -f $(ALL_OBJ) $(NAME) $(DNAME)
	@make -C ../ fclean
	@make -C ../libft fclean
	@make -C ../framework fclean
	@echo "  $(BLUE)Project has been wiped !\n"

re: fclean $(NAME)

.PHONY = all clean fclean re norm lib

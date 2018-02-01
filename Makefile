# **************************************************************************** #
#                                                          LE - /              #
#                                                              /               #
#   Makefile                                         .::    .:/ .      .::     #
#                                                 +:+:+   +:    +:  +:+:+      #
#   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+       #
#                                                 #+#   #+    #+    #+#        #
#   Created: 2017/12/28 15:26:42 by eruaud       #+#   ##    ##    #+#         #
#   Updated: 2018/02/01 10:58:14 by eruaud      ###    #+. /#+    ###.fr       #
#                                                         /                    #
#                                                        /                     #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
#CFLAGS = -Wall -Wextra -Werror
CFLAGS = -g
FUNC = ft_prf_utils \
		ft_prf_strutils \
		ft_prf_strutils2 \
		ft_prf_putwchar \
		ft_prf_launcher \
		ft_prf_s \
		ft_prf_p \
		ft_prf_x \
		ft_prf_pc \
		ft_prf_d \
		ft_prf_d2 \
		ft_prf_c \
		ft_prf_atoi \
		ft_prf_numutil \
		prf_tags \
		ft_prf_o \
		ft_printf
SRC = $(addprefix src/, $(addsuffix .c, $(FUNC)))
OBJ = $(addprefix build/, $(addsuffix .o, $(FUNC)))
RED = \033[1;31m
GREEN = \033[1;92m
BLUE = \033[34;1m
YELLOW = \033[0;33m
HEADER = -I includes/

all: $(NAME)

label:
	@echo "$(YELLOW)(╯°□°)–︻╦╤─ – – – PRINTF - - - "
	@echo "  $(BLUE)Compiling $(NAME) library..."

$(NAME): $(OBJ)
	@ar -rc $@ $^
	@echo "  $(GREEN)Compilation of $(NAME) is a success."

./build/%.o: ./src/%.c
	@echo "     $(YELLOW) → Compiling $<"
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADER)
	@echo "     $(GREEN)   OK"

norm :
	@norminette $(SRC)

clean:
	@/bin/rm -f $(OBJ)
	@echo "  $(YELLOW)OBJ files have been deleted."

fclean:
	@/bin/rm -f $(OBJ) $(NAME)
	@echo "  $(YELLOW)$(NAME) and OBJ files have been deleted."

re: fclean $(NAME)

copy:
	@cp -rf build ../../vogsphere/printf
	@cp -rf src ../../vogsphere/printf
	@cp -rf includes ../../vogsphere/printf
	@cp  Makefile ../../vogsphere/printf
	@cp  auteur ../../vogsphere/printf
	@echo "  $(YELLOW)$(NAME) have been copied to vogsphere."

curqui: $(NAME)
	@cp libftprintf.a curqui/
	@make -C curqui/
	@./curqui/ft_printf_tests

.PHONY = all clean fclean re norm lib

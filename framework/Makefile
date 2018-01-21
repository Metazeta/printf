# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpisano <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 14:30:17 by bpisano           #+#    #+#              #
#    Updated: 2017/12/02 15:48:17 by htaillef    ###    #+. /#+    ###.fr      #
#                                                                              #
# **************************************************************************** #

SRC = ./src/testlist.c	\
	  ./src/display.c	\

OBJECTS = $(SRC:.c=.o)

NAME = libunit.a

HEADS = ./includes

FLAGS = -Wall -Werror -Wextra

.PHONY = all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar -rcs $(NAME) $(OBJECTS)

%.o : %.c
	@gcc $(FLAGS) -I $(HEADS) -o $@ -c $<

clean:
	@rm -rf $(OBJECTS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

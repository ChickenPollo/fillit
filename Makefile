# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fjankows <fjankows@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/18 18:31:57 by fjankows          #+#    #+#              #
#    Updated: 2020/03/08 23:25:59 by fjankows         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SOURCES = ./fillit.h
CFILES = *.c
NAME = fillit

LIB = libft/libft.a

$(NAME):
	make -C libft
	$(CC) $(CFLAGS) $(CFILES) $(LIB) -o $(NAME)

.PHONY: all clean fclean re

all: $(NAME)

clean:
	make -C libft clean
	rm -f *.a
	rm -f *.o

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

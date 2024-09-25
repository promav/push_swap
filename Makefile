# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabromer <pabromer@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 11:19:49 by pabromer          #+#    #+#              #
#    Updated: 2024/09/25 11:19:54 by pabromer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = aux1.c aux2.c aux3.c aux4.c bigmoves.c creator.c creator2.c \
ft_printf.c ft_printf_aux.c orders_1.c orders_2.c smallmoves1.c smallmoves2.c main.c
OBJ = $(SRC:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: 
	$(MAKE) -C bonus

fcbonus: 
	$(MAKE) -C bonus fclean

rebonus: 
	$(MAKE) -C bonus re

.PHONY: all clean fclean re bonus fcbonus rebonus

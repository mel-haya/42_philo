# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-haya <mel-haya@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/19 23:25:34 by mel-haya          #+#    #+#              #
#    Updated: 2021/11/22 16:16:33 by mel-haya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- Makefile -*-

NAME = libft.a
FLAGS = -Wall -Werror -Wextra
SRC = ft_atoi.c ft_isdigit.c ft_strlen.c ft_strncmp.c
O = $(SRC:.c=.o)

all: $(NAME)

$(NAME): 
	gcc $(SRC) -c $(FLAGS)
	ar rc $(NAME) $(O)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re:	fclean all

#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skushnir <skushnir@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/20 13:59:48 by skushnir          #+#    #+#              #
#    Updated: 2017/11/20 13:59:50 by skushnir         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit
SRC = input.c output.c valid.c lstnev.c substitution.c algorithm.c
OBJ = $(SRC:.c=.o)
HDR = fillit.h
LIB = libft/libft.a

all: $(SRC) $(NAME)

$(NAME): $(OBJ) $(HDR)
	make -C libft/
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRC) $(LIB)

.c.o: 
	gcc -Wall -Wextra -Werror -c $<

clean: 
	make clean -C libft/
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/17 16:41:55 by eenasalorin       #+#    #+#              #
#    Updated: 2020/03/21 15:55:33 by eenasalorin      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS = srcs/main.c srcs/execute.c srcs/builtin.c srcs/cd.c srcs/echo.c srcs/error.c \
srcs/split_args.c

OBJ = main.o execute.o builtin.o cd.o echo.o error.o split_args.o

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) :
		@make -C libft/
		@gcc -Wall -Wextra -Werror -c $(SRCS)
		@gcc -Wall -Wextra -Werror -o $(NAME) $(SRCS) libft/libft.a

clean : 
		@rm -f $(OBJ)
		@make clean -C libft/

fclean : clean
		@rm -f $(NAME)
		@make fclean -C libft/

re : fclean all
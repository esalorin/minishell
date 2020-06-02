# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/17 16:41:55 by eenasalorin       #+#    #+#              #
#    Updated: 2020/06/01 16:21:45 by eenasalorin      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

INC_DIR := ./includes
SRCS_DIR := ./srcs
OBJ_DIR := ./obj

SRCS := main.c execute.c builtin.c cd.c echo.c error.c split_args.c env.c \
quotes.c expansions.c update_shell_env.c

OBJ :=	$(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

.PHONY : all clean fclean re

all : $(NAME)

$(OBJ_DIR):
	@/bin/mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:$(SRCS_DIR)/%.c
	@gcc -Wall -Wextra -Werror -I $(INC_DIR) -o $@ -c $<

$(NAME) : $(OBJ_DIR) $(OBJ)
	@make -C libft/
	@gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ) libft/libft.a

clean : 
	@rm -f $(OBJ)
	@make clean -C libft/

fclean : clean
	@rm -f $(NAME)
	@make fclean -C libft/

re : fclean all

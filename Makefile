# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/17 16:41:55 by eenasalorin       #+#    #+#              #
#    Updated: 2020/06/02 17:48:13 by esalorin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

INC_DIR := ./includes
SRCS_DIR := ./srcs
OBJ_DIR := ./obj

SRCS := main.c execute.c builtin_functions.c cd.c echo.c error.c split_args.c \
env.c expansions.c update_shell_env.c setenv.c unsetenv.c check_home_env.c \
sh_command_check.c check_path.c prompt.c check_quotes.c escapes.c count_bslash.c \
escape_inside_quotes.c make_builtin.c

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

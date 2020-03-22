/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 16:54:20 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/03/21 16:04:00 by eenasalorin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include   "libft/srcs/libft.h"
# include   <sys/wait.h>
# include   <signal.h>

void	sh_loop(void);
void	sh_cd(char **args);
void	sh_echo(char **args);
void	error(char *s1, char *s2);

int		sh_execute(char **args);
int		builtin_func(char **args, int i);

char	**make_builtin(void);
char	**check_if_string(char *s);

#endif
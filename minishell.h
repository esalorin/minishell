/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 16:54:20 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/03/26 16:07:42 by eenasalorin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include		"libft/srcs/libft.h"
# include		<sys/wait.h>
# include		<sys/types.h>
# include		<sys/stat.h>
# include		<signal.h>

typedef struct	s_sh
{
    char		**env;

}				t_sh;

void			sh_loop(t_sh sh);
void			sh_cd(char **args, t_sh *sh);
void			sh_echo(char **args);
void			error(char *s1, char *s2);
void			sh_env(char **args, t_sh *sh);
void			sh_unsetenv(char **args, t_sh *sh);

int				sh_commands(char **args, t_sh *sh);
int				builtin_func(char **args, int i, t_sh *sh);

char			**make_builtin(void);
char			**check_if_string(char *s);

#endif
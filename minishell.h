/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 16:54:20 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/04/02 18:36:31 by eenasalorin      ###   ########.fr       */
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
    char        **args;
    char        *home;

}				t_sh;

void			sh_loop(t_sh sh);
void			sh_cd(t_sh *sh);
void			sh_echo(t_sh *sh);
void			error(char *s1, char *s2);
void			sh_env(t_sh *sh);
void			sh_unsetenv(t_sh *sh);
void			expansions(t_sh *sh);
void			sh_setenv(t_sh *sh);

int				sh_commands(t_sh *sh);
int				builtin_func(int i, t_sh *sh);
int				if_escape(char *s, char c);
int				quote_match(char *s);
int	        	count_slash(char *s, int i);

char            *ft_rmescapes_inquotes(char *s, char c);
char			*savehome(char **env);

char			**make_builtin(void);
char			**check_if_quotes(char *s);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 16:54:20 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/06/01 16:42:56 by eenasalorin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/srcs/libft.h"
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <signal.h>

# define BSLASH 92
# define DQUOTE 34
# define SQUOTE 39

typedef struct	s_sh
{
	char		**env;
	char		**args;
}				t_sh;


void			error(char *s1, char *s2);
void			expansions(t_sh *sh);
void			sh_cd(t_sh *sh);
void			sh_echo(t_sh *sh);
void			sh_env(t_sh *sh);
void			sh_setenv(t_sh *sh);
void			sh_unsetenv(t_sh *sh);
void			update_shell_env(char *av, t_sh *sh);

int				builtin_func(int i, t_sh *sh);
int				count_slash(char *s, int i);
int				if_escape(char *s, char c);
int				sh_commands(t_sh *sh);
int				quote_match(char *s);

char			*ft_rmescapes_inquotes(char *s, char c);
char			*checkhome(char **env);

char			**check_if_quotes(char *s);
char			**make_builtin(void);


#endif

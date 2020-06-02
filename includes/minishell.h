/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 16:54:20 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/06/02 17:48:34 by esalorin         ###   ########.fr       */
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
void			prompt(t_sh *sh);
void			sh_cd(t_sh *sh);
void			sh_echo(t_sh *sh);
void			sh_env(t_sh *sh);
void			sh_setenv(t_sh *sh);
void			sh_unsetenv(t_sh *sh);
void			update_shell_env(char *av, t_sh *sh);

int				builtin_functions(int i, t_sh *sh);
int				count_bslash(char *s, int i);
int				expansions(t_sh *sh);
int				sh_commands(t_sh *sh);
int				sh_exec(t_sh *sh);

char			*checkhome(char **env);
char			*find_path(t_sh *sh);
char			*ft_rmescapes_inquotes(char *s, char c);

char			**check_if_quotes(char *s);
char			**escapes(char **array);
char			**make_builtin(void);
char			**split_args(char *s);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 17:59:23 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/03/26 16:53:51 by eenasalorin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char *check_path(char *s1, char *s2)
{
	char 		*tmp;
	char		*path;
	struct stat buf;

	tmp = ft_strjoin(s1, "/");
	path = ft_strjoin(tmp, s2);
	ft_strdel(&tmp);
	if (lstat(path, &buf) == 0)
		return (path);
	ft_strdel(&path);
	return (NULL);
}

static char	*find_path(char **args, t_sh *sh)
{
	char	**bin;
	char	*path;
	int		i;

	i = -1;
	path = NULL;
	while (sh->env[++i])
	{
		if (ft_strncmp("PATH=", sh->env[i], 5) == 0)
		{
			bin = ft_strsplit(&sh->env[i][5], ':');
			i = 0;
			while (bin[i])
			{
				if ((path = check_path(bin[i++], args[0])))
					break ;
			}
			ft_arraydel(bin);
			break ;
		}
	}
	return (path);
}

static int	sh_exec(char **args, t_sh *sh)
{
    pid_t	pid;
	char	*path;

	path = find_path(args, sh);
	pid = fork();
	if (pid == 0)
	{
		if (execve(((path) ? path : args[0]), args, sh->env) == -1)
			error("minishell: invalid command: ", args[0]);
		exit(1);
	}
	else if (pid > 0)
		wait(NULL);
	else
		ft_putendl_fd("minishell: fork failed", 2);
	ft_strdel(&path);
	return (1);
}

int			sh_commands(char **args, t_sh *sh)
{
	int				i;
	static char		**builtin;
    
	i = 0;
	if (!builtin)
		builtin = make_builtin();
	if (!args[0])
		return (1);
	while (builtin && builtin[i])
	{
		if (ft_strcmp(args[0], builtin[i]) == 0)
		{
			if (i == 0)
				exit(1);
			return (builtin_func(args, i, sh));
		}
		i++;
	}
	return (sh_exec(args, sh));
}

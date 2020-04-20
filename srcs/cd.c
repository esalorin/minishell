/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 19:27:17 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/04/20 14:37:23 by eenasalorin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	modify_pwd(char **env, char *old, char *new)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!old || !new)
	{
		ft_putendl_fd("minishell: error updating environment variables", 2);
		return ;
	}
	while (env[i] && (ft_strncmp("PWD=", env[i], 4) != 0))
		i++;
	while (env[j] && (ft_strncmp("OLDPWD=", env[j], 7) != 0))
		j++;
	(!env[j]) ? 0 : ft_strdel(&env[j]);
	env[j] = ft_strjoin("OLDPWD=", old);
	(!env[i]) ? 0 : ft_strdel(&env[i]);
	env[i] = ft_strjoin("PWD=", new);
}

void		sh_cd(t_sh *sh)
{
	char	*pwd;
	char	*new;

	pwd = NULL;
	new = NULL;
	if (sh->args[1] == NULL)
		ft_putstr_fd("cd: expected argument after command\n", 2);
	else if (sh->args[2])
		error("cd: string not in pwd: ", sh->args[1]);
	else
	{
		pwd = getcwd(pwd, 1);
		if (ft_strcmp(sh->args[1], "-") == 0 && pwd)
			ft_printf("%s\n", pwd);
		else if (ft_strcmp(sh->args[1], "-") == 0 && !pwd)
			ft_putendl_fd("cd: error occured", 2);
		else if (chdir(sh->args[1]) != -1)
		{
			modify_pwd(sh->env, pwd, getcwd(new, 1));
			(new) ? ft_strdel(&new) : 0;
		}
		else
			error("cd: no such directory: ", sh->args[1]);
		(pwd) ? ft_strdel(&pwd) : 0;
	}
}

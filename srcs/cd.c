/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 19:27:17 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/05/02 16:43:33 by eenasalorin      ###   ########.fr       */
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
		ft_putendl_fd("minishell: error while updating env", 2);
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
	char	*home;

	pwd = NULL;
	new = NULL;
	home = checkhome(sh->env);
	if (ft_arraylen(sh->args) > 2)
		error("cd: string not in pwd: ", sh->args[1]);
	else if (home || sh->args[1])
	{
		pwd = getcwd(pwd, 1);
		if (sh->args[1] && ft_strcmp(sh->args[1], "-") == 0 && pwd)
			ft_printf("%s\n", pwd);
		else if (sh->args[1] && ft_strcmp(sh->args[1], "-") == 0 && !pwd)
			ft_putendl_fd("cd: error occured", 2);
		else if (chdir((sh->args[1]) ? sh->args[1] : home) != -1)
		{
			modify_pwd(sh->env, pwd, getcwd(new, 1));
			(new) ? ft_strdel(&new) : 0;
		}
		else if (sh->args[1])
			error("cd: no such directory: ", sh->args[1]);
		(pwd) ? ft_strdel(&pwd) : 0;
	}
}

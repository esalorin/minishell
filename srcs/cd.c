/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 19:27:17 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/03/26 16:36:57 by eenasalorin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	modify_pwd(t_sh *sh, char *old, char *new)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!old || !new)
	{
        ft_putendl_fd("minishell: error when updating environment variables", 2);
		return ;
	}
	while (sh->env[i] && (ft_strncmp("PWD=", sh->env[i], 4) != 0))
		i++;
	while (sh->env[j] && (ft_strncmp("OLDPWD=", sh->env[j], 7) != 0))
		j++;
	(!sh->env[j]) ? 0 : ft_strdel(&sh->env[j]);
	sh->env[j] = ft_strjoin("OLDPWD=", old);
	(!sh->env[i]) ? 0 : ft_strdel(&sh->env[i]);
	sh->env[i] = ft_strjoin("PWD=", new);
}

void  	  sh_cd(char **args, t_sh *sh)
{
    char    *pwd;
	char	*new;
    
	pwd = NULL;
	new = NULL;
    if (args[1] == NULL)
        ft_putstr_fd("cd: expected argument after command\n", 2);
    else if (args[2])
        error("cd: string not in pwd: ", args[1]);
    else
    {
		pwd = getcwd(pwd, 1);
        if (ft_strcmp(args[1], "-") == 0 && pwd)
            ft_printf("%s\n", pwd);
		else if (ft_strcmp(args[1], "-") == 0 && !pwd)
			ft_putendl_fd("cd: error occured", 2);
        else if (chdir(args[1]) != -1)
        {
            modify_pwd(sh, pwd, getcwd(new, 1));
			(new) ? ft_strdel(&new) : 0;
        }
        else
            error("cd: no such directory: ", args[1]);
		(pwd) ? ft_strdel(&pwd) : 0;
	}
}

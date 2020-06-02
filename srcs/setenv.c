/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 15:13:08 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/06/02 18:15:34 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_new_variable(t_sh *sh, char *tmp)
{
	char	**envcpy;
	char	*newvar;

	newvar = ft_strjoin(tmp, sh->args[2]);
	envcpy = ft_array_push(sh->env, newvar, -1);
	ft_arraydel(sh->env);
	ft_strdel(&newvar);
	sh->env = envcpy;
}

void		sh_setenv(t_sh *sh)
{
	char	*tmp;
	int		i;

	if (ft_arraylen(sh->args) != 3)
		ft_putendl_fd("usage: setenv [variable name] [value]", 2);
	else
	{
		tmp = ft_strjoin(sh->args[1], "=");
		i = 0;
		while (sh->env[i])
		{
			if (ft_strncmp(sh->env[i], tmp, ft_strlen(tmp)) == 0)
			{
				ft_strdel(&sh->env[i]);
				sh->env[i] = ft_strjoin(tmp, sh->args[2]);
				break ;
			}
			i++;
		}
		if (!sh->env[i])
			set_new_variable(sh, tmp);
		ft_strdel(&tmp);
	}
}

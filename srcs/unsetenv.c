/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 15:13:26 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/06/02 18:05:44 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		sh_unsetenv(t_sh *sh)
{
	char	**new;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	(!sh->args[1]) ? ft_putendl_fd("unsetenv: not enough arguments", 2) : 0;
	while (sh->args[++i])
	{
		j = 0;
		tmp = ft_strjoin(sh->args[i], "=");
		while (sh->env[j])
		{
			if (ft_strncmp(sh->env[j], tmp, ft_strlen(tmp)) == 0)
			{
				new = ft_arrayrem(sh->env, j);
				ft_arraydel(sh->env);
				sh->env = new;
				break ;
			}
			j++;
		}
		ft_strdel(&tmp);
	}
}

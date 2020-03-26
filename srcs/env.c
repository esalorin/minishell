/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 19:58:21 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/03/26 16:51:07 by eenasalorin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	sh_unsetenv(char **args, t_sh *sh)
{
	char	**new;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	(!args[1]) ? ft_putendl_fd("unset: not enough arguments", 2) : 0;
	while (args[++i])
	{
		j = 0;
		tmp = ft_strjoin(args[i], "=");
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

void	sh_env(char **args, t_sh *sh)
{
	if (args[0] && !args[1])
		ft_putarray(sh->env);
}

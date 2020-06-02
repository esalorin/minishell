/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_home_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 14:32:16 by esalorin          #+#    #+#             */
/*   Updated: 2020/06/02 14:32:41 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*checkhome(char **env)
{
	int		i;
	char	*home;

	i = 0;
	home = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], "HOME=", 5) == 0)
		{
			return (&env[i][5]);
		}
		i++;
	}
	return (home);
}

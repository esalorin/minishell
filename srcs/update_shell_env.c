/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_shell_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 13:44:57 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/06/02 16:15:41 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_shell_env(char *av, t_sh *sh)
{
	int		i;
	char	*temp;
	char	*temp2;
	char	*temp3;

	i = 0;
	temp = NULL;
	while (sh->env[i])
	{
		if (ft_strncmp("SHELL=", sh->env[i], 6) == 0)
		{
			ft_strdel(&sh->env[i]);
			temp = getcwd(temp, 1);
			sh->env[i] = ft_strjoin("SHELL=", temp);
			ft_strdel(&temp);
			temp = ft_strchr(av, '/');
			temp2 = ft_strrchr(av, '/');
			temp3 = ft_strsub(temp, 0, ft_strlen(temp) - ft_strlen(temp2));
			temp = ft_joindel(temp3, ft_strjoin("/.", temp2));
			temp2 = ft_joindel(sh->env[i], temp);
			sh->env[i] = temp2;
		}
		i++;
	}
}

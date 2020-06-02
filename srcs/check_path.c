/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 14:56:48 by esalorin          #+#    #+#             */
/*   Updated: 2020/06/02 14:57:10 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*check_path(char *s1, char *s2)
{
	char		*tmp;
	char		*path;

	tmp = ft_strjoin(s1, "/");
	path = ft_strjoin(tmp, s2);
	ft_strdel(&tmp);
	if (access(path, F_OK) == 0)
		return (path);
	ft_strdel(&path);
	return (NULL);
}

char		*find_path(t_sh *sh)
{
	char	**bin;
	char	*path;
	int		i;

	i = 0;
	path = NULL;
	while (sh->env[i])
	{
		if (ft_strncmp("PATH=", sh->env[i], 5) == 0)
		{
			bin = ft_strsplit(&sh->env[i][5], ':');
			i = 0;
			while (bin[i])
			{
				if ((path = check_path(bin[i++], sh->args[0])))
					break ;
			}
			ft_arraydel(bin);
			break ;
		}
		i++;
	}
	return (path);
}

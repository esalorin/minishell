/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escapes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 17:11:15 by esalorin          #+#    #+#             */
/*   Updated: 2020/06/02 17:26:50 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_rmescapes(char *s)
{
	char	*des;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (s && s[++i])
		j += (s[i] == BSLASH && s[i + 1] != BSLASH) ? 1 : 0;
	if (!(des = (char*)malloc(sizeof(char) * (ft_strlen(s) - j))))
		return (NULL);
	i = 0;
	j = 0;
	while (s && s[i])
	{
		if (s[i] != BSLASH || (s[i] == BSLASH && s[i + 1] == BSLASH))
			des[j++] = s[i];
		i += (s[i] == BSLASH && s[i + 1] == BSLASH) ? 2 : 1;
	}
	des[j] = '\0';
	return (des);
}

char		**escapes(char **array)
{
	int		i;
	char	*tmp;

	i = 0;
	while (array && array[i])
	{
		tmp = ft_rmescapes(array[i]);
		ft_strdel(&array[i]);
		array[i++] = tmp;
	}
	return (array);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape_inside_quotes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 17:18:47 by esalorin          #+#    #+#             */
/*   Updated: 2020/06/02 17:31:47 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_rmescapes_inquotes(char *s, char c)
{
	char	*des;
	int		i;
	int		j;

	if (!(des = ft_strnew(ft_strlen(s))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == BSLASH && (!count_bslash(s, i) || (s[i + 1] == DQUOTE
		&& c == DQUOTE)))
			i++;
		else
			des[j++] = s[i++];
	}
	des[j] = '\0';
	ft_strdel(&s);
	return (des);
}

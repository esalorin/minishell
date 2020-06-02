/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joindel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 15:03:40 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/06/02 16:28:17 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_joindel(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	new = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (new == NULL)
		return (NULL);
	while (s1 && s1[i] != '\0')
		new[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i] != '\0')
		new[j++] = s2[i++];
	new[j] = '\0';
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (new);
}

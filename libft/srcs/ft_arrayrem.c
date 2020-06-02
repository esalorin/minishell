/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayrem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 15:59:59 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/06/02 16:27:06 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrayrem(char **array, int index)
{
	char	**des;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = 0;
	while (array && array[len])
		len++;
	des = (char**)malloc(sizeof(char*) * len);
	while (array && i < (len - 1))
	{
		if (j == index)
			j++;
		des[i++] = ft_strdup(array[j++]);
	}
	des[i] = 0;
	return (des);
}

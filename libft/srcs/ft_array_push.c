/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 18:47:01 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/04/07 18:15:23 by eenasalorin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_array_push(char **array, char *str, int index)
{
	char	**des;
	int		i;
	int		j;
    
	i = 0;
	j = 0;
	while (array[i])
		i++;
	des = (char**)malloc(sizeof(char*) * (i + 2));
	i = 0;
	while (array[j])
	{
		if (i == index)
			des[i++] = ft_strdup(str);
		else
			des[i++] = ft_strdup(array[j++]);
	}
	if (index == -1 || index >= i)
		des[i++] = ft_strdup(str);
	des[i] = 0;
	return (des);
}

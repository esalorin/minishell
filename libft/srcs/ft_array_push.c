/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 18:47:01 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/03/21 14:19:59 by eenasalorin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_array_push(char **array, char *str)
{
	char	**des;
	int		i;
    
	i = 0;
	while (array[i])
		i++;
	des = (char**)malloc(sizeof(char*) * (i + 2));
	i = 0;
	while (array[i])
	{
		des[i] = ft_strdup(array[i]);
		i++;
	}
	des[i++] = ft_strdup(str);
	des[i] = 0;
	return (des);
}

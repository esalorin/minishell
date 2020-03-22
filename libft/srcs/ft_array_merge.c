/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_merge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 14:18:24 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/03/21 18:12:54 by eenasalorin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_array_merge(char **ar1, char **ar2)
{
	char	**des;
	int		i;
	int		j;
    
	i = 0;
    j = 0;
	while (ar1[i])
		i++;
    while (ar2[j])
		j++;
	des = (char**)malloc(sizeof(char*) * (i + j + 1));
	i = 0;
    j = 0;
	while (ar1[i])
		des[j++] = ft_strdup(ar1[i++]);
    i = 0;
    while (ar2[i])
		des[j++] = ft_strdup(ar2[i++]);
	des[j] = 0;
	return (des);
}

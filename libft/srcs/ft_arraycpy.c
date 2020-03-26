/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraycpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 20:26:19 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/03/25 20:27:51 by eenasalorin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arraycpy(char **array)
{
	char	**des;
	int		i;
    
	i = 0;
	while (array[i])
		i++;
	des = (char**)malloc(sizeof(char*) * (i + 1));
	i = 0;
	while (array[i])
    {
	    des[i] = ft_strdup(array[i]);
        i++;
    }
	des[i] = 0;
	return (des);
}

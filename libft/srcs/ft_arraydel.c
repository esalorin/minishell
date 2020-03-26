/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 19:08:00 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/03/24 17:26:12 by eenasalorin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arraydel(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		ft_strdel(&array[i++]);
	free(array);
	array = NULL;
}

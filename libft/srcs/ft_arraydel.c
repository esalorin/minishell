/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 19:08:00 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/06/02 16:23:27 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arraydel(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
		ft_strdel(&array[i++]);
	if (array)
	{
		free(array);
		array = NULL;
	}
}

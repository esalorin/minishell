/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 16:21:29 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/06/02 16:29:02 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putarray(char **array)
{
	int i;

	i = 0;
	while (array && array[i])
	{
		ft_printf("%s\n", array[i]);
		i++;
	}
}

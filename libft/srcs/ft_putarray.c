/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 16:21:29 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/03/21 17:26:16 by eenasalorin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putarray(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		write(1, array[i], ft_strlen(array[i]));
		write(1, "\n", 1);
		i++;
	}
}

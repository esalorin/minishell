/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfound.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 18:26:14 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/06/02 16:30:55 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strfound(const char *haystack, const char *needle)
{
	int i;
	int a;

	i = 0;
	a = 0;
	if (!needle || !*needle)
		return (0);
	while (haystack[i] != '\0')
	{
		while (haystack[i + a] == needle[a])
		{
			a++;
			if (needle[a] == '\0')
				return (1);
		}
		a = 0;
		i++;
	}
	return (0);
}

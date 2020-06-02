/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:59:14 by esalorin          #+#    #+#             */
/*   Updated: 2020/06/02 16:34:03 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int a;

	i = 0;
	a = 0;
	if (!needle || !haystack || !*needle)
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		while (haystack[i + a] == needle[a])
		{
			a++;
			if (needle[a] == '\0')
				return ((char*)haystack + i);
		}
		a = 0;
		i++;
	}
	return (NULL);
}

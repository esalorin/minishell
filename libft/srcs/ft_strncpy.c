/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:41:32 by esalorin          #+#    #+#             */
/*   Updated: 2020/06/02 16:33:25 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (i < len && dst && src && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	while (dst && i < len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}

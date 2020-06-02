/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 13:42:31 by esalorin          #+#    #+#             */
/*   Updated: 2020/06/02 16:33:17 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t len1;
	size_t len2;
	size_t i;
	size_t j;

	i = 0;
	len1 = ft_strlen(dst);
	len2 = ft_strlen(src);
	j = len1;
	if (dstsize == 0 || dstsize < len1)
		return (dstsize + len2);
	while (j < (dstsize - 1) && src && src[i] != '\0')
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (len1 + len2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:10:35 by esalorin          #+#    #+#             */
/*   Updated: 2020/06/02 16:34:54 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_cpy(char *dst, char const *src, int j, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		dst[i++] = src[j++];
	}
	dst[i] = '\0';
}

static int	ft_len(char const *s, char c, int j)
{
	int count;

	count = 0;
	while (s[j] != c && s[j] != '\0')
	{
		j++;
		count++;
	}
	return (count);
}

static int	ft_count(char *s, char c)
{
	int i;
	int count;

	i = 0;
	if (s && s[i] != c && s[i] != '\0')
		count = 1;
	else
		count = 0;
	while (s && s[i] != '\0')
	{
		while (s[i] == c)
		{
			i++;
			if (s[i] != c && s[i] != '\0')
				count++;
		}
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		len;
	int		words;
	char	**array;

	i = 0;
	j = 0;
	words = ft_count((char*)s, c);
	array = (char **)malloc(sizeof(char*) * words + 1);
	if (array == NULL)
		return (NULL);
	while (i < words)
	{
		while (s[j] == c && s[j] != '\0')
			j++;
		len = ft_len(s, c, j);
		array[i] = (char *)malloc(sizeof(char) * len + 1);
		ft_cpy(array[i], s, j, len);
		j = j + len;
		i++;
	}
	array[i] = 0;
	return (array);
}

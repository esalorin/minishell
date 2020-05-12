/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 15:15:46 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/05/12 14:58:44 by eenasalorin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_rmescapes_inquotes(char *s, char c)
{
	char	*des;
	int		i;
	int		j;

	if (!(des = ft_strnew(ft_strlen(s))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == 92 && (!count_slash(s, i) || (s[i + 1] == 34 && c == 34)))
			i++;
		else
			des[j++] = s[i++];
	}
	des[j] = '\0';
	ft_strdel(&s);
	return (des);
}

int		if_escape(char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c && i > 0)
			count += (s[i - 1] == 92) ? 1 : 0;
		i++;
	}
	return (count);
}

int		count_slash(char *s, int i)
{
	int	count;

	count = 0;
	while (i-- != 0 && s[i] == 92)
		count++;
	return ((count % 2 == 0) ? 1 : 0);
}

int		quote_match(char *s)
{
	int		i;
	int		quotes;
	char	c;

	i = 0;
	quotes = 0;
	while (s[i])
	{
		if ((s[i] == 34 || s[i] == 39) && count_slash(s, i))
		{
			c = s[i];
			quotes = 1;
			while (s[++i])
			{
				if (s[i] == c && (c == 39 || (c == 34 && count_slash(s, i))))
				{
					quotes = 2;
					break ;
				}
			}
		}
		i += s[i] ? 1 : 0;
	}
	return ((quotes == 1) ? c : quotes);
}

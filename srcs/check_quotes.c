/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 16:36:54 by esalorin          #+#    #+#             */
/*   Updated: 2020/06/02 17:25:54 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	quote_match(char *s)
{
	int		i;
	int		quotes;
	char	c;

	i = 0;
	quotes = 0;
	while (s[i])
	{
		if ((s[i] == DQUOTE || s[i] == SQUOTE) && count_bslash(s, i))
		{
			c = s[i];
			quotes = 1;
			while (s[++i])
			{
				if (s[i] == c && (c == SQUOTE || (c == DQUOTE &&
				count_bslash(s, i))))
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

char		**check_if_quotes(char *s)
{
	char	*s1;
	char	*s2;
	char	*tmp;
	int		q;

	if ((q = quote_match(s)) == 0 && count_bslash(s, ft_strlen(s)))
		return (escapes(ft_strsplit(s, ' ')));
	s1 = ft_strdup(s);
	while (q % 2 != 0 || q == DQUOTE || q == SQUOTE || !count_bslash(s1,
	ft_strlen(s1)))
	{
		if (q == DQUOTE || q == SQUOTE)
			ft_printf((q == DQUOTE) ? "dquote" : "quote");
		ft_printf("> ");
		get_next_line(0, &tmp);
		(q == 2 || q == 0) && !tmp[0] ? ft_strdel(&tmp) : 0;
		if ((q == 2 || q == 0) && !tmp[0])
			break ;
		s2 = (q == 2 || q == 0) ? ft_strdup(tmp) :
		ft_strjoin("\n", tmp);
		ft_strdel(&tmp);
		s1 = ft_joindel(s1, s2);
		q = quote_match(s1);
	}
	return (split_args(s1));
}

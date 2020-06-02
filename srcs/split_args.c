/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 14:27:24 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/06/02 17:31:32 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**last_arg(char **array, char *s, int i, int j)
{
	char	**des;
	char	**temp;
	char	*tmp;

	tmp = ft_strsub(s, j, (i - j));
	temp = escapes(ft_strsplit(tmp, ' '));
	if (j > 1 && s[j - 2] != ' ')
	{
		array[ft_arraylen(array) - 1] = ft_joindel(array[ft_arraylen(array)
		- 1], ft_strdup(temp[0]));
		if (temp[1])
			des = ft_array_merge(array, ft_arrayrem(temp, 0));
		else
			des = array;
		ft_arraydel(temp);
	}
	else
		des = ft_array_merge(array, temp);
	ft_strdel(&tmp);
	return (des);
}

static char	**split_by_quotes(char **array, char *s, int *i, int *j)
{
	char	**ar1;
	char	**ar2;
	char	*temp;
	char	c;

	c = s[*i];
	temp = ft_strsub(s, *j, (*i - *j));
	ar1 = ft_strsplit(temp, ' ');
	ar2 = ft_array_merge(array, escapes(ar1));
	ft_strdel(&temp);
	*j = ++(*i);
	while (s[*i] != c || (s[*i] == c && c == DQUOTE && !count_bslash(s, *i)))
		(*i)++;
	temp = ft_rmescapes_inquotes(ft_strsub(s, *j, (*i - *j)), c);
	if (*j > 1 && s[*j - 2] != ' ')
	{
		*j = *i + 1;
		ar2[ft_arraylen(ar2) - 1] = ft_joindel(ar2[ft_arraylen(ar2) - 1], temp);
		return (ar2);
	}
	*j = *i + 1;
	ar1 = ft_array_push(ar2, temp, -1);
	ft_strdel(&temp);
	ft_arraydel(ar2);
	return (ar1);
}

char		**split_args(char *s)
{
	char	**temp;
	char	**array;
	int		j;
	int		i;

	i = 0;
	j = 0;
	array = ft_arraynew(0);
	while (1)
	{
		if ((s[i] == DQUOTE || s[i] == SQUOTE) && count_bslash(s, i))
		{
			temp = split_by_quotes(array, s, &i, &j);
			array = temp;
		}
		else if (s[i] == '\0')
		{
			temp = last_arg(array, s, i, j);
			array = temp;
			break ;
		}
		i++;
	}
	ft_strdel(&s);
	return (array);
}

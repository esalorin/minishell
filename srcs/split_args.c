/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 14:27:24 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/04/02 14:32:36 by eenasalorin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	**escapes(char **array)
{
	int		i;
	char	*tmp;

	i = 0;
	while (array[i])
	{
		tmp = ft_rmescapes(array[i]);
		ft_strdel(&array[i]);
		array[i++] = tmp;
	}
	return (array);
}

static char **last(char **array, char *s, int i, int j)
{
    char    **des;
    char    **temp;
    char    *tmp;

    tmp = ft_strsub(s, j, (i - j));
    temp = ft_strsplit(tmp, ' ');
    des = ft_array_merge(array, escapes(temp));
	ft_strdel(&tmp);
    return (des);
}

static char **quotes(char **array, char *s, int *i, int *j)
{
    char        **ar1;
    char        **ar2;
    char        *temp;
	char		c;

	c = s[*i];
    temp = ft_strsub(s, *j, (*i - *j));
	ar1 = ft_strsplit(temp, ' ');
	ar2 = ft_array_merge(array, escapes(ar1));
	ft_strdel(&temp);
    *j = ++(*i);
    while (s[*i] != c || (s[*i] == c && c == 34 && !count_slash(s, *i)))
        (*i)++;
    temp = ft_rmescapes_inquotes(ft_strsub(s, *j, (*i - *j)), c);
	if (*j > 1 && ft_isprint(s[*j - 2]))
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

static char	**split_args(char *s)
{
	char	**temp;
	char	**array;
    int     j;
	int		i;

	i = 0;
    j = 0;
    array = ft_arraynew(0);
	while (1)
	{
        if ((s[i] == 34 || s[i] == 39) && count_slash(s, i))
        {
            temp = quotes(array, s, &i, &j);
            array = temp;
        }
        else if (s[i] == '\0')
        {
            temp = last(array, s, i, j);
            array = temp;
			break ;
        }
        i++;
	}
    ft_strdel(&s);
	return (array);
}

char  	  **check_if_quotes(char *s)
{
	char    *s1;
	char	*s2;
	char	*tmp;
	int		quotes;

	quotes = quote_match(s);
	if (quotes == 0 && count_slash(s, ft_strlen(s)))
		return (escapes(ft_strsplit(s, ' ')));
    s1 = ft_strdup(s);
	while (quotes % 2 != 0 || !count_slash(s1, ft_strlen(s1)))
	{
		ft_printf((quotes == 2 || quotes == 0) ? ">" : "dquote> ");
		get_next_line(0, &tmp);
		if ((quotes == 2 || quotes == 0) && !tmp[0])
		{
			ft_strdel(&tmp);
			break;
		}
		s2 = (quotes == 2 || quotes == 0) ? ft_strdup(tmp) : ft_strjoin("\n", tmp);
		ft_strdel(&tmp);
		s1 = ft_joindel(s1, s2);
		quotes = quote_match(s1);
	}
	return (split_args(s1));
}

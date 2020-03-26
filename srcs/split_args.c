/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 14:27:24 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/03/22 19:39:47 by eenasalorin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char **last(char **array, char *s, int i, int j)
{
    char    **des;
    char    **temp;
    char    *tmp;

    tmp = ft_strsub(s, j, (i - j));
    temp = ft_strsplit(tmp, ' ');
    des = ft_array_merge(array, temp);
    ft_arraydel(array);
    ft_arraydel(temp); 
    ft_strdel(&tmp);
    return (des);
}

static char **quotes(char **array, char *s, int *i, int *j)
{
    char        **ar1;
    char        **ar2;
    char        **ar3;
    char        *temp;

    temp = ft_strsub(s, *j, (*i - *j));
    ar1 = ft_strsplit(temp, ' ');
    ar2 = ft_array_merge(array, ar1);
    ft_strdel(&temp);
    ft_arraydel(ar1);
    *j = (*i)++;
    while (s[*i] != 34)
        (*i)++;
    temp = ft_strsub(s, *j, (*i - *j));
    *j = *i + 1;
    ar3 = ft_strsplit(temp, 34);
    ar1 = ft_array_merge(ar2, ar3);
    ft_strdel(&temp);
    ft_arraydel(ar3);
    ft_arraydel(ar2);
    ft_arraydel(array);
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
        if (s[i] == 34)
        {
            temp = quotes(array, s, &i, &j);
            array = temp;
        }
        else if (s[i] == '\0')
        {
            temp = last(array, s, i, j);
            ft_strdel(&s);
            return (temp);
        }
        i++;
	}
    ft_strdel(&s);
	return (array);
}

char  	  **check_if_string(char *s)
{
	char    *s1;
	char	*s2;
	char	*tmp;
	int		count;

	count = ft_chrcount(s, 34);
    s1 = ft_strdup(s);
	if (count == 0)
		return (ft_strsplit(s, ' '));
	if (count % 2 == 0)
		return (split_args(s1));
	while (count % 2 != 0)
	{
		ft_printf("dquote> ");
		get_next_line(0, &tmp);
		s2 = ft_strjoin("\n", tmp);
		ft_strdel(&tmp);
		tmp = ft_strjoin(s1, s2);
		ft_strdel(&s1);
        ft_strdel(&s2);
		s1 = tmp;
		count = ft_chrcount(s1, 34);
	}
	return (split_args(s1));
}

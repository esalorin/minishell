/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 14:46:14 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/06/02 16:08:01 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*tilde(char *arg, char *home)
{
	char	*des;

	if (!arg[1] || arg[1] == '/')
	{
		des = ft_strjoin(home, &arg[1]);
		return (des);
	}
	error("minishell: no such user or named directory: ", &arg[1]);
	return (0);
}

static char	*env_variable(char *arg, char **env, char *exp)
{
	int		i;
	int		j;
	char	*s1;
	char	*s2;
	char	*des;

	i = 0;
	des = NULL;
	while (arg[i] && arg[i] != '$')
		i++;
	s1 = ft_strsub(arg, 0, i);
	j = 1;
	while (exp[j] && exp[j] != '$')
		j++;
	s2 = ft_joindel(ft_strsub(exp, 1, j - 1), ft_strdup("="));
	i = 0;
	while (env[i] && (ft_strncmp(env[i], s2, j) != 0))
		i++;
	if (env[i])
		des = ft_joindel(s1, ft_strdup(&env[i][j]));
	if (exp[j])
		des = ft_joindel((des) ? des : s1, ft_strdup(&exp[j]));
	ft_strdel(&s2);
	return ((des) ? des : s1);
}

int			expansions(t_sh *sh)
{
	int		i;
	char	*tmp;
	char	*exp;

	i = 0;
	while (sh->args[i])
	{
		if ((exp = ft_strchr(sh->args[i], '$')))
		{
			tmp = env_variable(sh->args[i], sh->env, exp);
			ft_strdel(&sh->args[i]);
			sh->args[i] = tmp;
		}
		else if (sh->args[i][0] == '~')
		{
			if (!(tmp = tilde(sh->args[i], checkhome(sh->env))))
				return (0);
			ft_strdel(&sh->args[i]);
			sh->args[i] = tmp;
		}
		else
			i++;
	}
	return (1);
}

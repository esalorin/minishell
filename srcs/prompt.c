/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 15:09:16 by esalorin          #+#    #+#             */
/*   Updated: 2020/06/02 15:09:33 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt(t_sh *sh)
{
	char	*pwd;
	char	*home;
	char	*dir;
	int		i;

	i = 0;
	pwd = getcwd(NULL, 1);
	if (pwd)
	{
		dir = ft_strrchr(pwd, '/');
		if ((home = checkhome(sh->env)))
		{
			if (ft_strcmp(pwd, home) == 0)
				dir = "~";
		}
		ft_printf(CBLUEB"%s%s $> %s", (ft_strlen(dir) > 1) ? ++dir : dir,
		CMAGENTAB, CRESET);
		ft_strdel(&pwd);
	}
	else
		ft_printf(CMAGENTAB"$> %s", CRESET);
}

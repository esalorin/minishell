/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_command_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 14:54:14 by esalorin          #+#    #+#             */
/*   Updated: 2020/06/02 17:47:22 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			sh_commands(t_sh *sh)
{
	int				i;
	static char		**builtin;

	i = 0;
	if (!builtin && (!(builtin = make_builtin())))
	{
		ft_putendl_fd("malloc(): failed allocating memory", 2);
		return (1);
	}
	if (!sh->args[0])
		return (1);
	while (builtin[i])
	{
		if (ft_strcmp(sh->args[0], builtin[i]) == 0)
			return (builtin_functions(i, sh));
		i++;
	}
	return (sh_exec(sh));
}

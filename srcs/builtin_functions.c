/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 19:07:37 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/06/02 17:48:24 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		builtin_functions(int i, t_sh *sh)
{
	if (i == 0)
		exit(1);
	if (i == 1)
		sh_cd(sh);
	else if (i == 2)
		sh_echo(sh);
	else if (i == 3)
		sh_env(sh);
	else if (i == 4)
		sh_setenv(sh);
	else if (i == 5)
		sh_unsetenv(sh);
	return (1);
}

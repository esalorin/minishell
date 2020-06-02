/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 19:58:21 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/06/02 18:05:12 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		sh_env(t_sh *sh)
{
	if (ft_arraylen(sh->args) == 1)
		ft_putarray(sh->env);
	else
		ft_putendl_fd("env: too many arguments", 2);
}

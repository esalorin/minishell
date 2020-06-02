/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 14:29:43 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/06/02 16:34:42 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sh_echo(t_sh *sh)
{
	int i;

	i = 1;
	while (sh->args[i])
	{
		if (i > 1 && sh->args[i - 1][0])
			ft_putchar(' ');
		ft_printf("%s", sh->args[i++]);
	}
	ft_putchar('\n');
}

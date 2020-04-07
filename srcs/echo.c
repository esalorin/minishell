/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 20:08:34 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/04/02 18:55:47 by eenasalorin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void  		sh_echo(t_sh *sh)
{
	int i;

	i = 1;
	while (sh->args[i])
	{
		if (i > 1 && sh->args[i - 1][0])
			ft_putchar(' ');
		ft_putstr(sh->args[i++]);
	}
	ft_putchar('\n');
}

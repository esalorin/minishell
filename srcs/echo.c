/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 20:08:34 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/03/21 14:27:58 by eenasalorin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void  		sh_echo(char **args)
{
	int i;

	i = 1;
	while (args[i])
	{
		if (i > 1)
			ft_putchar(' ');
		ft_putstr(args[i++]);
	}
	ft_putchar('\n');
}

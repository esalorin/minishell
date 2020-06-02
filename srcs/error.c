/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 17:35:12 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/06/01 16:17:09 by eenasalorin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error(char *s1, char *s2)
{
	ft_putstr_fd(s1, 2);
	ft_putstr_fd(s2, 2);
	ft_putchar_fd('\n', 2);
}

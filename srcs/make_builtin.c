/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 17:45:34 by esalorin          #+#    #+#             */
/*   Updated: 2020/06/02 17:45:53 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**make_builtin(void)
{
	char	**des;

	if (!(des = (char**)malloc(sizeof(char*) * 7)))
		return (NULL);
	des[0] = ft_strdup("exit");
	des[1] = ft_strdup("cd");
	des[2] = ft_strdup("echo");
	des[3] = ft_strdup("env");
	des[4] = ft_strdup("setenv");
	des[5] = ft_strdup("unsetenv");
	des[6] = 0;
	return (des);
}

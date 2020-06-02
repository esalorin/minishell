/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_bslash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 17:23:38 by esalorin          #+#    #+#             */
/*   Updated: 2020/06/02 17:24:02 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		count_bslash(char *s, int i)
{
	int	count;

	count = 0;
	while (i-- != 0 && s[i] == BSLASH)
		count++;
	return ((count % 2 == 0) ? 1 : 0);
}

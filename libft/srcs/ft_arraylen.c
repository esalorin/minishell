/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraylen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 16:27:07 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/04/01 16:28:15 by eenasalorin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_arraylen(char **array)
{
    size_t i;

    i = 0;
    while (array[i])
        i++;
    return (i);
}

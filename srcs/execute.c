/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 17:59:23 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/03/21 18:49:04 by eenasalorin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


int sh_execute(char **args)
{
    int             i;
    static char    **builtin;
    
    i = 0;
    if (!builtin)
        builtin = make_builtin();
    if (!args[0])
        return (1);
    while (builtin && builtin[i])
    {
        if (ft_strcmp(args[0], builtin[i]) == 0)
        {
            if (i == 0)
                return (0);
            return (builtin_func(args, i));
        }
        i++;
    }
    error("minishell: invalid command: ", args[0]);
    return (1);
}

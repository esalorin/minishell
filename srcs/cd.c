/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 19:27:17 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/03/20 17:40:55 by eenasalorin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    sh_cd(char **args)
{
    if (args[1] == NULL)
        ft_putstr_fd("cd: expected argument after command\n", 2);
    else if (chdir(args[1]) == -1)
        error("cd: no such directory: ", args[1]);
}

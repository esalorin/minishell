/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 17:59:23 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/06/02 17:59:00 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			sh_exec(t_sh *sh)
{
	pid_t	pid;
	char	*path;

	path = find_path(sh);
	pid = fork();
	if (pid == 0)
	{
		if (execve(((path) ? path : sh->args[0]), sh->args, sh->env) == -1)
			error("minishell: invalid command: ", sh->args[0]);
		exit(1);
	}
	else if (pid > 0)
		wait(NULL);
	else
		ft_putendl_fd("fork(): an error occurred, please try again later", 2);
	(path) ? ft_strdel(&path) : 0;
	return (1);
}

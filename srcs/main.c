/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 16:56:25 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/06/02 18:37:06 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	sh_loop(t_sh *sh)
{
	char	*line;
	int		status;

	status = 1;
	while (status)
	{
		prompt(sh);
		if (get_next_line(0, &line))
		{
			sh->args = check_if_quotes(line);
			if (expansions(sh))
				status = sh_commands(sh);
			ft_strdel(&line);
			ft_arraydel(sh->args);
		}
		else
			ft_putchar('\n');
	}
}

int			main(int ac, char **av, char **env)
{
	t_sh sh;

	if (ac && av[0])
	{
		sh.env = ft_arraydup(env);
		update_shell_env(av[0], &sh);
		sh_loop(&sh);
		ft_arraydel(sh.env);
	}
	return (0);
}

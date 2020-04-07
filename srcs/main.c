/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 16:56:25 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/04/02 18:10:00 by eenasalorin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    sh_loop(t_sh sh)
{
	char	*line;
	int		status;

	status = 1;
	while (status)
	{
		ft_printf("$> ");
		get_next_line(0, &line);
		sh.args = check_if_quotes(line);
		expansions(&sh);
		status = sh_commands(&sh);
		ft_strdel(&line);
		ft_arraydel(sh.args);
	}
}

int main(int ac, char **av, char **env)
{
	t_sh sh;
	
	if (ac && av[0])
	{
		sh.env = ft_arraydup(env);
		sh.home = savehome(sh.env);
		sh_loop(sh);
		ft_strdel(&sh.home);
		ft_arraydel(sh.env);
	}
	return (0);
}

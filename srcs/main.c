/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 16:56:25 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/03/26 13:54:55 by eenasalorin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    sh_loop(t_sh sh)
{
	char	*line;
	char	**args;
	int		status;

	status = 1;
	while (status)
	{
		ft_printf("$> ");
		get_next_line(0, &line);
		args = check_if_string(line);
		status = sh_commands(args, &sh);
		ft_strdel(&line);
		ft_arraydel(args);
	}
}

int main(int ac, char **av, char **env)
{
	t_sh sh;
	
	if (ac && av[0])
	{
		sh.env = ft_arraycpy(env);
		sh_loop(sh);
	}
	return (0);
}

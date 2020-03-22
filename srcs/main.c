/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 16:56:25 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/03/21 18:43:03 by eenasalorin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    sh_loop(void)
{
	char	*line;
	char	**args;
	int		status;

	status = 1;
	while (status)
	{
		ft_printf("$> ");
		get_next_line(0, &line);
		if (ft_strfound(line, "echo"))
			args = check_if_string(line);
		else
			args = ft_strsplit(line, ' ');
		status = sh_execute(args);
		free(line);
		ft_arraydel(args);
	}
}

int main(void)
{
	sh_loop();
	return (0);
}

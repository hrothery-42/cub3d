/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:51:26 by hrothery          #+#    #+#             */
/*   Updated: 2022/09/20 14:57:24 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

bool	check_file(int argc, char *argv)
{
	int	i;

	if (argc != 2)
	{
		ft_putstr_fd("Wrong number of arguments!  Please use the path to a cub file.\n", 2);
		return (1);
	}
	i = ft_strlen(argv) - 1;
	if (i < 4 || argv[i] != 'b' || argv[i - 1] != 'u' || argv[i - 2] != 'c'\
	|| argv[i - 3] != '.')
	{
		ft_putstr_fd("Error!  You need to use a .cub file.\n", 2);
		return (1);
	}
	return (0);
}

void	print_struct(t_values *vars)
{
	
}

int	main(int argc, char **argv)
{
	t_values	vars;
	
	if (check_file(argc, argv[1]) || parse_input(argv[1], &vars))
	{
		//run the program
	}
	ft_double_free(vars.map);
	return (0);
}

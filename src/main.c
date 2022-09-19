/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:51:26 by hrothery          #+#    #+#             */
/*   Updated: 2022/09/19 17:38:25 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	check_file(int argc, char *argv)
{
	int	i;

	if (argc != 2)
		return (printf("Error! Wrong number of arguments!\n"));
	i = ft_strlen(argv) - 1;
	if (i < 4 || argv[i] != 'b' || argv[i - 1] != 'u' || argv[i - 2] != 'c'\
	|| argv[i - 3] != '.')
		return (printf("Error! Use one .cub file!\n"));
	return (0);
}

int	main(int argc, char **argv)
{
	t_values	val;
	
	if (check_file(argc, argv[1]) || parse_input(argv[1], &val))
	{
		//free all memory, close mlx
		return (0);
	}
	return (0);
}

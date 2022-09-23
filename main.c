/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:09:17 by bvarlamo          #+#    #+#             */
/*   Updated: 2022/09/23 14:24:02 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	xclose(t_values *vars)
{
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	exit(0);
	return (0);
}

void	raycasting(t_values *vars)
{
	double	w;
	int		x;

	w = SCREENWIDTH;
	x = 0;
	while (x <= w)
	{
		vars->camerax = 2 * x / w - 1;
		raycast1(vars);
		raycast2(vars);
		raycast3(vars);
		raycast4(vars);
		raycast5(vars);
		drawwalls(x, vars);
		x++;
	}
}

int	init_mlx(t_values *vars)
{
	vars->mlx_ptr = mlx_init();
	if (vars->mlx_ptr == NULL)
		return (1);
	vars->win_ptr = mlx_new_window(vars->mlx_ptr, SCREENWIDTH,
			SCREENHEIGHT, "Cub3D");
	if (vars->win_ptr == NULL)
		return (1);
	vars->img_ptr = mlx_new_image(vars->mlx_ptr, SCREENWIDTH, SCREENHEIGHT);
	if (vars->img_ptr == NULL)
		return (1);
	vars->img = mlx_get_data_addr(vars->img_ptr, &vars->bits,
			&vars->line, &vars->end);
	if (vars->img == NULL)
		return (1);
	return (0);
}

bool	check_file(int argc, char *argv)
{
	int	i;

	if (argc != 2)
	{
		ft_putstr_fd("Error!\nWrong number of arguments!  Use a cub file.\n", 2);
		return (1);
	}
	i = ft_strlen(argv) - 1;
	if (i < 4 || argv[i] != 'b' || argv[i - 1] != 'u' || argv[i - 2] != 'c'\
	|| argv[i - 3] != '.')
	{
		ft_putstr_fd("Error!\nUse a .cub file.\n", 2);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_values		vars;

	if (check_file(argc, argv[1]))
		return (1);
	if (init_mlx(&vars))
	{
		ft_putstr_fd("Error!\nMLX not running.\n", 2);
		return (1);
	}
	if (!parse_input(argv[1], &vars))
	{
		mlx_hook(vars.win_ptr, 2, 0, keys, &vars);
		mlx_hook(vars.win_ptr, 17, 0, xclose, &vars);
		mlx_loop_hook(vars.mlx_ptr, test, &vars);
		mlx_loop(vars.mlx_ptr);
	}
	ft_double_free(vars.map);
	return (0);
}

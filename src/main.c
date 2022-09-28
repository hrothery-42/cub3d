/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:09:17 by bvarlamo          #+#    #+#             */
/*   Updated: 2022/09/28 09:43:00 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	free_everything(t_values *vars)
{
	int	i;

	i = 0;
	ft_double_free(vars->map);
	if (vars->img_ptr)
		mlx_destroy_image(vars->mlx_ptr, vars->img_ptr);
	i = 0;
	while (i < 4)
	{
		if (vars->pattern[i])
			free(vars->pattern[i]);
		if (vars->t_tex[i])
			mlx_destroy_image(vars->mlx_ptr, vars->t_tex[i]);
		i++;
	}
	if (vars->win_ptr)
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	free(vars->mlx_ptr);
	return (1);
}

int	main(int argc, char **argv)
{
	t_values		vars;

	if (check_file(argc, argv[1]))
		return (1);
	if (init_to_null(&vars) || parse_input(argv[1], &vars))
		return (free_map(&vars));
	if (init_mlx(&vars))
	{
		ft_putstr_fd("Error!\nMLX not running.\n", 2);
		return (free_everything(&vars));
	}
	if (textures(&vars))
		return (free_everything(&vars));
	mlx_hook(vars.win_ptr, 2, 0, keys, &vars);
	mlx_hook(vars.win_ptr, 17, 0, xclose, &vars);
	mlx_loop_hook(vars.mlx_ptr, test, &vars);
	mlx_loop(vars.mlx_ptr);
	free_everything(&vars);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:09:17 by bvarlamo          #+#    #+#             */
/*   Updated: 2022/09/22 14:19:49 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int worldMap[MAPWIDTH][MAPHEIGHT]=
{
  {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7},
  {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
  {4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
  {4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
  {4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
  {4,0,4,0,0,0,0,5,5,5,5,5,5,5,5,5,7,7,0,7,7,7,7,7},
  {4,0,5,0,0,0,0,5,0,5,0,5,0,5,0,5,7,0,0,0,7,7,7,1},
  {4,0,6,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
  {4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,1},
  {4,0,8,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
  {4,0,0,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,7,7,7,1},
  {4,0,0,0,0,0,0,5,5,5,5,0,5,5,5,5,7,7,7,7,7,7,7,1},
  {6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
  {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
  {6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
  {4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
  {4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2},
  {4,0,0,5,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
  {4,0,6,0,6,0,0,0,0,4,6,0,6,2,0,0,5,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
  {4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3}
};

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

int	init(t_values *vars)
{
	vars->pos.x = 22;
	vars->pos.y = 22;
	vars->dir.x = 0;
	vars->dir.y = 1;
	vars->plane.x = 0.66;
	vars->plane.y = 0;
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

int	main(void)
{
	t_values		vars;

	if (init(&vars))
		return (1);
	textures(&vars);
	mlx_hook(vars.win_ptr, 2, 0, keys, &vars);
	mlx_hook(vars.win_ptr, 17, 0, xclose, &vars);
	mlx_loop_hook(vars.mlx_ptr, test, &vars);
	mlx_loop(vars.mlx_ptr);
	return (0);
}

// ----At what side to look---
// dir.x=0 dir.y=-1 plane.x=-0.66 plane.y=0
// dir.x=-1 dir.y=0 plane.x=0 plane.y=0.66
// dir.x=1 dir.y=0 plane.x=0 plane.y=-0.66
// dir.x=0 dir.y=1 plane.x=0.66 plane.y=0

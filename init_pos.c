/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:42:24 by hrothery          #+#    #+#             */
/*   Updated: 2022/09/23 11:47:03 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_n(t_values *vars)
{
	vars->dir.x = 0; 
	vars->dir.y = 1;
	vars->plane.x = 0.66;
	vars->plane.y = 0;
}

void	init_s(t_values *vars)
{
	vars->dir.x = 0;
	vars->dir.y = -1;
	vars->plane.x = -0.66;
	vars->plane.y = 0;
}

void	init_e(t_values *vars)
{
	vars->dir.x = 1;
	vars->dir.y = 0;
	vars->plane.x = 0;
	vars->plane.y = -0.66;
}

void	init_w(t_values *vars)
{
	vars->dir.x = -1;
	vars->dir.y = 0;
	vars->plane.x = 0;
	vars->plane.y = 0.66;
}

void	init_pos_and_dir(char c, t_values *vars, int i, int j)
{
	vars->pos.x = i;
	vars->pos.y = j;
	if (c == 'N')
		init_n(vars);
	else if (c == 'S')
		init_s(vars);
	else if (c == 'W')
		init_w(vars);
	else if (c == 'E')
		init_e(vars);
}
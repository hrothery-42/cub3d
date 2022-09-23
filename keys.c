/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:54:42 by bvarlamo          #+#    #+#             */
/*   Updated: 2022/09/23 13:41:17 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	stepleft(t_values *vars)
{
	if (vars->map[(int)(vars->pos.x)][(int)(vars->pos.y + vars->dir.x * 0.65)] == '0')
			vars->pos.y += vars->dir.x * 0.65;
	if (vars->map[(int)(vars->pos.x + (-vars->dir.y * 0.65))][(int)(vars->pos.y)] == '0')
		vars->pos.x += -vars->dir.y * 0.65;
	return (0);
}

int	stepright(t_values *vars)
{
	if (vars->map[(int)(vars->pos.x)][(int)(vars->pos.y - vars->dir.x * 0.65)] == '0')
			vars->pos.y -= vars->dir.x * 0.65;
	if (vars->map[(int)(vars->pos.x - (-vars->dir.y * 0.65))][(int)(vars->pos.y)] == '0')
		vars->pos.x -= -vars->dir.y * 0.65;
	return (0);
}

int	turnleft(t_values *vars)
{
	vars->olddirx = vars->dir.x;
	vars->dir.x = vars->dir.x * cos(0.2) - vars->dir.y * sin(0.2);
	vars->dir.y = vars->olddirx * sin(0.2) + vars->dir.y * cos(0.2);
	vars->oldplanex = vars->plane.x;
	vars->plane.x = vars->plane.x * cos(0.2) - vars->plane.y * sin(0.2);
	vars->plane.y = vars->oldplanex * sin(0.2) + vars->plane.y * cos(0.2);
	return (0);
}

int	turnright(t_values *vars)
{
	vars->olddirx = vars->dir.x;
	vars->dir.x = vars->dir.x * cos(-0.2) - vars->dir.y * sin(-0.2);
	vars->dir.y = vars->olddirx * sin(-0.2) + vars->dir.y * cos(-0.2);
	vars->oldplanex = vars->plane.x;
	vars->plane.x = vars->plane.x * cos(-0.2) - vars->plane.y * sin(-0.2);
	vars->plane.y = vars->oldplanex * sin(-0.2) + vars->plane.y * cos(-0.2);
	return (0);
}

int	keys(int key, t_values *vars)
{
	if (key == 53)
		xclose(vars);
	else if (key == 13)
	{
		if (vars->map[(int)(vars->pos.x + vars->dir.x * 0.65)][(int)(vars->pos.y)] == '0')
			vars->pos.x += vars->dir.x * 0.65;
		if (vars->map[(int)(vars->pos.x)][(int)(vars->pos.y + vars->dir.y * 0.65)] == '0')
			vars->pos.y += vars->dir.y * 0.65;
	}
	else if (key == 1)
	{
		if (vars->map[(int)(vars->pos.x - vars->dir.x * 0.65)][(int)(vars->pos.y)] == '0')
			vars->pos.x -= vars->dir.x * 0.65;
		if (vars->map[(int)(vars->pos.x)][(int)(vars->pos.y - vars->dir.y * 0.65)] == '0')
			vars->pos.y -= vars->dir.y * 0.65;
	}
	else if (key == 0)
		stepleft(vars);
	else if (key == 2)
		stepright(vars);
	else if (key == 123)
		turnleft(vars);
	else if (key == 124)
		turnright(vars);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:54:42 by bvarlamo          #+#    #+#             */
/*   Updated: 2022/09/22 14:23:51 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	worldMapz[MAPWIDTH][MAPHEIGHT]=
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

int	stepleft(t_values *vars)
{
	if (!worldMapz[(int)(vars->pos.x)][(int)(vars->pos.y + vars->dir.x * 0.65)])
			vars->pos.y += vars->dir.x * 0.65;
	if (!worldMapz[(int)(vars->pos.x + (-vars->dir.y * 0.65))][(int)(vars->pos.y)])
		vars->pos.x += -vars->dir.y * 0.65;
	return (0);
}

int	stepright(t_values *vars)
{
	if (!worldMapz[(int)(vars->pos.x)][(int)(vars->pos.y - vars->dir.x * 0.65)])
			vars->pos.y -= vars->dir.x * 0.65;
	if (!worldMapz[(int)(vars->pos.x - (-vars->dir.y * 0.65))][(int)(vars->pos.y)])
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
		if (!worldMapz[(int)(vars->pos.x + vars->dir.x * 0.65)][(int)(vars->pos.y)])
			vars->pos.x += vars->dir.x * 0.65;
		if (!worldMapz[(int)(vars->pos.x)][(int)(vars->pos.y + vars->dir.y * 0.65)])
			vars->pos.y += vars->dir.y * 0.65;
	}
	else if (key == 1)
	{
		if (!worldMapz[(int)(vars->pos.x - vars->dir.x * 0.65)][(int)(vars->pos.y)])
			vars->pos.x -= vars->dir.x * 0.65;
		if (!worldMapz[(int)(vars->pos.x)][(int)(vars->pos.y - vars->dir.y * 0.65)])
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

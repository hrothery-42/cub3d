/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycastingHelpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:52:09 by bvarlamo          #+#    #+#             */
/*   Updated: 2022/09/22 14:19:42 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int worldMaps[MAPWIDTH][MAPHEIGHT]=
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

void	raycast1(t_values *vars)
{
	vars->ray.x = vars->dir.x + vars->plane.x * vars->camerax;
	vars->ray.y = vars->dir.y + vars->plane.y * vars->camerax;
	vars->map.x = (int)vars->pos.x;
	vars->map.y = (int)vars->pos.y;
	if (vars->ray.x == 0)
		vars->delta.x = 1e30;
	else
		vars->delta.x = fabs(1 / vars->ray.x);
	if (vars->ray.y == 0)
		vars->delta.y = 1e30;
	else
		vars->delta.y = fabs(1 / vars->ray.y);
	if (vars->ray.x < 0)
	{
		vars->step.x = -1;
		vars->side.x = (vars->pos.x - vars->map.x) * vars->delta.x;
	}
	else
	{
		vars->step.x = 1;
		vars->side.x = (vars->map.x + 1.0 - vars->pos.x) * vars->delta.x;
	}
}

void	raycast2(t_values *vars)
{
	if (vars->ray.y < 0)
	{
		vars->step.y = -1;
		vars->side.y = (vars->pos.y - vars->map.y) * vars->delta.y;
	}
	else
	{
		vars->step.y = 1;
		vars->side.y = (vars->map.y + 1.0 - vars->pos.y) * vars->delta.y;
	}
}

void	raycast3(t_values *vars)
{
	vars->hit = 0;
	while (vars->hit == 0)
	{
		if (vars->side.x < vars->side.y)
		{
			vars->side.x += vars->delta.x;
			vars->map.x += vars->step.x;
			vars->p_side = 0;
		}
		else
		{
			vars->side.y += vars->delta.y;
			vars->map.y += vars->step.y;
			vars->p_side = 1;
		}
		if (worldMaps[vars->map.x][vars->map.y] > 0)
			vars->hit = 1;
	}
}

void	raycast4(t_values *vars)
{
	if (vars->p_side == 0)
		vars->perpwalldist = (vars->side.x - vars->delta.x);
	else
		vars->perpwalldist = (vars->side.y - vars->delta.y);
	vars->h = SCREENHEIGHT;
	vars->lineheight = (int)(vars->h / vars->perpwalldist);
	vars->drawstart = -vars->lineheight / 2 + vars->h / 2;
	if (vars->drawstart < 0)
		vars->drawstart = 0;
	vars->drawend = vars->lineheight / 2 + vars->h / 2;
	if (vars->drawend >= vars->h)
		vars->drawend = vars->h - 1;
	if (vars->p_side == 1 && vars->map.y > (vars->map.y - vars->step.y))
		vars->texnum = 0;
	else if (vars->p_side == 1 && vars->map.y < (vars->map.y - vars->step.y))
		vars->texnum = 1;
	else if (vars->p_side == 0 && vars->map.x < (vars->map.x - vars->step.x))
		vars->texnum = 2;
	else if (vars->p_side == 0 && vars->map.x > (vars->map.x - vars->step.x))
		vars->texnum = 3;
	if (vars->p_side == 0)
		vars->wallx = vars->pos.y + vars->perpwalldist * vars->ray.y;
	else
		vars->wallx = vars->pos.x + vars->perpwalldist * vars->ray.x;
	vars->wallx -= floor((vars->wallx));
}

void	raycast5(t_values *vars)
{
	vars->tex.x = (int)(vars->wallx * (double)vars->height[vars->texnum]);
	if (vars->p_side == 0 && vars->ray.x > 0)
		vars->tex.x = vars->width[vars->texnum] - vars->tex.x - 1;
	if (vars->p_side == 1 && vars->ray.y < 0)
		vars->tex.x = vars->width[vars->texnum] - vars->tex.x - 1;
	vars->t_step = 1.0 * vars->height[vars->texnum] / vars->lineheight;
	vars->texpos = (vars->drawstart - vars->h / 2 + vars->lineheight / 2)
		* vars->t_step;
}

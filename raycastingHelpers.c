/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycastingHelpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:52:09 by bvarlamo          #+#    #+#             */
/*   Updated: 2022/09/21 16:20:46 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int worldMaps[mapWidth][mapHeight]=
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
	vars->rayDirX = vars->dirX + vars->planeX * vars->cameraX;
	vars->rayDirY = vars->dirY + vars->planeY * vars->cameraX;
	vars->mapX = (int)vars->posX;
	vars->mapY = (int)vars->posY;
	if (vars->rayDirX == 0)
		vars->deltaDistX = 1e30;
	else
		vars->deltaDistX = fabs(1 / vars->rayDirX);
	if (vars->rayDirY == 0)
		vars->deltaDistY = 1e30;
	else
		vars->deltaDistY = fabs(1 / vars->rayDirY);
	if (vars->rayDirX < 0)
	{
		vars->stepX = -1;
		vars->sideDistX = (vars->posX - vars->mapX) * vars->deltaDistX;
	}
	else
	{
		vars->stepX = 1;
		vars->sideDistX = (vars->mapX + 1.0 - vars->posX) * vars->deltaDistX;
	}
}

void	raycast2(t_values *vars)
{
	if (vars->rayDirY < 0)
	{
		vars->stepY = -1;
		vars->sideDistY = (vars->posY - vars->mapY) * vars->deltaDistY;
	}
	else
	{
		vars->stepY = 1;
		vars->sideDistY = (vars->mapY + 1.0 - vars->posY) * vars->deltaDistY;
	}
}

void	raycast3(t_values *vars)
{
	vars->hit = 0;
	while (vars->hit == 0)
	{
		if (vars->sideDistX < vars->sideDistY)
		{
			vars->sideDistX += vars->deltaDistX;
			vars->mapX += vars->stepX;
			vars->side = 0;
		}
		else
		{
			vars->sideDistY += vars->deltaDistY;
			vars->mapY += vars->stepY;
			vars->side = 1;
		}
		if (worldMaps[vars->mapX][vars->mapY] > 0)
			vars->hit = 1;
	}
}

void	raycast4(t_values *vars)
{
	if (vars->side == 0)
		vars->perpWallDist = (vars->sideDistX - vars->deltaDistX);
	else
		vars->perpWallDist = (vars->sideDistY - vars->deltaDistY);
	vars->h = screenHeight;
	vars->lineHeight = (int)(vars->h / vars->perpWallDist);
	vars->drawStart = -vars->lineHeight / 2 + vars->h / 2;
	if (vars->drawStart < 0)
		vars->drawStart = 0;
	vars->drawEnd = vars->lineHeight / 2 + vars->h / 2;
	if (vars->drawEnd >= vars->h)
		vars->drawEnd = vars->h - 1;
	if (vars->side == 1 && vars->mapY > (vars->mapY - vars->stepY))
		vars->texNum = 0;
	else if (vars->side == 1 && vars->mapY < (vars->mapY - vars->stepY))
		vars->texNum = 1;
	else if (vars->side == 0 && vars->mapX < (vars->mapX - vars->stepX))
		vars->texNum = 2;
	else if (vars->side == 0 && vars->mapX > (vars->mapX - vars->stepX))
		vars->texNum = 3;
	if (vars->side == 0)
		vars->wallX = vars->posY + vars->perpWallDist * vars->rayDirY;
	else
		vars->wallX = vars->posX + vars->perpWallDist * vars->rayDirX;
	vars->wallX -= floor((vars->wallX));
}

void	raycast5(t_values *vars)
{
	vars->texX = (int)(vars->wallX * (double)vars->height[vars->texNum]);
	if (vars->side == 0 && vars->rayDirX > 0)
		vars->texX = vars->width[vars->texNum] - vars->texX - 1;
	if (vars->side == 1 && vars->rayDirY < 0)
		vars->texX = vars->width[vars->texNum] - vars->texX - 1;
	vars->step = 1.0 * vars->height[vars->texNum] / vars->lineHeight;
	vars->texPos = (vars->drawStart - vars->h / 2 + vars->lineHeight / 2)
		* vars->step;
}

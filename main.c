/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:09:17 by bvarlamo          #+#    #+#             */
/*   Updated: 2022/09/19 15:26:49 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


#define mapWidth 24
#define mapHeight 24
#define screenWidth 800
#define screenHeight 600

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void	raycasting(t_values *vars)
{
	double	w;
	int		x;
	char	*pix;
	int		d;

	w = screenWidth;
	x = 0;
	while (x <= w)
	{
		vars->cameraX = 2 * x / w - 1;
		vars->rayDirX = vars->dirX + vars->planeX * vars->cameraX;
		vars->rayDirY = vars->dirY + vars->planeY * vars->cameraX;
		vars->mapX = (int)vars->posX;
		vars->mapY = (int)vars->posY;
		vars->deltaDistX = (vars->rayDirX == 0) ? 1e30 : fabs(1 / vars->rayDirX);
		vars->deltaDistY = (vars->rayDirY == 0) ? 1e30 : fabs(1 / vars->rayDirY);
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
			if (worldMap[vars->mapX][vars->mapY] > 0)
				vars->hit = 1;
		}
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
		if (worldMap[vars->mapX][vars->mapY] == 1)
			vars->color = 0xffffff;
		else if (worldMap[vars->mapX][vars->mapY] == 2)
			vars->color = 0x00FF00;
		else if (worldMap[vars->mapX][vars->mapY] == 3)
			vars->color = 0xe80c0c;
		else
			vars->color = 0xe80c0c / 2;
		if (vars->side == 1)
			vars->color = vars->color / 2;
		d = vars->drawStart;
		while (d < vars->drawEnd)
		{
			pix = vars->img + ((int)d * vars->line) + ((int)x * (vars->bits / 8));
			*(unsigned int *)pix = vars->color;
			d++;
		}
		x++;
	}
}

void	draw_fc(t_values *vars)
{
	int		x;
	int		y;
	char	*pix;

	x = 0;
	vars->color = 0x0000FF;
	while (x < screenHeight)
	{
		if (x == screenHeight / 2)
			vars->color = 0x808080;
		y = 0;
		while (y < screenWidth)
		{
			pix = vars->img + ((int)x * vars->line) + ((int)y * (vars->bits / 8));
			if (*(unsigned int *)pix == 0)
				*(unsigned int *)pix = vars->color;
			y++;
		}
		x++;
	}
}

int	keys(int key, t_values *vars)
{
	if (key == 53)
	{
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
		// if (vars->img_ptr)
		// 	mlx_destroy_image(vars->mlx_ptr, vars->img_ptr);
		exit(0);
	}
	else if (key == 13)
	{
		if (!worldMap[(int)(vars->posX + vars->dirX * 0.65)][(int)(vars->posY)])
			vars->posX += vars->dirX * 0.65;
		if (!worldMap[(int)(vars->posX)][(int)(vars->posY + vars->dirY * 0.65)])
			vars->posY += vars->dirY * 0.65;
	}
	else if (key == 1)
	{
		if (!worldMap[(int)(vars->posX - vars->dirX * 0.65)][(int)(vars->posY)])
			vars->posX -= vars->dirX * 0.65;
		if (!worldMap[(int)(vars->posX)][(int)(vars->posY - vars->dirY * 0.65)])
			vars->posY -= vars->dirY * 0.65;
	}
	else if (key == 0)
	{
		if (!worldMap[(int)(vars->posX)][(int)(vars->posY + vars->dirX * 0.65)])
			vars->posY += vars->dirX * 0.65;
		if (!worldMap[(int)(vars->posX + (-vars->dirY * 0.65))][(int)(vars->posY)])
			vars->posX += -vars->dirY * 0.65;
	}
	else if (key == 2)
	{
		if (!worldMap[(int)(vars->posX)][(int)(vars->posY - vars->dirX * 0.65)])
			vars->posY -= vars->dirX * 0.65;
		if (!worldMap[(int)(vars->posX - (-vars->dirY * 0.65))][(int)(vars->posY)])
			vars->posX -= -vars->dirY * 0.65;
	}
	else if (key == 123)
	{
		vars->oldDirX = vars->dirX;
		vars->dirX = vars->dirX * cos(0.2) - vars->dirY * sin(0.2);
		vars->dirY = vars->oldDirX * sin(0.2) + vars->dirY * cos(0.2);
		vars->oldPlaneX = vars->planeX;
		vars->planeX = vars->planeX * cos(0.2) - vars->planeY * sin(0.2);
		vars->planeY = vars->oldPlaneX * sin(0.2) + vars->planeY * cos(0.2);
	}
	else if (key == 124)
	{
		vars->oldDirX = vars->dirX;
		vars->dirX = vars->dirX * cos(-0.2) - vars->dirY * sin(-0.2);
		vars->dirY = vars->oldDirX * sin(-0.2) + vars->dirY * cos(-0.2);
		vars->oldPlaneX = vars->planeX;
		vars->planeX = vars->planeX * cos(-0.2) - vars->planeY * sin(-0.2);
		vars->planeY = vars->oldPlaneX * sin(-0.2) + vars->planeY * cos(-0.2);
	}
	// mlx_destroy_image(vars->mlx_ptr, vars->img_ptr);
	// vars->img_ptr = mlx_new_image(vars->mlx_ptr, screenWidth, screenHeight);
	// vars->img = mlx_get_data_addr(vars->img_ptr, &vars->bits, &vars->line,
	// 		&vars->end);
	// raycasting(vars);
	// draw_fc(vars);
	// mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img_ptr, 0, 0);
	printf("posX:%f posY:%f dX:%f dY:%f pX:%f pY:%f\n", vars->posX, vars->posY, vars->dirX, vars->dirY, vars->planeX, vars->planeY);
	return (0);
}

int	test(t_values *vars)
{
	vars->img_ptr = mlx_new_image(vars->mlx_ptr, screenWidth, screenHeight);
	vars->img = mlx_get_data_addr(vars->img_ptr, &vars->bits, &vars->line,
			&vars->end);
	raycasting(vars);
	draw_fc(vars);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img_ptr, 0, 0);
	mlx_destroy_image(vars->mlx_ptr, vars->img_ptr);
	return (0);
}

int	hook(t_values *vars)
{
	// mlx_loop_hook(vars->mlx_ptr, test, &vars);
	// mlx_hook(vars->win_ptr, 2, 0, keys, &vars);
	// mlx_loop_hook(vars->mlx_ptr, test, &vars);
	mlx_loop(vars->mlx_ptr);
	return (0);
}

int	main()
{
	t_values	vars;

	vars.posX = 22;
	vars.posY = 22;
	vars.dirX = -1;
	vars.dirY = 0;
	vars.planeX = 0;
	vars.planeY = 0.66;
	
	vars.mlx_ptr = mlx_init();
	if (vars.mlx_ptr == NULL)
		return (0);
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, screenWidth, screenHeight, "Cub3D");
	if (vars.win_ptr == NULL)
		return (0);
	vars.img_ptr = mlx_new_image(vars.mlx_ptr, screenWidth, screenHeight);
	if (vars.img_ptr == NULL)
		return (0);
	vars.img = mlx_get_data_addr(vars.img_ptr, &vars.bits, &vars.line, &vars.end);
	raycasting(&vars);
	draw_fc(&vars);
	mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, vars.img_ptr, 0, 0);
	mlx_hook(vars.win_ptr, 2, 0, keys, &vars);
	mlx_loop_hook(vars.mlx_ptr, test, &vars);
	mlx_loop(vars.mlx_ptr);
	// hook(&vars);
	// test(&vars);
	
	return (0);
}

// ----At what side to look---
// dirX=0 dirY=-1 planeX=-0.66 planeY=0
// dirX=-1 dirY=0 planeX=0 planeY=0.66
// dirX=1 dirY=0 planeX=0 planeY=-0.66
// dirX=0 dirY=1 planeX=0.66 planeY=0
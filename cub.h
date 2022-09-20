/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:21:32 by bvarlamo          #+#    #+#             */
/*   Updated: 2022/09/19 09:35:40 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
#define	CUB_H

#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <math.h>
#include "minilibx_opengl/mlx.h"

typedef struct s_values
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	void	*img;
	void	*fc_img;
	void	*fc_img_ptr;
	int		bits;
	int		line;
	int		end;
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	int		mapX;
	int		mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		lineHeight;
	int		h;
	int		drawStart;
	int		drawEnd;
	int		color;
	double	oldDirX;
	double	oldPlaneX;
	
}	t_values;


#endif
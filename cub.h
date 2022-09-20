/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:21:32 by bvarlamo          #+#    #+#             */
/*   Updated: 2022/09/20 12:36:28 by bvarlamo         ###   ########.fr       */
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
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	void				*img;
	void				*fc_img;
	void				*fc_img_ptr;
	int					bits;
	int					line;
	int					end;
	double				posX;
	double				posY;
	double				dirX;
	double				dirY;
	double				planeX;
	double				planeY;
	double				cameraX;
	double				rayDirX;
	double				rayDirY;
	int					mapX;
	int					mapY;
	double				sideDistX;
	double				sideDistY;
	double				deltaDistX;
	double				deltaDistY;
	double				perpWallDist;
	int					stepX;
	int					stepY;
	int					hit;
	int					side;
	int					lineHeight;
	int					h;
	int					drawStart;
	int					drawEnd;
	unsigned long int	color;
	double				oldDirX;
	double				oldPlaneX;
	// unsigned long int 	buffer[][];
	int					texNum;
	double				wallX;
	int					texX;
	void				*tex1;
	void				*tex2;
	void				*tex3;
	void				*tex4;
	void				*tex5;
	void				*tex6;
	void				*tex7;
	void				*tex8;
	int					*width1;
	int					*height1;
	int					*width2;
	int					*height2;
	int					*width3;
	int					*height3;
	int					*width4;
	int					*height4;
	int					*width5;
	int					*height5;
	int					*width6;
	int					*height6;
	int					*width7;
	int					*height7;
	int					*width8;
	int					*height8;
	double				step;
	double				texPos;
	int					texY;
	
}	t_values;


#endif
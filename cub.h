/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:21:32 by bvarlamo          #+#    #+#             */
/*   Updated: 2022/09/22 10:34:08 by bvarlamo         ###   ########.fr       */
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

#define mapWidth 24
#define mapHeight 24
#define screenWidth 800
#define screenHeight 600

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
	int					texNum;
	double				wallX;
	int					texX;
	void				*tex[4];
	void				*itex[4];
	int					width[4];
	int					height[4];
	int					tbits[4];
	int					tline[4];
	int					tend[4];
	double				step;
	double				texPos;
	int					texY;
	
}	t_values;
	
void	raycast1(t_values *vars);
void	raycast2(t_values *vars);
void	raycast3(t_values *vars);
void	raycast4(t_values *vars);
void	raycast5(t_values *vars);
int		keys(int key, t_values *vars);
int		xclose(t_values *vars);
void	textures(t_values *vars);
int		test(t_values *vars);
void	draw_fc(t_values *vars);
void	drawwalls(int x, t_values *vars);
void	raycasting(t_values *vars);



#endif
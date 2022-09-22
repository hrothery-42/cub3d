/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:21:32 by bvarlamo          #+#    #+#             */
/*   Updated: 2022/09/22 13:46:40 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <math.h>
# include "minilibx_opengl/mlx.h"

# define MAPWIDTH 24
# define MAPHEIGHT 24
# define SCREENWIDTH 800
# define SCREENHEIGHT 600

typedef struct s_cordinates
{
	double	x;
	double	y;
}	t_cordinates;

typedef struct s_icordinates
{
	int	x;
	int	y;
}	t_icordinates;

typedef struct s_values
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	void				*img;
	int					bits;
	int					line;
	int					end;
	t_cordinates		pos;
	t_cordinates		dir;
	t_cordinates		plane;
	double				camerax;
	t_cordinates		ray;
	t_icordinates		map;
	t_cordinates		side;
	t_cordinates		delta;
	double				perpwalldist;
	t_icordinates		step;
	int					hit;
	int					p_side;
	int					lineheight;
	int					h;
	int					drawstart;
	int					drawend;
	unsigned long int	color;
	double				olddirx;
	double				oldplanex;
	int					texnum;
	double				wallx;
	t_icordinates		tex;
	void				*t_tex[4];
	void				*itex[4];
	int					width[4];
	int					height[4];
	int					tbits[4];
	int					tline[4];
	int					tend[4];
	double				t_step;
	double				texpos;

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
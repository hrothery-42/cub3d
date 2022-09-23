/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:21:32 by bvarlamo          #+#    #+#             */
/*   Updated: 2022/09/23 10:22:58 by hrothery         ###   ########.fr       */
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

typedef struct s_coordinates
{
	double	x;
	double	y;
}	t_coordinates;

typedef struct s_icoordinates
{
	int	x;
	int	y;
}	t_icoordinates;

typedef struct s_values
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	void				*img;
	int					bits;
	int					line;
	int					end;
	t_coordinates		pos;
	t_coordinates		dir;
	t_coordinates		plane;
	double				camerax;
	t_coordinates		ray;
	t_icoordinates		map;
	t_coordinates		side;
	t_coordinates		delta;
	double				perpwalldist;
	t_icoordinates		step;
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
	t_icoordinates		tex;
	void				*t_tex[4];
	void				*itex[4];
	int					width[4];
	int					height[4];
	int					tbits[4];
	int					tline[4];
	int					tend[4];
	double				t_step;
	double				texpos;
	char				**map;

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
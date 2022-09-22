/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:12:12 by bvarlamo          #+#    #+#             */
/*   Updated: 2022/09/21 16:17:45 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	drawwalls(int x, t_values *vars)
{
	int		d;
	char	*pix;

	d = vars->drawStart;
	while (d < vars->drawEnd)
	{
		vars->texY = (int)vars->texPos & (vars->height[vars->texNum] - 1);
		vars->texPos += vars->step;
		pix = vars->img + ((int)d * vars->line) + ((int)x * (vars->bits / 8));
		*(unsigned int *) pix = *(unsigned int *)(vars->itex[vars->texNum]
				+ ((int)vars->texY * vars->tline[vars->texNum])
				+ ((int)vars->texX * (vars->tbits[vars->texNum] / 8)));
		d++;
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
			pix = vars->img + (int)x * vars->line + (int)y * (vars->bits / 8);
			if (*(unsigned int *)pix == 0)
				*(unsigned int *)pix = vars->color;
			y++;
		}
		x++;
	}
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

void	textures(t_values *vars)
{
	vars->tex[0] = mlx_xpm_file_to_image(vars->mlx_ptr, "pics/redbrick.xpm", &vars->width[0], &vars->height[0]);
	vars->itex[0] = mlx_get_data_addr(vars->tex[0], &vars->tbits[0], &vars->tline[0], &vars->tend[0]);
	vars->tex[1] = mlx_xpm_file_to_image(vars->mlx_ptr, "pics/bluestone.xpm", &vars->width[1], &vars->height[1]);
	vars->itex[1] = mlx_get_data_addr(vars->tex[1], &vars->tbits[1], &vars->tline[1], &vars->tend[1]);
	vars->tex[2] = mlx_xpm_file_to_image(vars->mlx_ptr, "pics/colorstone.xpm", &vars->width[2], &vars->height[2]);
	vars->itex[2] = mlx_get_data_addr(vars->tex[2], &vars->tbits[2], &vars->tline[2], &vars->tend[2]);
	vars->tex[3] = mlx_xpm_file_to_image(vars->mlx_ptr, "pics/wood.xpm", &vars->width[3], &vars->height[3]);
	vars->itex[3] = mlx_get_data_addr(vars->tex[3], &vars->tbits[3], &vars->tline[3], &vars->tend[3]);
}


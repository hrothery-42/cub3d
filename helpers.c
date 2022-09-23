/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:12:12 by bvarlamo          #+#    #+#             */
/*   Updated: 2022/09/23 11:47:00 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	drawwalls(int x, t_values *vars)
{
	int		d;
	char	*pix;

	d = vars->drawstart;
	while (d < vars->drawend)
	{
		vars->tex.y = (int)vars->texpos & (vars->height[vars->texnum] - 1);
		vars->texpos += vars->t_step;
		pix = vars->img + ((int)d * vars->line) + ((int)x * (vars->bits / 8));
		*(unsigned int *) pix = *(unsigned int *)(vars->itex[vars->texnum]
				+ ((int)vars->tex.y * vars->tline[vars->texnum])
				+ ((int)vars->tex.x * (vars->tbits[vars->texnum] / 8)));
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
	while (x < SCREENHEIGHT)
	{
		if (x == SCREENHEIGHT / 2)
			vars->color = 0x808080;
		y = 0;
		while (y < SCREENWIDTH)
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
	vars->img_ptr = mlx_new_image(vars->mlx_ptr, SCREENWIDTH, SCREENHEIGHT);
	vars->img = mlx_get_data_addr(vars->img_ptr, &vars->bits, &vars->line,
			&vars->end);
	raycasting(vars);
	draw_fc(vars);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img_ptr, 0, 0);
	mlx_destroy_image(vars->mlx_ptr, vars->img_ptr);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:55:47 by hrothery          #+#    #+#             */
/*   Updated: 2022/09/29 14:56:01 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	sprite(t_values *vars)
{
	vars->t_tex[4] = mlx_xpm_file_to_image(vars->mlx_ptr, "./img/cat.xpm", &vars->width[4], &vars->height[4]);
	if (!vars->t_tex[4])
	{
		ft_putstr_fd("Error!\nBad file path for sprite.\n", 2);
		return (1);
	}
	vars->itex[4] = mlx_get_data_addr(vars->t_tex[4], &vars->tbits[4], &vars->tline[4], &vars->tend[4]);
	if (!vars->itex[4])
	{
		ft_putstr_fd("Error!\nSprite can't be rendered.\n", 2);
		return (1);
	}
	return (0);
}

/* int	mlx_sync(int cmd, void *ptr) //ptr is a ptr to the mlx image object
{
	
} */

//shoot the ray again and stop at the place where the wall was
//is there a sprite?  If so draw the sprite values on top of the image already rendered
//the image must be moving!
//find a way to draw the sprite at the correct size and draw it always head on

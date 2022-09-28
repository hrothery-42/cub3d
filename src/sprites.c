/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:55:47 by hrothery          #+#    #+#             */
/*   Updated: 2022/09/28 15:26:39 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	init_sprite(char **tmp, t_values *vars)
{
	if (!tmp[1] || tmp[2])
	{
		ft_putstr_fd("Error!\nInvalid data: sprite\n", 2);
		return (1);
	}
	vars->s.path = malloc(sizeof(char) *(1 + ft_strlen(tmp[1])));
	if (!vars->s.path)
	{
		ft_putstr_fd("Error!\nMemory allocation failed: sprite.\n", 2);
		free_everything(vars);
		exit (1);
	}
	ft_strlcpy(vars->s.path, tmp[1], ft_strlen(tmp[1]) + 1);
	return (0);
}

bool	sprite(t_values *vars)
{
	vars->s.s_ptr = mlx_xpm_file_to_image(vars->mlx_ptr, vars->s.path, &vars->s.w, &vars->s.h);
	if (!vars->s.s_ptr)
		return (1);
	vars->s.s_img = mlx_get_data_addr(vars->s.s_img, &vars->s.bits, &vars->s.line, &vars->s.end);
	if (!vars->s.s_img)
		return (1);
	return (0);
}

/* int	mlx_sync(int cmd, void *ptr) //ptr is a ptr to the mlx image object
{
	
} */

//shoot the ray again and stop at the place where the wall was
//is there a sprite?  If so draw the sprite values on top of the image already rendered
//the image must be moving!
//find a way to draw the sprite at the correct size and draw it always head on

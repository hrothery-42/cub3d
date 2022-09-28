/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:55:47 by hrothery          #+#    #+#             */
/*   Updated: 2022/09/28 14:12:14 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	init_sprite(t_values *vars, char *line)
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

bool	render_sprite(t_values *vars)
{
	s->s_ptr = mlx_xpm_file_to_image(vars->mlx_ptr, s->path, &s->w, &s->h);
	if (!s_ptr)
		return (1);
	s->s_img = mlx_get_data_addr(s->s_img, &s->bits, &s->line, &s->tend);
	if (!s->img)
		return (1);
	return (0);
}
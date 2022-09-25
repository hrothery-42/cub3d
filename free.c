/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 13:56:38 by hrothery          #+#    #+#             */
/*   Updated: 2022/09/25 14:25:46 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	free_map(t_values *vars)
{
	int	i;

	ft_double_free(vars->map);
	i = 0;
	while (i < 4)
	{
		if (vars->pattern[i])
			free(vars->pattern[i]);
		i++;
	}
	return (1);
}

bool	free_everything(t_values *vars)
{
	int	i;

	i = 0;
	ft_double_free(vars->map);
	if (vars->img_ptr)
		mlx_destroy_image(vars->mlx_ptr, vars->img_ptr);
	i = 0;
	while (i < 4)
	{
		if (vars->pattern[i])
			free(vars->pattern[i]);
		i++;
	}
	if (vars->win_ptr)
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	free(vars->mlx_ptr);
	return (1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:46:26 by hrothery          #+#    #+#             */
/*   Updated: 2022/09/21 08:30:15 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

bool	left_wall(int i, int j, t_values *vars)
{
	while (j > 0)
	{
		j--;
		if (vars->map[i][j] == '1')
			return (0);
	}
	ft_putstr_fd("Error!\nThe wall is not complete.\n", 2);
	return (1);
}

bool	right_wall(int i, int j, t_values *vars)
{
	while (vars->map[i][j] && j < vars->nr_columns)
	{
		j++;
		if (vars->map[i][j] == '1')
			return (0);
	}
	ft_putstr_fd("Error!\nThe wall is not complete.\n", 2);
	return (1);
}

bool	top_wall(int i, int j, t_values *vars)
{
	while (i > 0)
	{
		i--;
		if (vars->map[i][j] == '1')
			return (0);
	}
	ft_putstr_fd("Error!\nThe wall is not complete.\n", 2);
	return (1);
}

bool	bottom_wall(int i, int j, t_values *vars)
{
	while (i < vars->nr_rows - 1)
	{
		i++;
		if (vars->map[i][j] == '1')
			return (0);
	}
	ft_putstr_fd("Error!\nThe wall is not complete.\n", 2);
	return (1);
}
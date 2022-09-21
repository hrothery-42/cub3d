/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:45:06 by hrothery          #+#    #+#             */
/*   Updated: 2022/09/21 16:18:28 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

bool	left_border(int i, int j, t_values *vars)
{
	while (j > 0)
	{
		j--;
		if (vars->map[i][j] == '1')
			return (0);
		if (vars->map[i][j] == '0')
		{
			ft_putstr_fd("Error!\nThere are empty spaces inside the map.\n", 2);
			return (1);
		}
	}
	return (0);
}

bool	right_border(int i, int j, t_values *vars)
{
	while (vars->map[i][j] && j < vars->nr_columns)
	{
		j++;
		if (vars->map[i][j] == '1')
			return (0);
		if (vars->map[i][j] == '0')
		{
			ft_putstr_fd("Error!\nThere are empty spaces inside the map.\n", 2);
			return (1);
		}
	}
	return (0);
}

bool	top_border(int i, int j, t_values *vars)
{
	while (i > 0)
	{
		i--;
		if (vars->map[i][j] == '1')
			return (0);
		if (vars->map[i][j] == '0')
		{
			ft_putstr_fd("Error!\nThere are empty spaces inside the map.\n", 2);
			return (1);
		}
	}
	return (0);
}

bool	bottom_border(int i, int j, t_values *vars)
{
	while (i < vars->nr_rows - 1)
	{
		i++;
		if (vars->map[i][j] == '1')
			return (0);
		if (vars->map[i][j] == '0')
		{
			ft_putstr_fd("Error!\nThere are empty spaces inside the map.\n", 2);
			return (1);
		}
	}
	return (0);
}

void	sort_data(t_values *vars, char *line, int *count, bool *ret)
{
	int	j;

	if (*count < 6 && !is_only_whitespaces(line))
	{
		(*count)++;
		if (init_value(line, vars))
		{
			ft_putstr_fd("error: ", 2);
			ft_putstr_fd(line, 2);
			*ret = 1;
		}
	}
	else if ((*count == 6 && !is_only_whitespaces(line)) || *count > 6)
	{
		j = (*count) - 6;
		(*count)++;
		if (j == vars->nr_rows)
			return ;
		ft_strlcpy(vars->map[j++], line, ft_strlen(line) + 1);
	}
}

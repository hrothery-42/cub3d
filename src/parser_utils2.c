/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:29:11 by hrothery          #+#    #+#             */
/*   Updated: 2022/09/20 16:15:03 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

bool	save_color(char *color, t_color *l)
{
	char	**tmp;
	bool	ret;

	ret = 0;
	tmp = ft_split(color, ',');
	if (!tmp[2] || tmp[3])
		ret = 1;
	if (!ft_strisdigit(tmp[0]) || !ft_strisdigit(tmp[1]) || !ft_strisdigit(tmp[2]))
		ret = 1;
	l->red = ft_atoi(tmp[0]);
	l->green = ft_atoi(tmp[1]);
	l->blue = ft_atoi(tmp[2]);
	if (l->red < 0 | l->red > 255 || l->green < 0 || l->green > 255 || l->blue < 0 || l->blue > 255)
		ret = 1;
	if (ret == 1)
		ft_putstr_fd("error: color value(s): floor and/or ceiling\n", 2);
	ft_double_free(tmp);
	return (ret);
}

bool	check_character(char c, t_values *vars)
{
	if (c == '1' || c == '0' || c == ' ' || c == '\0')
		return (0);
	else if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		vars->start_position++;
		return (0);
	}
	return (1);
}

bool	left_wall(int i, int j, t_values *vars)
{
	while (j > 0)
	{
		j--;
		if (vars->map[i][j] == '1')
			return (0);
	}
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
	return (1);
}

bool	check_map(t_values *vars)
{
	vars->start_position = 0;
	int	i;
	int	j;

	i = 0;
	while (i < vars->nr_rows)
	{
		j = 0;
		while (j < vars->nr_columns)
		{
			if (check_character(vars->map[i][j], vars))
			{
				ft_putstr_fd("invalid character on the map\n", 2);
				return (1);
			}
			if (vars->map[i][j] == '0')
			{
				if (left_wall(i, j, vars) || right_wall(i, j, vars) || top_wall(i, j, vars) || bottom_wall(i, j, vars))
				{
					ft_putstr_fd("The map is not surrounded by walls\n", 2);
					return (1);
				}
			}
			j++;
		}
		i++;
	}
	if (vars->start_position != 1)
	{
		ft_putstr_fd("wrong number of starting positions\n", 2);
		return (1);
	}
	return (0);
}
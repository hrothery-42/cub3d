/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:31:53 by hrothery          #+#    #+#             */
/*   Updated: 2022/09/23 11:47:12 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	get_color(char *color, t_values *vars, int i)
{
	char	**tmp;
	bool	ret;
	t_color	l;

	ret = 0;
	tmp = ft_split(color, ',');
	if (!tmp[2] || tmp[3])
		ret = 1;
	if (!ft_strisdigit(tmp[0]) || !ft_strisdigit(tmp[1]) \
	|| !ft_strisdigit(tmp[2]))
		ret = 1;
	l.red = ft_atoi(tmp[0]);
	l.green = ft_atoi(tmp[1]);
	l.blue = ft_atoi(tmp[2]);
	if (l.red < 0 | l.red > 255 || l.green < 0 || l.green > 255 \
	|| l.blue < 0 || l.blue > 255)
		ret = 1;
	ft_double_free(tmp);
	if (ret == 1)
		ft_putstr_fd("Error!\nColor value(s): floor and/or ceiling.\n", 2);
	else if (!ret && i == FLOOR)
		vars->floor = create_trgb(0, l.red, l.green, l.blue);
	else if (!ret && i == CEILING)
		vars->ceiling = create_trgb(0, l.red, l.green, l.blue);
	return (ret);
}

bool	check_character(char c, t_values *vars, int i, int j)
{
	if (c == '1' || c == '0' || c == ' ' || c == '\0')
		return (0);
	else if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		vars->nr_start_pos++;
		init_pos_and_dir(c, vars, i, j);
		vars->map[i][j] = '0';
		return (0);
	}
	ft_putstr_fd("Error!\nInvalid charcter on the map.\n", 2);
	return (1);
}

static bool	check_map_more(int i, int j, t_values *vars)
{
	if (check_character(vars->map[i][j], vars, i, j))
		return (1);
	if (vars->map[i][j] == '0')
	{
		if (left_wall(i, j, vars) || right_wall(i, j, vars) \
		|| top_wall(i, j, vars) || bottom_wall(i, j, vars))
			return (1);
	}
	if (vars->map[i][j] == ' ')
	{
		if (top_border(i, j, vars) || bottom_border(i, j, vars) \
		|| left_border(i, j, vars) || right_border(i, j, vars))
			return (1);
	}
	return (0);
}

bool	empty_lines(t_values *vars)
{
	int	i;

	i = 0;
	while (i + 1 < vars->nr_rows)
	{
		if (is_only_whitespaces(vars->map[i]) \
		&& !is_only_whitespaces(vars->map[i + 1]))
		{
			ft_putstr_fd("Error!\nEmpty line(s) on the map.\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

bool	check_map(t_values *vars)
{
	int	i;
	int	j;

	if (empty_lines(vars))
		return (1);
	vars->nr_start_pos = 0;
	i = 0;
	while (i < vars->nr_rows)
	{
		j = 0;
		while (j < vars->nr_columns)
		{
			if (check_map_more(i, j, vars))
				return (1);
			j++;
		}
		i++;
	}
	if (vars->nr_start_pos != 1)
	{
		ft_putstr_fd("Error! Wrong number of starting positions.\n", 2);
		return (1);
	}
	return (0);
}
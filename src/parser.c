/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:34:12 by hrothery          #+#    #+#             */
/*   Updated: 2022/09/21 08:43:41 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

bool	init_t_values(char *argv, t_values *vars)
{
	int		fd;
	char	*line;
	int		count;
	int		j;

	count = 0;
	j = 0;
	line = (char *)1;
	fd = open(argv, O_RDONLY);
	while (line)
	{
		line = get_next_line(fd);
		replace_newline(line);
		if (count < 6 && !is_only_whitespaces(line))
		{
			count++;
			if (init_value(line, vars))
			{
				ft_putstr_fd("Error!\nFalse identifier or value.\n", 2);
				return (1);
			}
		}
		else if (count == 6 && !is_only_whitespaces(line) || count > 6)
		{
			count++;
			if (j == vars->nr_rows)
				break ;
			ft_strlcpy(vars->map[j++], line, ft_strlen(line) + 1);
		}
		free(line);
	}
	close(fd);
	return (0);
}

void	allocate_map(t_values *vars)
{
	int	i;

	vars->map = malloc(sizeof(char *) * (vars->nr_rows + 1));
	if (!vars->map)
	{
		ft_putstr_fd("Error!\nMemory allocation failed.\n", 2);
		exit(0);
	}
	i = 0;
	while (i < vars->nr_rows)
	{
		vars->map[i] = ft_calloc(vars->nr_columns + 1, sizeof(char));
		if (!vars->map[i])
		{
			ft_putstr_fd("Error!\nMemory allocation failed.\n", 2);
			ft_double_free(vars->map);
			exit(0);
		}
		i++;
	}
	vars->map[i] = NULL;
}

static void	ft_count(int fd, t_values *vars)
{
	char	*line;
	bool	map;

	line = (char *)1;
	map = 0;
	while (line)
	{
		line = get_next_line(fd);
		if (!map && first_char(line) == '1')
		{
			map = 1;
			vars->nr_rows++;
			vars->nr_columns = ft_strlen(line);
		}
		else if (!map)
			write_nswefc(vars, line);
		else if (map && line)
		{
			vars->nr_rows++;
			if (ft_strlen(line) > vars->nr_columns)
				vars->nr_columns = ft_strlen(line);
		}
		free(line);
	}
}

void	count_map_rows(char *argv, t_values *vars)
{
	int		fd;
	int		i;

	vars->nr_rows = 0;
	vars->nr_columns = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error!\nCannot open file.\n", 2);
		exit(0);
	}
	ft_count(fd, vars);
	close(fd);
	i = 0;
	while (i < 7)
	{
		if (vars->nswefc[i] != 1)
		{
			ft_putstr_fd("Error!\nFile: invalid identifiers.\n", 2);
			exit(0);
		}
		i++;
	}
}

int	parse_input(char *argv, t_values *vars)
{
	int	i;

	i = 0;
	while (i < 6)
		vars->nswefc[i++] = 0;
	vars->nswefc[6] = 1;
	count_map_rows(argv, vars);
	allocate_map(vars);
	if (init_t_values(argv, vars)|| check_map(vars))
	{
		ft_putstr_fd("Check the file content.\n", 2);
		return (1);
	}
	return (0);
}

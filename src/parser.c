/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:34:12 by hrothery          #+#    #+#             */
/*   Updated: 2022/09/20 10:04:29 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

char	first_char(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return ('\0');
	while (line[i] != '\0')
	{
		if (line[i] != ' ')
			return (line[i]);
		i++;
	}
	return ('\0');
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

	vars->nr_rows = 0;
	vars->nr_columns = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error opening file\n", 2);
		exit(0);
	}
	ft_count(fd, vars);
	close(fd);
}

int	parse_input(char *argv, t_values *vars)
{
	int	i;

	count_map_rows(argv, vars);
	vars->map = (char **)malloc(sizeof(char *) * vars->nr_rows);
	if (!vars->map)
		return (printf("Error: malloc failed\n"));
	i = 0;
	while (i < vars->nr_rows)
	{
		vars->map[i] = ft_calloc(vars->nr_columns + 1, sizeof(char));
		if (!vars->map[i])
		{
			ft_putstr_fd("Error: malloc failed\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:34:12 by hrothery          #+#    #+#             */
/*   Updated: 2022/09/20 11:19:01 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

bool	init_t_values(char *argv, t_values *vars)
{
	int		fd;
	char	*line;
	bool	map;
	
	fd = open(argv, O_RDONLY);
	line = (char *)1;
	map = 0;
	while (line)
	{
		line = get_next_line(fd);
		replace_newline(line);
		
	}
	close(fd);
}

void	allocate_map(t_values *vars)
{
	int	i;

	vars->map = (char **)malloc(sizeof(char *) * vars->nr_rows);
	if (!vars->map)
	{
		ft_putstr_fd("Error: memory allocation failed\n", 2);
		exit(0);
	}
	i = 0;
	while (i < vars->nr_rows)
	{
		vars->map[i] = ft_calloc(vars->nr_columns + 1, sizeof(char));
		if (!vars->map[i])
		{
			ft_putstr_fd("Error: malloc failed\n", 2);
			ft_double_free(vars->map);
			exit(0);
		}
		i++;
	}
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
		ft_putstr_fd("Error opening file\n", 2);
		exit(0);
	}
	ft_count(fd, vars);
	close(fd);
	i = 0;
	while (i < 7)
	{
		if (vars->nswefc[i] != 1)
		{
			ft_putstr_fd("Error: file: duplicate/ missing/ invalid identifiers\n", 2);
			exit(0);
		}
		i++;
	}
}

int	parse_input(char *argv, t_values *vars)
{
	int 	i;

	i = 0;
	while (i < 6)
		vars->nswefc[i++] = 0;
	vars->nswefc[6] = 1;
	count_map_rows(argv, vars);
	allocate_map(vars);
	if (init_t_values(argv, vars))
		return (1);
	return (0);
}

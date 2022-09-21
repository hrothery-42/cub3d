/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:33:28 by hrothery          #+#    #+#             */
/*   Updated: 2022/09/21 09:00:38 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

bool	save_fd(char *path, int *location)
{
	int	fd;

	//fd = open(path, O_RDONLY);
	//if (fd < 0)
	//	return (1);
	//*location = fd;
	return (0);
}

bool	init_value(char *line, t_values *vars)
{
	char	**tmp;
	bool	ret;

	tmp = ft_split(line, ' ');
	if (!tmp[1] || tmp[2])
		ret = 1;
	else if (!ft_strcmp(tmp[0], "NO"))
		ret = save_fd(tmp[1], &vars->fd_no);
	else if (!ft_strcmp(tmp[0], "SO"))
		ret = save_fd(tmp[1], &vars->fd_so);
	else if (!ft_strcmp(tmp[0], "WE"))
		ret = save_fd(tmp[1], &vars->fd_we);
	else if (!ft_strcmp(tmp[0], "EA"))
		ret = save_fd(tmp[1], &vars->fd_ea);
	else if (!ft_strcmp(tmp[0], "F"))
		ret = save_color(tmp[1], &vars->floor);
	else if (!ft_strcmp(tmp[0], "C"))
		ret = save_color(tmp[1], &vars->ceiling);
	else
		ret = 1;
	ft_double_free(tmp);
	return (ret);
}

void	write_nswefc(t_values *vars, char *line)
{
	char	c;

	c = first_char(line);
	if (c == 'N')
		vars->nswefc[0]++;
	else if (c == 'S')
		vars->nswefc[1]++;
	else if (c == 'W')
		vars->nswefc[2]++;
	else if (c == 'E')
		vars->nswefc[3]++;
	else if (c == 'F')
		vars->nswefc[4]++;
	else if (c == 'C')
		vars->nswefc[5]++;
	else if (c == '\0' || c == '\n')
		return ;
	else
		vars->nswefc[6]++;
}

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

void	replace_newline(char *line)
{
	char	*p;

	if (!line)
		return ;
	p = ft_strrchr(line, '\n');
	if (p)
		*p = ' ';
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:30:40 by hrothery          #+#    #+#             */
/*   Updated: 2022/09/23 11:47:10 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	init_value(char *line, t_values *vars)
{
	char	**tmp;
	bool	ret;
	int		color;

	tmp = ft_split(line, ' ');
	if (!tmp[1] || tmp[2])
		ret = 1;
	else if (!ft_strcmp(tmp[0], "NO"))
		ret = save_tex(tmp[1], vars, NORTH);
	else if (!ft_strcmp(tmp[0], "SO"))
		ret = save_tex(tmp[1], vars, SOUTH);
	else if (!ft_strcmp(tmp[0], "WE"))
		ret = save_tex(tmp[1], vars, WEST);
	else if (!ft_strcmp(tmp[0], "EA"))
		ret = save_tex(tmp[1], vars, EAST);
	else if (!ft_strcmp(tmp[0], "F"))
		ret = get_color(tmp[1], vars, FLOOR);
	else if (!ft_strcmp(tmp[0], "C"))
		ret = get_color(tmp[1], vars, CEILING);
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

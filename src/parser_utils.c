/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:33:28 by hrothery          #+#    #+#             */
/*   Updated: 2022/09/20 11:19:08 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

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
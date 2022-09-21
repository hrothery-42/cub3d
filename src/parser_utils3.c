/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:04:58 by hrothery          #+#    #+#             */
/*   Updated: 2022/09/21 17:05:39 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	init_pos_and_dir(char c, t_values *vars, int i, int j)
{
	/* posX = i;
	posY = j;
	if (c == 'N')
	{
		dirX = 0; 
		dirY = 1;
	}
	else if (c == 'S')
	{
		dirX = 0;
		dirY = -1;
	}
	else if (c == 'W')
	{
		dirX = -1;
		dirY = 0;
	}
	else if (c == 'E')
	{
		dirX = 1;
		dirY = 0;
	} */
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

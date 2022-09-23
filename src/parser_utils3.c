/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:04:58 by hrothery          #+#    #+#             */
/*   Updated: 2022/09/23 09:55:48 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

//NO = 0, SO = 1, WE = 2, EA = 3
bool	save_tex(char *pattern, t_values *vars, int i)
{
	/* if (!vars->t_tex[i] = mlx_xpm_file_to_image(vars->mlx_ptr, pattern,
		&vars->width[i], &vars->height[i]))
	{
		ft_putstr_fd("Error!\nProblem connecting file with minilibx. Check file path.\n", 2);
		return (1);
	}
	if (!vars->itex[i] = mlx_get_data_addr(vars->t_tex[i], &vars->tbits[i],
		&vars->tline[i], &vars->tend[i]))
	{
		ft_putstr_fd("Error!\nProblem connecting file with minilibx.\n", 2);
		return (1);
	} */
	return (0);
}

int	create_trgb(int t, int r, int g, int b)
{
	int	trgb;

	trgb = t << 24 | r << 16 | g << 8 | b;
	return (trgb);
}

void	init_pos_and_dir(char c, t_values *vars, int i, int j)
{
	vars->pos.x = i;
	vars->pos.y = j;
	if (c == 'N')
	{
		vars->dir.x = 0; 
		vars->dir.y = 1;
		vars->plane.x = 0.66;
		vars->plane.y = 0;
	}
	else if (c == 'S')
	{
		vars->dir.x = 0;
		vars->dir.y = -1;
		vars->plane.x = -0.66;
		vars->plane.y = 0;
	}
	else if (c == 'W')
	{
		vars->dir.x = -1;
		vars->dir.y = 0;
		vars->plane.x = 0;
		vars->plane.y = 0.66;
	}
	else if (c == 'E')
	{
		vars->dir.x = 1;
		vars->dir.y = 0;
		vars->plane.x = 0;
		vars->plane.y = -0.66;
	}
}

void	sort_data(t_values *vars, char *line, int *count, bool *ret)
{
	int	j;

	if (*count < 6 && !is_only_whitespaces(line))
	{
		(*count)++;
		if (init_value(line, vars))
			*ret = 1;
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

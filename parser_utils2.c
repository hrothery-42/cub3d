/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:37:56 by hrothery          #+#    #+#             */
/*   Updated: 2022/09/23 15:43:55 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	save_tex(char *pattern, t_values *vars, int i)
{
	(vars->t_tex[i] = mlx_xpm_file_to_image(vars->mlx_ptr, pattern,
				&vars->width[i], &vars->height[i]));
	if (!vars->t_tex[i])
	{
		ft_putstr_fd("Error!\nCheck file path for wall pattern.\n", 2);
		return (1);
	}
	(vars->itex[i] = mlx_get_data_addr(vars->t_tex[i], &vars->tbits[i],
				&vars->tline[i], &vars->tend[i]));
	if (!vars->itex[i])
	{
		ft_putstr_fd("Error!\nProblem connecting file with minilibx.\n", 2);
		return (1);
	}
	return (0);
}

int	create_trgb(int t, int r, int g, int b)
{
	int	trgb;

	trgb = t << 24 | r << 16 | g << 8 | b;
	return (trgb);
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

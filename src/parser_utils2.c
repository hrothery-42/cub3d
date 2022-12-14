/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:29:32 by bvarlamo          #+#    #+#             */
/*   Updated: 2022/09/28 16:29:42 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	count_commas(char *s)
{
	int	i;
	int	commas;

	commas = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == ',')
			commas++;
		i++;
	}
	return (commas);
}

bool	save_tex(char **tmp, t_values *vars, int i)
{
	char	*pattern;

	if (!tmp[1] || tmp[2])
	{
		ft_putstr_fd("Error!\nInvalid data: wall texture.\n", 2);
		return (1);
	}
	pattern = tmp[1];
	vars->pattern[i] = malloc(sizeof(char) * (ft_strlen(pattern) + 1));
	if (!vars->pattern[i])
	{
		ft_putstr_fd("Error!\nMemory allocation failed.\n", 2);
		free_everything(vars);
		exit(0);
	}
	ft_strlcpy(vars->pattern[i], pattern, ft_strlen(pattern) + 1);
	return (0);
}

bool	textures(t_values *vars)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		(vars->t_tex[i] = mlx_xpm_file_to_image(vars->mlx_ptr, vars->pattern[i],
					&vars->width[i], &vars->height[i]));
		if (!vars->t_tex[i])
		{
			ft_putstr_fd("Error!\nCheck file path for wall pattern.\n", 2);
			return (1);
		}
		(vars->itex[i] = mlx_get_data_addr(vars->t_tex[i], &vars->tbits[i],
					&vars->tline[i], &vars->tend[i]));
		if (!vars->itex[i++])
		{
			ft_putstr_fd("Error!\nProblem connecting file with minilibx.\n", 2);
			return (1);
		}
	}
	return (0);
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

static char	*copy_with_spaces(char *new, char *line)
{
	int	i;
	int	j;
	int	spaces;

	i = 0;
	j = 0;
	while (line[j])
	{
		if (line[j] == '\t')
		{
			spaces = 0;
			while (spaces < TAB)
			{
				new[i++] = ' ';
				spaces++;
			}
		}
		else
			new[i++] = line[j];
		j++;
	}
	new[i] = '\0';
	return (new);
}

char	*replace_tabs(char *line)
{
	int		i;
	int		count;
	char	*new;

	i = 0;
	count = 0;
	if (!line)
		return (0);
	while (line[i])
		if (line[i++] == '\t')
			count++;
	if (count)
	{
		new = malloc(sizeof(char) * (1 + ft_strlen(line)
					+ (count * (TAB - 1))));
		if (!new)
			return (0);
		new = copy_with_spaces(new, line);
		free(line);
		return (new);
	}
	return (line);
}

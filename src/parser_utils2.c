/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:29:11 by hrothery          #+#    #+#             */
/*   Updated: 2022/09/20 14:59:52 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

bool	save_color(char *color, t_color *l)
{
	char	**tmp;
	bool	ret;

	ret = 0;
	tmp = ft_split(color, ',');
	if (!tmp[2] || tmp[3])
		ret = 1;
	if (!ft_strisdigit(tmp[0]) || !ft_strisdigit(tmp[1]) || !ft_strisdigit(tmp[2]))
		ret = 1;
	l->red = ft_atoi(tmp[0]);
	l->green = ft_atoi(tmp[1]);
	l->blue = ft_atoi(tmp[2]);
	if (l->red < 0 | l->red > 255 || l->green < 0 || l->green > 255 || l->blue < 0 || l->blue > 255)
		ret = 1;
	if (ret == 1)
		ft_putstr_fd("error: color value(s): floor and/or ceiling\n", 2);
	ft_double_free(tmp);
	return (ret);
}
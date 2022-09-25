/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stepforward.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 12:23:25 by hrothery          #+#    #+#             */
/*   Updated: 2022/09/25 12:24:48 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	stepforward(t_values *vars)
{
	if (!vars->map[(int)(vars->pos.x + vars->dir.x
			* 0.65)][(int)(vars->pos.y)])
		vars->pos.x += vars->dir.x * 0.65;
	if (!vars->map[(int)(vars->pos.x)][(int)(vars->pos.y
			+ vars->dir.y * 0.65)])
		vars->pos.y += vars->dir.y * 0.65;
	return (0);
}

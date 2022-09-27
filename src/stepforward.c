/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stepforward.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 12:23:25 by hrothery          #+#    #+#             */
/*   Updated: 2022/09/26 12:15:27 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	stepforward(t_values *vars)
{
	if (vars->map[(int)(vars->pos.x + vars->dir.x
			* (STEP_INTERVAL * 2))][(int)(vars->pos.y)] == '0')
		vars->pos.x += vars->dir.x * STEP_INTERVAL;
	if (vars->map[(int)(vars->pos.x)][(int)(vars->pos.y
			+ vars->dir.y * (STEP_INTERVAL * 2))] == '0')
		vars->pos.y += vars->dir.y * STEP_INTERVAL;
	return (0);
}

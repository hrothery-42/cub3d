/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:54:42 by bvarlamo          #+#    #+#             */
/*   Updated: 2022/09/25 13:11:07 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	stepleft(t_values *vars)
{
	if (vars->map[(int)(vars->pos.x)][(int)(vars->pos.y + vars->dir.x
				* 0.65)] == '0')
			vars->pos.y += vars->dir.x * 0.65;
	if (vars->map[(int)(vars->pos.x + (-vars->dir.y
				* 0.65))][(int)(vars->pos.y)] == '0')
		vars->pos.x += -vars->dir.y * 0.65;
	return (0);
}

int	stepright(t_values *vars)
{
	if (vars->map[(int)(vars->pos.x)][(int)(vars->pos.y
				- vars->dir.x * 0.65)] == '0')
			vars->pos.y -= vars->dir.x * 0.65;
	if (vars->map[(int)(vars->pos.x - (-vars->dir.y
				* 0.65))][(int)(vars->pos.y)] == '0')
		vars->pos.x -= -vars->dir.y * 0.65;
	return (0);
}

int	turnleft(t_values *vars)
{
	vars->olddirx = vars->dir.x;
	vars->dir.x = vars->dir.x * cos(0.2) - vars->dir.y * sin(0.2);
	vars->dir.y = vars->olddirx * sin(0.2) + vars->dir.y * cos(0.2);
	vars->oldplanex = vars->plane.x;
	vars->plane.x = vars->plane.x * cos(0.2) - vars->plane.y * sin(0.2);
	vars->plane.y = vars->oldplanex * sin(0.2) + vars->plane.y * cos(0.2);
	return (0);
}

int	turnright(t_values *vars)
{
	vars->olddirx = vars->dir.x;
	vars->dir.x = vars->dir.x * cos(-0.2) - vars->dir.y * sin(-0.2);
	vars->dir.y = vars->olddirx * sin(-0.2) + vars->dir.y * cos(-0.2);
	vars->oldplanex = vars->plane.x;
	vars->plane.x = vars->plane.x * cos(-0.2) - vars->plane.y * sin(-0.2);
	vars->plane.y = vars->oldplanex * sin(-0.2) + vars->plane.y * cos(-0.2);
	return (0);
}

int	keys(int key, t_values *vars)
{
	if (key == EXIT_KEY)
		xclose(vars);
	else if (key == W_KEY)
		stepforward(vars);
	else if (key == S_KEY)
	{
		if (vars->map[(int)(vars->pos.x - vars->dir.x
				* 0.65)][(int)(vars->pos.y)] == '0')
			vars->pos.x -= vars->dir.x * 0.65;
		if (vars->map[(int)(vars->pos.x)][(int)(vars->pos.y
				- vars->dir.y * 0.65)] == '0')
			vars->pos.y -= vars->dir.y * 0.65;
	}
	else if (key == A_KEY)
		stepleft(vars);
	else if (key == D_KEY)
		stepright(vars);
	else if (key == LEFT_ARROW)
		turnleft(vars);
	else if (key == RIGHT_ARROW)
		turnright(vars);
	return (0);
}

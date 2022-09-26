/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:54:42 by bvarlamo          #+#    #+#             */
/*   Updated: 2022/09/26 12:18:33 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	stepleft(t_values *vars)
{
	if (vars->map[(int)(vars->pos.x)][(int)(vars->pos.y + vars->dir.x
				* (STEP_INTERVAL * 2))] == '0')
			vars->pos.y += vars->dir.x * STEP_INTERVAL;
	if (vars->map[(int)(vars->pos.x + (-vars->dir.y
				* (STEP_INTERVAL * 2)))][(int)(vars->pos.y)] == '0')
		vars->pos.x += -vars->dir.y * STEP_INTERVAL;
	return (0);
}

int	stepright(t_values *vars)
{
	if (vars->map[(int)(vars->pos.x)][(int)(vars->pos.y
				- vars->dir.x * (STEP_INTERVAL * 2))] == '0')
			vars->pos.y -= vars->dir.x * STEP_INTERVAL;
	if (vars->map[(int)(vars->pos.x - (-vars->dir.y
				* (STEP_INTERVAL * 2)))][(int)(vars->pos.y)] == '0')
		vars->pos.x -= -vars->dir.y * STEP_INTERVAL;
	return (0);
}

int	turnleft(t_values *vars)
{
	vars->olddirx = vars->dir.x;
	vars->dir.x = vars->dir.x * cos(TURN) - vars->dir.y * sin(TURN);
	vars->dir.y = vars->olddirx * sin(TURN) + vars->dir.y * cos(TURN);
	vars->oldplanex = vars->plane.x;
	vars->plane.x = vars->plane.x * cos(TURN) - vars->plane.y * sin(TURN);
	vars->plane.y = vars->oldplanex * sin(TURN) + vars->plane.y * cos(TURN);
	return (0);
}

int	turnright(t_values *vars)
{
	vars->olddirx = vars->dir.x;
	vars->dir.x = vars->dir.x * cos(-1 * TURN) - vars->dir.y * sin(-1 * TURN);
	vars->dir.y = vars->olddirx * sin(-1 * TURN) + vars->dir.y * cos(-1 * TURN);
	vars->oldplanex = vars->plane.x;
	vars->plane.x = vars->plane.x * cos(-1 * TURN) - vars->plane.y
		* sin(-1 * TURN);
	vars->plane.y = vars->oldplanex * sin(-1 * TURN) + vars->plane.y
		* cos(-1 * TURN);
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
				* (STEP_INTERVAL * 2))][(int)(vars->pos.y)] == '0')
			vars->pos.x -= vars->dir.x * STEP_INTERVAL;
		if (vars->map[(int)(vars->pos.x)][(int)(vars->pos.y
				- vars->dir.y * (STEP_INTERVAL * 2))] == '0')
			vars->pos.y -= vars->dir.y * STEP_INTERVAL;
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

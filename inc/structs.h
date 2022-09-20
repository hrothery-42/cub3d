/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:36:17 by hrothery          #+#    #+#             */
/*   Updated: 2022/09/20 08:57:46 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_coordinates
{
	double	x;
	double	y;
}	t_coordinates;

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}	t_color;

typedef struct s_values
{
	int		fd_no;
	int		fd_so;
	int		fd_we;
	int		fd_ea;
	t_color	floor;
	t_color	ceiling;
	char	**map;
	int		nr_rows;
	int		nr_columns;
}	t_values;

#endif
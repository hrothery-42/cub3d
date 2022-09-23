/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:36:17 by hrothery          #+#    #+#             */
/*   Updated: 2022/09/23 09:35:40 by hrothery         ###   ########.fr       */
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
	int		floor;
	int		ceiling;
	char	**map;
	int		nr_rows; //width
	int		nr_columns; //height
	int		nswefc[7]; //used for checking the input is not repeated or omitted, the last value is for error
	int		start_position;
	t_coordinates	plane;
	t_coordinates	dir;
	t_coordinates	pos;
	void	*t_tex[4];
}	t_values;

#endif
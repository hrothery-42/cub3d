/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:36:17 by hrothery          #+#    #+#             */
/*   Updated: 2022/09/20 15:34:52 by hrothery         ###   ########.fr       */
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
	int		nswefc[7]; //used for checking the input is not repeated or omitted, the last value is for error
	int		start_position;
}	t_values;

#endif
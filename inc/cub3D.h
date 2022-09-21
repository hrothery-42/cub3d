/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:47:09 by hrothery          #+#    #+#             */
/*   Updated: 2022/09/21 16:11:14 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef cub3D
# define cub3D
# include "structs.h"
# include "../mlx/mlx.h"
//only on Linux
#  include <X11/X.h>
#  include <X11/keysym.h>

# include <fcntl.h> //open, close, read
# include <stdio.h> //perror
# include <stdlib.h> //malloc, free, exit
# include <unistd.h> // write, read
# include <stdbool.h>
# include "../libft/libft.h"

//parser.c
int		parse_input(char *argv, t_values *vars);

//parser_utils.c
char	first_char(char *line);
void	replace_newline(char *line);
void	write_nswefc(t_values *vars, char *line);
bool	init_value(char *line, t_values *vars);

//parser_utils2.c
bool	save_color(char *color, t_color *l);
bool	check_map(t_values *vars);

//space_check.c
bool	left_border(int i, int j, t_values *vars);
bool	right_border(int i, int j, t_values *vars);
bool	top_border(int i, int j, t_values *vars);
bool	bottom_border(int i, int j, t_values *vars);
void	sort_data(t_values *vars, char *line, int *count, bool *ret);

//wall_check.c
bool	left_wall(int i, int j, t_values *vars);
bool	right_wall(int i, int j, t_values *vars);
bool	top_wall(int i, int j, t_values *vars);
bool	bottom_wall(int i, int j, t_values *vars);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:47:09 by hrothery          #+#    #+#             */
/*   Updated: 2022/09/23 09:56:14 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef cub3D
# define cub3D
# include "structs.h"
# include "../mlx/mlx.h"
//only on Linux
//#  include <X11/X.h>
//#  include <X11/keysym.h>

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
int		get_color(char *color, t_values *vars, int i);
bool	check_map(t_values *vars);

//parser_utils3.c
int		create_trgb(int t, int r, int g, int b);
void	sort_data(t_values *vars, char *line, int *count, bool *ret);
void	init_pos_and_dir(char c, t_values *vars, int i, int j);
bool	save_tex(char *pattern, t_values *vars, int i);

//space_check.c
bool	left_border(int i, int j, t_values *vars);
bool	right_border(int i, int j, t_values *vars);
bool	top_border(int i, int j, t_values *vars);
bool	bottom_border(int i, int j, t_values *vars);

//wall_check.c
bool	left_wall(int i, int j, t_values *vars);
bool	right_wall(int i, int j, t_values *vars);
bool	top_wall(int i, int j, t_values *vars);
bool	bottom_wall(int i, int j, t_values *vars);

//textures.c
//bool	save_tex(char *pattern, t_values *vars, int i)

#endif
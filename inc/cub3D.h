/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:47:09 by hrothery          #+#    #+#             */
/*   Updated: 2022/09/20 12:31:19 by hrothery         ###   ########.fr       */
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

#endif
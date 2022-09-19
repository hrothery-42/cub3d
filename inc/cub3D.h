/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:47:09 by hrothery          #+#    #+#             */
/*   Updated: 2022/09/19 17:36:01 by hrothery         ###   ########.fr       */
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
# include "../libft/libft.h"

//parser.c
int		parse_input(char *argv, t_values *val);

#endif
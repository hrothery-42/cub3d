/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:02:16 by hrothery          #+#    #+#             */
/*   Updated: 2021/12/19 11:30:37 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//outputs the string s followed by a new line.  To the given file 
//descriptor fd.

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

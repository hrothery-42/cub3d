/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:47:42 by hrothery          #+#    #+#             */
/*   Updated: 2021/12/18 22:09:26 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//tests for any printing character, including space. 

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (c);
	return (0);
}

/* #include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_isprint('r'));
	return (0);
}
 */
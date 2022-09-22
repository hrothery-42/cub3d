/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:46:43 by hrothery          #+#    #+#             */
/*   Updated: 2021/12/19 17:07:17 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//The bzero function erases the data in the n bytes of the memory starting 
//at the location pointed to by s, by writing zeros ('\0') to that area.

//#include <string.h>
//#include <stdio.h>

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = '\0';
		i++;
	}
}

// int	main(void)
//  {
// 	char str[35] = "We wish you a merry Christmas!";
// 	printf("str = %s\n", str);
// 	ft_bzero(str, 5);
// 	int	i = 0;
// 	while (i < 7)
// 	{
// 		printf("str + %d = %s\n", i, str + i);
// 		i++;
// 	}
// 	return (0);
// }

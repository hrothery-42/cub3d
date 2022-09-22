/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:13:27 by hrothery          #+#    #+#             */
/*   Updated: 2021/12/18 22:12:45 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//The memset function fills the first n bytes of the memory area pointed to
//by s with the constant byte c.  Returns a pointer to the memory area s.

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	long unsigned int	i;

	i = 0;
	while (i < n)
	{
		*(char *)(str + i) = c;
		i++;
	}
	return (str);
}

/* int	main(void)
{
	char str[50];
	strcpy(str, "We wish you a merry Christmas");
	puts(str);

	ft_memset(str, '*', 5);
	puts(str);

	return (0);
}
 */
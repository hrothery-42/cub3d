/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:39:39 by hrothery          #+#    #+#             */
/*   Updated: 2021/12/18 21:32:01 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//locate the first occurrence of c (converted to an unsigned char) in str s.
// returns a ptr to the byte located, or NULL if no such byte exists within 
//n bytes.

//#include <string.h>
//#include <stdio.h>

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}

/* int	main(void)
{
	printf("%s\n", (char *)(ft_memchr("hello", 'k', 5)));
	return (0);
} */

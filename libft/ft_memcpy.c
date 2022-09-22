/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 08:33:28 by hrothery          #+#    #+#             */
/*   Updated: 2021/12/09 11:06:39 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//The memcpy function copies n bytes from memory area src to memory area dst.  
//If dst and src overlap, behaviour is undefined.  
//The function memcpy returns the original value of dst.

//#include <string.h>
//#include <stdio.h>

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		*(char *)(dst + i) = *(char *)(src + i);
		i++;
	}
	return (dst);
}

/* int	main(void)
{
	int	j = 8;
	//char arr[50] = {"This is the way to copy memory"};
	char arr2[20] = {"0123456789"};
	char	*s1 = NULL;
	const char	*s2 = arr2;

	//char arr3[50] = {"This is the way to copy memory"};
	//char arr4[20] = {"0123456789"};
	//char	*s3 = NULL;
	//const char	*s4 = arr4;
	
	ft_memcpy(s1, s2, j);
	//memcpy(s3, s4, j);
	printf("ft_memcpy: replacing %d characters: \n\t%s\n", j, s1);
	//printf("memcpy: replacing %d characters: \n\t%s\n", j, s3);
	return (0);
} */

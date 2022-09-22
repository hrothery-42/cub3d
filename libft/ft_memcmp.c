/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:00:25 by hrothery          #+#    #+#             */
/*   Updated: 2021/12/19 17:50:00 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//compares the first n bytes (each interpreted as unsigned chars) of the 
//memory areas s1 and s2.  Returns an int less than, equal to, or greater
//than zero if the first n bytes of s1 are less than, match, or greater
//than the first n bytes of s2.  For a nonzero value, the sign is
//determined by the sign of the difference between the first pair of 
//bytes (interpreted as unsigned char) that differ in s1 and s2.  
//If n is zero, the return value is zero.

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s1 + i) != *(unsigned char *)(s2 + i))
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	int a;
// 	char *s1 = "hello";
// 	char *s2 = "h2llo";
// 	a = 2;
// 	printf("ft_memcmp:  result is %d\n", ft_memcmp(s1, s2, a));
// 	return (0);
// }
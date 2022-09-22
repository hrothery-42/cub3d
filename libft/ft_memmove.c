/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 08:39:34 by hrothery          #+#    #+#             */
/*   Updated: 2021/12/18 22:12:05 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The memmove function copies len bytes from string src to string dst.  
// The two strings may overlap; the copy is always done in a non_destructive
// manner.  The memmove function returns the original value of dst.

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!src && !dest)
		return (0);
	if (dest > src)
	{
		i = n;
		while (i-- != 0)
		*(char *)(dest + i) = *(const char *)(src + i);
	}
	else
	{
		i = 0;
		while (i < n)
		{
			*(char *)(dest + i) = *(const char *)(src + i);
			i++;
		}
	}
	return (dest);
}

/* int	main(void)
{
	int j = 6;;
	char s[11] = {"0123456789"};
	char *p1 = s;
	char *p2 = &s[1];
	ft_memmove(p1, p2, j);
	printf("ft_memmove: replacing the first %d characters:\n\t%s\n", j, s);
	return (0);
}
 */
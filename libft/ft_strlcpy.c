/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:51:27 by hrothery          #+#    #+#             */
/*   Updated: 2021/12/18 22:16:27 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Takes the full size of the bufer (not just the length) and guarantees to
NULL terminate the result (as long as size is larger than 0).  Note that a 
byte for NULL should be included in the size.  Copies up to size - 1 characters
from the NUL terminated string src to dest, NUL terminating the result.
Returns the total length of the string it tried to create.  That means the 
length of src. */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	result;

	i = 0;
	result = ft_strlen(src);
	if (n > 0)
	{
		while (src[i] && (i < (n - 1)))
		{
		dest[i] = src[i];
		i++;
		}
		dest[i] = '\0';
	}
	return (result);
}

/* int	main(void)
{
	char s[50] = "Tiger is a scaredy cat!";
	char s2[50] = "Garfield likes lasagne!";
	char *p = s;
	const char *p2 = s2;
	printf("%s\n", p);
	printf("%s\n", p2);
	printf("%ld\n", ft_strlcpy(p, p2, 0));
	printf("%s\n", p);
	return (0);
} */
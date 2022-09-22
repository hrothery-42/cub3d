/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:54:51 by hrothery          #+#    #+#             */
/*   Updated: 2021/12/18 22:16:00 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Concatenates strings.  Takes the full size of the buffer (not just the 
//length) and guarantees to NUL terminate the result (as long as size
//is larger than 0 or there is at least 1 byte free in dst.)  Note that 
//a byte for the NUL should be included in size.  Appends the NUL
//terminated string src to dst.  It will append at most size - strlen(dst)
// - 1 bytes, NUL terminating the result.  Returns the total length of the
//string they tried to create, that means the initial length of the dst
//plus the length of src.  Note that if strlcat traverses size characters
//without finding NUL the length of the string is size and the dst string
//will not be NUL terminated.  In practice this should not happen.

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	dest_length;
	size_t	size;

	dest_length = ft_strlen(dest);
	size = n - dest_length - 1;
	i = 0;
	if (n > 0 && dest_length < n)
	{
		while (src[i] && i < size)
		{
		dest[dest_length + i] = src[i];
		i++;
		}
		dest[dest_length + i] = '\0';
	}
	if (dest_length >= n)
		dest_length = n;
	return (dest_length + ft_strlen(src));
}

/* int	main(void)
{
	char s[50] = "Gar";
	char s2[50] = "field is hungry!";
	char *p = s;
	const char *p2 = s2;
	printf("%s\n", p);
	printf("%s\n", p2);
	ft_strlcat(s, s2, 0);
	printf("%s\n", s);
	return (0);
}
 */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:49:04 by hrothery          #+#    #+#             */
/*   Updated: 2021/12/19 10:28:00 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//applies the function f to each character of the string s.
//passing its index as first argument to create a new string with malloc.
//return the string created by the successive applcations of f.
//return NULL if the allocation fails.

//#include <stdio.h>
//#include <stdlib.h>

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*out_str;
	size_t	i;

	if (!s || !f)
		return ((char *)s);
	i = 0;
	out_str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!out_str)
		return (NULL);
	if (!s)
		return (NULL);
	while (s[i])
	{
		out_str[i] = f(i, s[i]);
		i++;
	}
	out_str[i] = '\0';
	return (out_str);
}

/* char	f(unsigned int i, char c)
{
	if (i % 2 == 0)
		c = 'f';
	return (c);
}

int	main(void)
{
	char	*str = "hello  42";
	printf("%s\n", ft_strmapi(str, f));
	return (0);
} */
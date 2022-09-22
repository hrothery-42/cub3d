/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:03:25 by hrothery          #+#    #+#             */
/*   Updated: 2021/12/21 11:53:33 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//locates the last occurrence of c in the string s.  If c is the end character,
// the function will return a pointer to the end of the string.

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c == '\0')
		return ((char *)(s + ft_strlen(s)));
	while (s[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char *return_ptr;
// 	char c = 'h';
// 	return_ptr = ft_strrchr("happy birthday!", c);
// 	printf("%s\n", c, return_ptr);
// 	return (0);
// }

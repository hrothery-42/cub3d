/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:35:40 by hrothery          #+#    #+#             */
/*   Updated: 2021/12/19 10:14:36 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// allocates with malloc and returns a new string, which is the result of the 
//concatenation of s1 and s2.
//returns the new string.  NULL if the allocation fails.

//#include <stdio.h>
#include "libft.h"

char	*ft_copystring(char const *s1, char const *s2, char *s3)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	return (s3);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out_str;

	if ((!s1 && !s2) || !s2)
		return ((char *)s1);
	if (!s1)
		return ((char *)s2);
	out_str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1)
			* sizeof(char));
	if (out_str == 0)
		return (NULL);
	out_str = ft_copystring(s1, s2, out_str);
	return (out_str);
}

/* int	main(void)
{
	char const *string = "hello";
	char const *string2 = " 42";
	printf("%s\n", ft_strjoin(string, string2));
	return (0);
} */
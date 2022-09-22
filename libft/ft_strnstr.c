/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 13:19:07 by hrothery          #+#    #+#             */
/*   Updated: 2022/01/28 12:36:51 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//locates the first occurrence of the null-terminated string s2 in the string 
// s1,
// where not more than n characters are searched.  Characters that appear after
//a '\0' character are not searched.  If s2 is an empty string, s1 is returned.
// if s2 occurs nowhere in s1, NULL is returned.  Otherwise, a ptr to the first 
//character of the first occurrence of s2 is returned.

//#include <stdio.h>

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	if (s2[0] == '\0')
	{
		return ((char *)s1);
	}
	i = 0;
	while (i < n && s1[i])
	{
		j = 0;
		while (s1[i + j] == s2[j] && i + j < n && s1[i + j])
			j++;
		if (s2[j] == '\0')
		{
			return ((char *)(s1 + i));
		}
		i++;
	}
	return (NULL);
}

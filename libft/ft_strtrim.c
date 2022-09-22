/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:54:40 by hrothery          #+#    #+#             */
/*   Updated: 2021/12/21 08:34:44 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//allocates with malloc and returns a copy of s1 with the characters in the 
//set removed from the beginning and end of the string.  Return the trimmed 
//string.  NULL if the allocation fails.

#include "libft.h"

static int	find_start(char const *s, char const *se)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (se[j] && s[i])
	{
		if (s[i] == se[j])
		{
			i++;
			j = -1;
		}
		j++;
	}
	return (i);
}

static char	*copy_string(char const *s, int start, int end)
{
	int		i;
	char	*out_str;

	out_str = (char *)malloc((end - start + 2) * sizeof(char));
	if (!out_str)
		return (NULL);
	i = 0;
	while (s + start + i <= s + end)
	{
		out_str[i] = s[start + i];
		i++;
	}
	out_str[i] = '\0';
	return (out_str);
}

char	*str_is_gone(char const *s1)
{
	char	*str;

	str = (char *)malloc(sizeof(char));
	str[0] = s1[ft_strlen(s1)];
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int			start;
	int			end;
	int			j;

	if (!s1)
		return (NULL);
	end = (int)ft_strlen(s1) - 1;
	start = (find_start(s1, set));
	if (start > end)
	{
		return (str_is_gone(s1));
	}
	j = 0;
	while (set[j] && end > 0)
	{
		if (s1[end] == set[j])
		{
			end--;
			j = -1;
		}
		j++;
	}
	return (copy_string(s1, start, end));
}

// #include <stdio.h>
// int	main(void)
// {
// 	printf("%s\n", ft_strtrim("hehehehhhe", "he"));
// 	return (0);
// }
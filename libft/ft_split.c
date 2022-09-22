/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:00:45 by hrothery          #+#    #+#             */
/*   Updated: 2021/12/21 11:47:09 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//allocates with malloc and returns an array of strings obtained
//by splitting string s using the character c as a delimiter.
//The array must be ended with a NULL pointer.

#include <stdio.h>
#include "libft.h"

static size_t	ft_wordlen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static size_t	ft_word_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			while (s[i] && s[i] != c)
				i++;
			count++;
		}
	}
	return (count);
}

static char	*ft_copy_word(char const *s, char c)
{
	size_t	i;
	char	*word;

	word = (char *)malloc((ft_wordlen(s, c) + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] != c && s[i])
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		j;
	char		**out_arr;

	if (!s)
		return (NULL);
	out_arr = (char **)malloc((ft_word_count(s, c) + 1) * sizeof(char *));
	if (!out_arr)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			out_arr[j] = ft_copy_word(s + i, c);
			j++;
			i = i + ft_wordlen(s + i, c);
		}
	}
	out_arr[j] = NULL;
	return (out_arr);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	*s = "out";
// 	char	**out;
// 	size_t	i;
// 	char	c = ' ';
// 	i = 0;
// 	printf("There are %ld words in the string\n", ft_word_count(s, c));
// 	out = ft_split(s, c);
// 	while (i <= ft_word_count(s, c))
// 	{	
// 		printf("%s\n", *(out + i));
// 		i++;
// 	}
// 	free(out);
// 	return (0);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:09:41 by hrothery          #+#    #+#             */
/*   Updated: 2021/12/21 09:45:13 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//subst returns the new string starting from s[start] and with maximum length 
// len.  Return NULL if the allocation fails.

//#include <stdio.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*pstr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < len)
		pstr = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	else
		pstr = (char *)malloc((len + 1) * sizeof(char));
	if (!pstr)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			pstr[j] = s[i];
			j++;
		}
		i++;
	}
	pstr[j] = '\0';
	return (pstr);
}

/* int	main(void)
{
	char *p;
	char const *s = "at school 42";

	p = ft_substr(s, 3, 6);
	printf("%s\n", p);
	free (p);
	return (0);
}
 */
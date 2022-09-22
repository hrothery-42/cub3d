/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:08:52 by hrothery          #+#    #+#             */
/*   Updated: 2021/12/18 22:15:24 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//allocates sufficient memory for a copy of the string s, and returns a pointer
//to it.  The pointer may be used as an argument to the function free.
// If insufficient memory is available, NULL is returned and errno is set to 
//ENOMEM.

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*pstr;

	i = 0;
	while (s[i])
	{
		i++;
	}
	pstr = (char *)malloc((i + 1) * sizeof(char));
	if (!pstr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		pstr[i] = s[i];
		i++;
	}
	pstr[i] = '\0';
	return (pstr);
}

/* int	main(void)
{
	char *ptr = "one two three!";
	printf("%p %s\n", ptr, ptr);
	printf("%p %s\n", ft_strdup(ptr), ft_strdup(ptr));
	free (ft_strdup(ptr));
	return (0);
}
 */
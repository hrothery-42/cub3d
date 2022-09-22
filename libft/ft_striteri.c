/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:46:57 by hrothery          #+#    #+#             */
/*   Updated: 2021/12/13 10:39:06 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Applies the function f to each character of the string passed as argument
// and passing its index as first argument.  Each character is passed by 
//address to f to be modified if necessary.

//#include <stdio.h>

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}

/* void	f(unsigned int i, char *s)
{
	if (i % 2 == 0)
		s[0] = 'f';
}

int	main(void)
{
	char str[10] = "Hello 42!";
	ft_striteri(str, f);
	printf("%s\n", str);
	return (0);
}  */
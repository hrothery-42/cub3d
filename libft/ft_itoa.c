/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 18:21:20 by hrothery          #+#    #+#             */
/*   Updated: 2021/12/18 12:13:04 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//allocates with malloc and returns a string representing the integer 
//received as an argument.  Negative numbers must be handled.
//Return the string representing the integer.  NULL if the allocation fails.

#include <stdio.h>
#include <stdlib.h>

#include "libft.h"

int	len(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n = n * -1;
	}
	while (n > 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char	*ft_str(char *s, long n, int i)
{
	s[i--] = '\0';
	if (n == 0)
	{
		s[0] = '0';
		return (s);
	}
	if (n < 0)
	{
		s[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		s[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*out_str;
	long	nbr;

	nbr = n;
	out_str = (char *)malloc((len(n) + 1) * sizeof(char));
	if (!out_str)
		return (NULL);
	out_str = ft_str(out_str, nbr, len(n));
	return (out_str);
}

/* int	main(void)
{
	int	number;

	number = 120;
	printf("len of n is %d\n", len(number));
	printf("The char string %d is %s\n", number, ft_itoa(number));
	return (0);
}
 */
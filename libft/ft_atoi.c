/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:48:59 by hrothery          #+#    #+#             */
/*   Updated: 2022/02/07 08:36:19 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The atoi function converts the initial portion of the string pointed to 
// by nptr to int, and returns the converted value.
#include "libft.h"

static int	ft_putn(char *p)
{
	int	i;
	int	nbr;

	i = 0;
	if (p[i] >= '0' && p[i] <= '9')
	{
		nbr = (p[i] - '0');
		i++;
	}
	else
		return (0);
	while (p[i] <= '9' && p[i] >= '0')
	{
		nbr = (nbr * 10) + (p[i] - '0');
		i++;
	}
	return (nbr);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	n;
	int	neg_value;

	i = 0;
	n = 0;
	neg_value = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			neg_value = -1;
		i++;
	}
	n = ft_putn((char *)(nptr + i));
	return (n * neg_value);
}

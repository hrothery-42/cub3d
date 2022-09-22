/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:33:17 by hrothery          #+#    #+#             */
/*   Updated: 2021/12/18 22:07:29 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// the isalpha function tests for any character for which isupper or islower is 
// true. The value of the argument must be representable as an unsigned char or 
// the value of EOF. The function returns 0 if the character tests false and 
// returns non-zero if the function tests true.

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (c);
	return (0);
}

/* int	main(void)
{
	char c;

	c = '=';
	printf("ft_isalpha(%c) = %d\n", c, ft_isalpha(c));
	c = 'A';
	printf("ft_isalpha(%c) = %d\n", c, ft_isalpha(c));
	c = '7';
	printf("ft_isalpha(%c) = %d\n", c, ft_isalpha(c));
	c = 'r';
	printf("ft_isalpha(%c) = %d\n", c, ft_isalpha(c));
}
 */
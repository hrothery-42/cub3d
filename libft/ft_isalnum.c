/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:12:39 by hrothery          #+#    #+#             */
/*   Updated: 2021/12/18 22:06:37 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// tests for any character for which isalpha or isdigit is true. Returns 0 if 
//false and non-zero if true.

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (c);
	return (0);
}

/* int	main(void)
{
	printf("%d\n", ft_isalnum('L'));
	return (0);
}
 */
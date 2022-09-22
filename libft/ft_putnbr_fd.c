/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:12:50 by hrothery          #+#    #+#             */
/*   Updated: 2021/12/13 09:43:08 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Outputs the integer n to the given file descriptor.  Uses write function.

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n = n * -1;
		ft_putchar_fd('-', fd);
	}
	nbr = n;
	if (nbr < 10)
	{
		ft_putchar_fd((char)n + '0', fd);
		return ;
	}
	if (nbr >= 10)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putnbr_fd(nbr % 10, fd);
	}
}

/* int	main(void)
{
	ft_putnbr_fd(-2147483648, 1);
	write (1, "\n", 1);
	return (0);
}
 */
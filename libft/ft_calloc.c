/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:07:23 by hrothery          #+#    #+#             */
/*   Updated: 2021/12/18 21:28:11 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The calloc function allocates memory for an array of nmemb elements of size 
bytes each and returns a pointer to the allocated memory.  The memory is set 
to zero.  If nmemb or size is 0, then calloc returns either NULL, or a 
unique pointer valuethat can later be successfully passed to free().  
If the multiplication of nmemb and size would result in integer overflow, 
then calloc returns an error.  By contrast, an integer overflow would not be 
detected in malloc with the result that an incorrectly sized block
of memory would be allocated. */

#include <stdlib.h>
#include <stdio.h>

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

/* int	main(void)
{
	int *ptr;
	ptr = ft_calloc(0, sizeof(int));
	printf("%ls\n", ptr);
	free (ptr);
	return (0);
}
 */
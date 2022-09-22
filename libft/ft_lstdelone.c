/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:53:11 by hrothery          #+#    #+#             */
/*   Updated: 2021/12/16 14:14:46 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Takes as a parameter an element and frees the memory of the element's
//content using the function 'del' given as a parameter and free the 
//element.  The memory of 'next' must not be freed. Parameter one:
// the element to free.  Parameter two: The address of the function
//used to delete the content.

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	del(lst->content);
	free(lst);
}

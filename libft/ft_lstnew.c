/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:00:36 by hrothery          #+#    #+#             */
/*   Updated: 2021/12/19 17:09:26 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Allocates with malloc and returns a new element.  The variable 'content'
//is initialized with the value of the parameter 'content'.  The variable
//'next' is initialized to NULL.

//#include <stdio.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_elem;

	new_elem = malloc(sizeof(t_list));
	if (!new_elem)
		return (NULL);
	new_elem->content = content;
	new_elem->next = NULL;
	return (new_elem);
}

// int	main(void)
// {
// 	char str[10] = "hello 42!";
// 	t_list	*elem;

// 	elem = ft_lstnew(str);
// 	printf("%s\n", (char *)elem->content);
// 	return (0);
// } 
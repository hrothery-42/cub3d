/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:39:11 by hrothery          #+#    #+#             */
/*   Updated: 2021/12/18 14:01:24 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//returns the last element of the list.  The parameter points to the first
//element.

#include <stdio.h>

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/* int	main(void)
{
	t_list *one;
	t_list *two;
	t_list *three;
	one = malloc(sizeof(t_list));
	two = malloc(sizeof(t_list));
	three = malloc(sizeof(t_list));

	one->content = "1";
	two->content = "2";
	three->content = "3";
	one->next = two;
	two->next = three;
	three->next = NULL;
	printf("%s\n", (char *)(ft_lstlast(one))->content);
	return (0);
} */
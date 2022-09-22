/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:28:39 by hrothery          #+#    #+#             */
/*   Updated: 2021/12/18 13:57:49 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//counts the number of elements in a list. *lst is the beginning of the list.
//returns the length of the list.

#include <stdio.h>
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
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
	printf("%d\n", ft_lstsize(one));
	return (0);
} */
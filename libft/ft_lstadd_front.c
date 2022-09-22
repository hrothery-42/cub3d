/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:12:07 by hrothery          #+#    #+#             */
/*   Updated: 2021/12/18 13:56:43 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Adds the element 'new' at the beginning of the list
//The first parameter is the address of a pointer to the first link of a list
//The second parameter is the address of a pointer to the element to be added
//to the list.

#include <stdio.h>

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

/* void	print_list(t_list *head)
{
	t_list	*current;
	
	current = head;
	if (head == NULL)
		printf("list is empty\n");
	printf("printing list:\n");
	while (current != NULL)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
}

int	main(void)
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
	one->next = NULL;
	two->next = three;
	three->next = NULL;
	print_list(two);
	ft_lstadd_front(&two, one);
	print_list(one);
	return (0);
} 
  */
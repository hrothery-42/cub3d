/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:45:32 by hrothery          #+#    #+#             */
/*   Updated: 2021/12/18 14:02:21 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// adds the element 'new' at the end of the list.  Parameter one is the
//address of a pointer to the first link of a  list.  Paramter two is the
//address of a pointer to the element to be added to the list.

#include <stdio.h>
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		new->next = NULL;
		return ;
	}
	while (last->next)
		last = last->next;
	last->next = new;
	new->next = NULL;
}

/* void	print_list(t_list *head)
{
	t_list	*current;
	
	current = head;
	if (head == NULL)
		printf("list is empty\n");
	printf("\nprinting list:\n");
	while (current != NULL)
	{
		printf("   %s   ", (char *)current->content);
		current = current->next;
	}
	printf("\n");
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
	one->next = two;
	two->next = NULL;
	three->next = NULL;
	print_list(one);
	ft_lstadd_back(&one, three);
	print_list(one);
	return (0);
} */
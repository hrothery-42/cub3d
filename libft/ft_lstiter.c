/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:18:53 by hrothery          #+#    #+#             */
/*   Updated: 2021/12/18 18:58:19 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Iterates the list lst and applies the function f to the content of each
//element.  

#include <stdio.h>

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{	
	if (!lst)
		return ;
	while (lst->next)
	{
		f(lst->content);
		lst = lst->next;
	}	
	f(lst->content);
}

/* void	f(void *ptr)
{
	printf("%s    ", (char *)ptr);
}

void	print_list(t_list *head)
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

	one->content = "10";
	two->content = "20";
	three->content = "30";
	one->next = two;
	two->next = three;
	three->next = NULL;
	print_list(one);
	ft_lstiter(one, &f);
	print_list(one);
	return (0);
} 
 */
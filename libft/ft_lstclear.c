/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:39:25 by hrothery          #+#    #+#             */
/*   Updated: 2021/12/21 11:54:00 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//deletes and frees the given element and every successor of that element
//using the function *del and free.Finally, the ptr on the list must be set
//to NULL.

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!*lst)
		return ;
	while ((*lst)->next)
	{
		temp = (*lst)->next;
		del(*lst);
		*lst = temp;
	}
	del(*lst);
	*lst = (NULL);
}

// #include <stdio.h>
// #include <stdlib.h>
// void	del(void *ptr)
// {
// 	free(ptr);
// }
// void	print_list(t_list *head)
// {
// 	t_list	*current;
// 	current = head;
// 	if (head == NULL)
// 	{
// 		printf("list is empty\n");
// 		return ;
// 	}
// 	printf("\nprinting list:\n");
// 	while (current != NULL)
// 	{
// 		printf("   %s   ", current->content);
// 		current = current->next;
// 	}
// 	printf("\n");
// }
// int	main(void)
// {
// 	t_list *one;
// 	t_list *two;
// 	t_list *three;
// 	one = malloc(sizeof(t_list));
// 	two = malloc(sizeof(t_list));
// 	three = malloc(sizeof(t_list));
// 	one->content = "1";
// 	two->content = "2";
// 	three->content = "3";
// 	one->next = two;
// 	two->next = three;
// 	three->next = NULL;
// 	print_list(one);
// 	ft_lstclear(&one, del);
// 	print_list(one);
// 	return (0);
// }
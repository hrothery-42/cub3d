/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:19:44 by hrothery          #+#    #+#             */
/*   Updated: 2021/12/19 17:40:04 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Iterates the list lst and applies the function f to each element.
//To creat a new list. Using del if necessary.  Return the new list, 
//NULL if the allocation has failed.

//#include <stdio.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*tail;

	head = malloc(sizeof(t_list));
	tail = malloc(sizeof(t_list));
	if (!head || !tail || (!head && !tail) || !lst || !f)
		return (NULL);
	head = ft_lstnew(f(lst->content));
	if (head == NULL)
	{
		ft_lstclear(&head, del);
		return (NULL);
	}
	tail = head;
	while (lst->next)
	{
		lst = lst->next;
		tail->next = ft_lstnew(f(lst->content));
		tail = tail->next;
	}
	return (head);
}

// void	del(void *ptr)
// {
// 	free(ptr);
// }
//
// void	*f(void *ptr)
// {
// 	char	*out_str;
// 	int		i;
//
// 	i = 0;
// 	out_str = (char *)(malloc(ft_strlen((char *)(ptr)) + 1 * sizeof(char)));
// 	if (!out_str)
// 		return (NULL);
// 	while (*(char *)(ptr + i))
// 	{
// 		if (i % 2 == 0)
// 			out_str[i] = 'f';
// 		else
// 			out_str[i] = *(char *)(ptr + i);
// 		i++;
// 	}
// 	return ((void *)out_str);
// }
//
// void	print_list(t_list *head)
// {
// 	t_list	*current;
//
// 	current = head;
// 	if (head == NULL)
// 		printf("list is empty\n");
// 	printf("\nprinting list:\n");
// 	while (current != NULL)
// 	{
// 		printf("   %s   ", (char *)current->content);
// 		current = current->next;
// 	}
// 	printf("\n");
// }
//
// int	main(void)
// {
// 	t_list *one;
// 	t_list *two;
// 	t_list *three;
// 	t_list *four;
// 	one = malloc(sizeof(t_list));
// 	two = malloc(sizeof(t_list));
// 	three = malloc(sizeof(t_list));
// 	four = malloc(sizeof(t_list));
// 	one->content = "111111";
// 	two->content = "222222";
// 	three->content = "333333";
// 	one->next = two;
// 	two->next = three;
// 	three->next = NULL;
// 	print_list(one);
// 	four = ft_lstmap(one, f, del);
// 	print_list(four);
// 	print_list(one);
// 	free(four);
// 	return (0);
// }
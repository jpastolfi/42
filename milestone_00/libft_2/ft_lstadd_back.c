/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 12:23:05 by jastolfi          #+#    #+#             */
/*   Updated: 2026/04/24 11:06:25 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (!lst)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	node = *lst;
	while (node->next)
	{
		node = node->next;
	}
	node->next = new;
}

/* int main(void)
{
	t_list *first = ft_lstnew("first");
	t_list *second = ft_lstnew("second");
	t_list *third = ft_lstnew("third");
	t_list *fourth = ft_lstnew("fourth");
	first->next = second;
	second->next = third;
	third->next = fourth;
	fourth->next = NULL;
	printf("Last element: %s\n", (char *)ft_lstlast(first)->content);
	t_list *fifth = ft_lstnew("fifth");
	ft_lstadd_back(&first, fifth);
	printf("Last element: %s\n", (char *)ft_lstlast(first)->content);
	ft_lstadd_back(&first, NULL);
	printf("Last after adding NULL: %s\n", (char *)ft_lstlast(first)->content);
} */

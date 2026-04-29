/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 12:23:13 by jastolfi          #+#    #+#             */
/*   Updated: 2026/04/24 16:59:34 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*ptr;

	if (!lst)
		return ;
	node = *lst;
	while (node)
	{
		ptr = node->next;
		del(node->content);
		free(node);
		node = ptr;
	}
	*lst = NULL;
}

/* void del(void *ptr)
{
	printf("Insert a delete function here to delete %p\n", ptr);
}

int main(void)
{
	t_list *first = ft_lstnew("first");
	printf("first content: %s\n", (char *)first->content);
	ft_lstclear(&first, &del);
	ft_lstclear(NULL, &del);
	printf("Is first NULL? %s\n", first == NULL ? "Yes" : "No");
} */
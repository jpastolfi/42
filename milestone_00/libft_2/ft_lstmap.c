/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 12:23:25 by jastolfi          #+#    #+#             */
/*   Updated: 2026/04/24 17:00:54 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	void	*new_content;
	t_list	*new_node;

	result = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, new_node);
		lst = lst->next;
	}
	return (result);
}

/* void *f(void *ptr)
{
	char *new_content = ft_strdup((char *)ptr);
	new_content[0]++;
	return (new_content);
}

void del(void *ptr)
{
	printf("%s\n", (char *)ptr);
}

int main(void)
{
	t_list *first = ft_lstnew("0");
	t_list *second = ft_lstnew("1");
	t_list *third = ft_lstnew("2");
	t_list *fourth = ft_lstnew("3");
	first->next = second;
	second->next = third;
	third->next = fourth;
	fourth->next = NULL;
	t_list *teste = ft_lstmap(first, f, del);
	while(teste)
	{
		printf("%s\n", (char *)teste->content);
		teste = teste->next;
	}
} */
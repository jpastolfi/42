/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 12:23:20 by jastolfi          #+#    #+#             */
/*   Updated: 2026/04/24 16:59:51 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/* void f(void *ptr)
{
	printf("%s\n", (char *)ptr);
}

int main(void)
{
	t_list *first = ft_lstnew("first");
	t_list *second = ft_lstnew("second");
	t_list *third = ft_lstnew("third");
	t_list *fourth = ft_lstnew("fourth");
	first->next = second;
	second->next = third;
	third->next = fourth;
	fourth->next = NULL;
	ft_lstiter(first, f);
} */
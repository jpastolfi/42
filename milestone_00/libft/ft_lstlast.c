/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 12:23:23 by jastolfi          #+#    #+#             */
/*   Updated: 2026/04/24 11:05:17 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
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
	printf("Last item: %s\n", (char *)ft_lstlast(first)->content);
	printf("Last item of NULL: %s\n", (char *)ft_lstlast(NULL));
} */
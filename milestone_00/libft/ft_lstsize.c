/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 12:23:28 by jastolfi          #+#    #+#             */
/*   Updated: 2026/04/24 11:07:02 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_lstsize(t_list *lst)
{
	int	counter;

	counter = 0;
	while (lst)
	{
		counter++;
		lst = lst->next;
	}
	return (counter);
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
	printf("first->content: %s\n", (char *)first->content);
	printf("first->next: %p\n", first->next);
	printf("second address: %p\n", second);
	printf("second->content: %s\n", (char *)second->content);
	printf("second->next: %p\n", second->next);
	printf("third address: %p\n", third);
	printf("third->content: %s\n", (char *)third->content);
	printf("third->next: %p\n", third->next);
	printf("fourth address: %p\n", fourth);
	printf("fourth->content: %s\n", (char *)fourth->content);
	printf("fourth->next: %p\n", fourth->next);
	printf("Length: %d\n", ft_lstsize(first));
	t_list *fifth = ft_lstnew("fifth");
	ft_lstadd_front(&first, fifth);
	printf("Length: %d\n", ft_lstsize(first));
} */
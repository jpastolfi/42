/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 12:23:08 by jastolfi          #+#    #+#             */
/*   Updated: 2026/04/22 16:43:07 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/* int main(void)
{
	t_list *first = ft_lstnew("Ola");
	t_list *second = ft_lstnew("Tchau");
	printf("first before call: %s\n", (char *)first->content);
	printf("second before call: %s\n", (char *)second->content);
	ft_lstadd_front(&first, second);
	printf("first after call: %s\n", (char *)first->content);
	printf("second after call: %s\n", (char *)first->next->content);
} */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 15:31:56 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/05/05 18:22:38 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
// 17. t_lst **list -------------- A -> B -> C -> NULL
// 21. Linked list or the node must not be NULL
// 23. If the list exist but there's no node
// 25. then the first node of the list should be new node
// 28. last = ft_lstlast(*lst)---- last node = C
// 29. last->next = new ---------- A -> B -> C -> N

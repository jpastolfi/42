/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 16:00:24 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/05/05 18:22:46 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*next;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		del(current->content);
		next = current->next;
		free(current);
		current = next;
	}
	*lst = NULL;
}
// 19. One variable to the current head node, the other to the current->next
// 20. While current is not NULL, 27. Delete current node content.
// 28. Point the next variable to the current->next
// 29. Free current node. 30 Now the variable current is the next.

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 17:37:22 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/05/05 18:23:00 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
// 17. Receives one list, then apply a funtion to modify every node content.
// 17. In case of error another function (del), frees the content and the list
// 17. The function should return the first node of the new list created
// 19. Variable = The new node for the list to be created
// 20. Variable = The new node created to be added in the new list
// 21. Variable = The new transformed content to be inserted in the new node
// 23. Guards = If any argument is NULL stops the function
// 25. The new_lst should initialize with NULL so addback and lstclear works
// 27. Iterates through every node of the original list until NULL
// 28. Applies f to current node content, storing the transformed result
// 29. Attempts to create a new node with the transformed content
// 30. If ft_lstnew malloc fails:
// 32. Frees the new_content that f just created (no owner = memory leak)
// 33. Frees all nodes already added to new_lst
// 34. Returns NULL to signal allocation failure
// 36. Adds the new node to the end of the new list
// 37. Advances to the next node of the original list
// 39. Returns the fully constructed new list

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 13:42:33 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/05/05 18:22:49 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 23. Delete (free) the node content
// 24. Free the node itself;
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/* 
void	del_content(void *content);

int	main(void)
{
	t_list	*lst1;
	char	*str1;

	str1 = ft_strdup("TESTING");
	lst1 = ft_lstnew(str1);
	printf("%s\n", (char *)lst1->content);
	ft_lstdelone(lst1, del_content);
	return (0);
}

void	del_content(void *content)
{
	free(content);
} */

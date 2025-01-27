/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:19:11 by ksorokol          #+#    #+#             */
/*   Updated: 2024/09/19 11:27:21 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*new;

	if (!lst || !f || !del)
		return (NULL);
	tmp1 = lst;
	new = NULL;
	while (tmp1)
	{
		tmp2 = ft_lstnew (f (tmp1->content));
		if (!tmp2)
		{
			ft_lstclear (&new, del);
			return (NULL);
		}
		if (!new)
			new = tmp2;
		else
			ft_lstlast (new)->next = tmp2;
		tmp1 = tmp1->next;
	}
	return (new);
}

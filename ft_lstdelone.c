/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:58:57 by ksorokol          #+#    #+#             */
/*   Updated: 2024/10/08 23:52:37 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del (lst->content);
	if (lst->prev)
		lst->prev->next = lst->next;
	if (lst->next)
		lst->next->prev = lst->prev;
	free (lst);
	lst = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:33:12 by ksorokol          #+#    #+#             */
/*   Updated: 2024/10/07 19:38:08 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newt_list;

	newt_list = (t_list *) malloc (sizeof (t_list));
	if (!newt_list)
		return (NULL);
	newt_list->prev = NULL;
	newt_list->next = NULL;
	newt_list->content = content;
	return (newt_list);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgetidx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:25:58 by ksorokol          #+#    #+#             */
/*   Updated: 2024/10/09 21:41:56 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstgetidx(t_list *lst, t_list *slst)
{
	t_list	*tmp;
	int		cntr;

	cntr = 0;
	tmp = lst;
	while (tmp && tmp->next)
	{
		if (tmp == slst)
			return (cntr);
		cntr++;
		tmp = tmp->next;
	}
	return (cntr);
}

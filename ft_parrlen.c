/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:05:47 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/24 15:12:46 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

size_t	ft_parrsize(void *p_arr)
{
	size_t	idx;
	void 	*p_arr_;

	idx = 0;
	p_arr_ = p_arr;
	while (p_arr)
	{
		p_arr_++;
		idx++;
	}
	return (idx);
}

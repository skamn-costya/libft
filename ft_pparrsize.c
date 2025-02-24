/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pparrsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:42:56 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/24 16:21:46 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_pparrsize(void **pp_arr)
{
	size_t	idx;
	void	**pp_arr_;

	idx = 0;
	pp_arr_ = pp_arr;
	while (pp_arr_ && *pp_arr_)
	{
		idx++;
		pp_arr_++;
	}
	return (idx);
}

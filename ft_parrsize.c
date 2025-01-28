/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parrsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:42:56 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/28 19:16:45 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_parrsize(void **pp_mem)
{
	size_t	result;
	void	**pp_mem_;

	result = 0;
	pp_mem_ = pp_mem;
	while (*pp_mem_)
	{
		result++;
		pp_mem_++;
	}
	return (result);
}

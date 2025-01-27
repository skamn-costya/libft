/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parrclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:02:53 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/27 23:37:21 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_parrclear(void **pp_mem)
{
	size_t	idx;

	if (!pp_mem)
		return ;
	if (!pp_mem[0])
		return (free (pp_mem));
	idx = 0;
	while (pp_mem[idx])
	{
		free (pp_mem[idx]);
		idx++;
	}
	free (pp_mem);
}

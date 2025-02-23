/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_powf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:59:18 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/23 16:22:21 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

float	ft_powf(int x, int y)
{
	float	result;
	int		idx;

	if (y == 0)
		return (1);
	result = 1;
	idx = ft_abs(y);
	while (idx > 0)
	{
		result *= x;
		idx--;
	}
	if (y < 0)
		result = 1.f / result;
	return (result);
}

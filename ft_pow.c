/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:59:18 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/27 22:26:35 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

long	ft_pow(int x, unsigned int y)
{
	long long	result;

	if (y == 0)
		return (1);
	result = 1;
	while (y > 0)
	{
		result *= x;
		y--;
	}
	if (result < LONG_MIN || result > LONG_MAX)
		return (0);
	return (result);
}

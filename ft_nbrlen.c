/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 09:33:11 by ksorokol          #+#    #+#             */
/*   Updated: 2024/10/03 12:20:22 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_nbrlen(long long ll)
{
	int		i;

	i = 0;
	if (ll == 0)
		return (1);
	if (ll == LLONG_MIN)
		return (20);
	if (ll == LLONG_MAX)
		return (19);
	if (ll < 0)
	{
		i++;
		ll *= -1;
	}
	while (ll)
	{
		i++;
		ll = ll / 10;
	}
	return (i);
}

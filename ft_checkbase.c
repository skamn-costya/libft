/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkbase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:08:48 by ksorokol          #+#    #+#             */
/*   Updated: 2024/09/20 23:43:19 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checkbase(char *base)
{
	int	l1;
	int	l2;

	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	l1 = 0;
	while (base[l1])
	{
		if (base[l1] == ' ' || base[l1] == '+' || base[l1] == '-')
			return (0);
		if (base[l1] >= 9 && base[l1] <= 13)
			return (0);
		if (base[l1] > 126)
			return (0);
		l2 = l1 + 1;
		while (base[l2])
		{
			if (base[l1] == base[l2])
				return (0);
			l2++;
		}
		l1++;
	}
	return (1);
}

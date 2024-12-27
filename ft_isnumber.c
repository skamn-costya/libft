/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:50:45 by ksorokol          #+#    #+#             */
/*   Updated: 2024/10/23 22:45:32 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnumber(char *s)
{
	int	idx;

	if (!s)
		return (0);
	idx = 0;
	if (s[idx] == '-' || s[idx] == '+')
		idx++;
	while (s[idx])
	{
		if (!ft_isdigit (s[idx]))
			return (0);
		idx++;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxnumber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 22:30:21 by ksorokol          #+#    #+#             */
/*   Updated: 2024/10/23 22:42:44 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isxnumber(char *s)
{
	int	idx;

	if (!s)
		return (0);
	idx = 0;
	if (s[idx] == '0' && s[idx + 1] && (s[idx + 1] == 'x' || s[idx + 1] == 'X'))
		idx += 2;
	while (s[idx])
	{
		if (!ft_isxdigit (s[idx]))
			return (0);
		idx++;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:45:57 by ksorokol          #+#    #+#             */
/*   Updated: 2024/10/17 18:11:44 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static void	ft_atol_sign(char *str, int *idx, int *sign);

long	ft_atol(const char *nptr)
{
	char		*str;
	int			sign;
	long long	result;
	int			idx;

	str = ft_strtrim (nptr, " \f\n\r\t\v");
	if (!str)
		return (0);
	if (ft_strlen (str) == 0)
		return (free (str), 0);
	idx = 0;
	ft_atol_sign (str, &idx, &sign);
	result = 0;
	while (str[idx])
	{
		if (!ft_isdigit (str[idx]))
			break ;
		result = result * 10 + (str[idx] - '0');
		idx++;
	}
	if ((result * sign) > LONG_MAX || (result * sign) < LONG_MIN)
		return (free (str), 0);
	return (free (str), result * sign);
}

static void	ft_atol_sign(char *str, int *idx, int *sign)
{
	*sign = 1;
	if (*str == '-')
	{
		*sign = -1;
		(*idx)++;
	}
	else if (*str == '+')
		(*idx)++;
}

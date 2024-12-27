/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 00:13:18 by ksorokol          #+#    #+#             */
/*   Updated: 2024/10/08 13:33:10 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static void	ft_atoi_sign(char *str, int *idx, int *sign);

int	ft_atoi(const char *nptr)
{
	char		*str;
	int			sign;
	long long	result;
	int			idx;

	str = ft_strtrim (nptr, " \f\n\r\t\v");
	if (!str)
		return (0);
	if (ft_strlen (str) == 0)
		return (0);
	idx = 0;
	ft_atoi_sign (str, &idx, &sign);
	result = 0;
	while (str[idx])
	{
		if (!ft_isdigit (str[idx]))
			return (free (str), result * sign);
		result = result * 10 + (str[idx] - '0');
		idx++;
	}
	if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
		return (free (str), 0);
	return (free (str), result * sign);
}

static void	ft_atoi_sign(char *str, int *idx, int *sign)
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

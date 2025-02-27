/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 00:13:18 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/23 18:39:07 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static void		ft_atof_sign(char *str, int *idx, int *sign);
static float	mantisa(char *str, int idx, float result);
static float	e(char *str, int idx, float result);

float	ft_atof(const char *nptr)
{
	char	*str;
	int		sign;
	float	result;
	int		idx;

	str = ft_strtrim (nptr, " \f\n\r\t\v");
	if (!str || ft_strlen (str) == 0)
		return (0);
	idx = 0;
	ft_atof_sign (str, &idx, &sign);
	result = 0;
	while (str[idx] && str[idx] != '.')
	{
		if (!ft_isdigit (str[idx]))
			return (free (str), result * sign);
		result = result * 10 + (str[idx] - '0');
		idx++;
	}
	if (str[idx++] == '.')
	result = mantisa (str, idx, result);
	result *= sign;
	return (free (str), result);
}

static void	ft_atof_sign(char *str, int *idx, int *sign)
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

static float	mantisa(char *str, int idx, float result)
{
	int		y;
	float	pow;

	y = 1;
	while (str[idx])
	{
		if (!ft_isdigit (str[idx]))
		{
			if (str[idx] == 'e' || str[idx] == 'E')
				return (e(str, ++idx, result));	
			return (result);
		}
		pow = ft_pow (10, y);
		result += ((str[idx] - '0') / pow);
		idx++;
		y++;
	}
	return (result);
}

static float	e(char *str, int idx, float result)
{
	int pow;

	pow = ft_atoi(&str[idx]);
	result *= ft_powf(10, pow);
	return (result);
}

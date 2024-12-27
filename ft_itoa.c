/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 22:57:53 by ksorokol          #+#    #+#             */
/*   Updated: 2024/09/20 12:02:37 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ilen(long l);
static char	*ft_recursion(long l, char *pstr, size_t *pidx);

char	*ft_itoa(int n)
{
	char	*newstr;
	size_t	idx;
	long	l;

	newstr = (char *) ft_calloc (ft_ilen(n) + 1, sizeof (char));
	if (!newstr)
		return (NULL);
	l = (long) n;
	idx = 0;
	if (l < 0)
	{
		newstr[0] = '-';
		l *= -1;
		idx++;
	}
	ft_recursion (l, newstr, &idx);
	return (newstr);
}

static int	ft_ilen(long l)
{
	int		i;

	i = 0;
	if (l == 0)
		return (1);
	if (l < 0)
	{
		i++;
		l *= -1;
	}
	while (l)
	{
		i++;
		l = l / 10;
	}
	return (i);
}

static char	*ft_recursion(long l, char *pstr, size_t *pidx)
{
	if (l / 10)
		ft_recursion (l / 10, pstr, pidx);
	pstr[*pidx] = l % 10 + '0';
	(*pidx)++;
	return (pstr);
}

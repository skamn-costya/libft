/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:27:07 by ksorokol          #+#    #+#             */
/*   Updated: 2024/09/21 00:07:50 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_recursion(char *str, unsigned long ul, char *base, int len);

char	*ft_uitoa_base(unsigned int nbr, char *base)
{
	char			*str;

	if (!ft_checkbase (base))
		return (NULL);
	str = (char *) ft_calloc (sizeof(char), 1);
	str = ft_recursion (str, nbr, base, ft_strlen (base));
	return (str);
}

static char	*ft_recursion(char *str, unsigned long ul, char *base, int len)
{
	unsigned long	r;
	char			*str_r;
	char			*str_t;

	r = ul % len;
	if (ul / len > 0)
		str = ft_recursion (str, ul / len, base, len);
	str_t = (char *) ft_calloc (sizeof(char), 2);
	str_t[0] = base[r];
	str_r = ft_strjoin (str, str_t);
	free (str_t);
	free (str);
	return (str_r);
}

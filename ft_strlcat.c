/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 20:41:24 by ksorokol          #+#    #+#             */
/*   Updated: 2024/09/18 12:00:05 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t l)
{
	size_t	len_d;
	size_t	len_s;

	len_s = ft_strlen (src);
	if (l == 0)
		return (len_s);
	len_d = ft_strlen (dest);
	if (len_d > l)
		return (len_s + l);
	if (len_d + len_s < l - 1)
	{
		ft_memcpy (&dest[len_d], src, len_s + 1);
	}
	else if (len_d < l - 1)
	{
		ft_memcpy (&dest[len_d], src, l - len_d - 1);
		dest[l - 1] = '\0';
	}
	return (len_d + len_s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 20:38:47 by ksorokol          #+#    #+#             */
/*   Updated: 2024/09/18 21:07:26 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t l)
{
	size_t	len_s;

	len_s = ft_strlen (src);
	if (l == 0)
		return (len_s);
	if (len_s <= l - 1)
	{
		ft_memcpy (dest, src, len_s + 1);
	}
	else if (len_s > l - 1)
	{
		ft_memcpy (dest, src, l - 1);
		dest[l - 1] = '\0';
	}
	return (len_s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 20:33:15 by ksorokol          #+#    #+#             */
/*   Updated: 2024/09/18 12:40:10 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	idx;

	if (!dest && !src)
		return (NULL);
	if (dest > src)
		ft_memcpy (dest, src, n);
	else
	{
		idx = 0;
		while (idx < n)
		{
			((char *)dest)[idx] = ((char *) src)[idx];
			idx++;
		}
	}
	return (dest);
}

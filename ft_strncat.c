/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:50:46 by ksorokol          #+#    #+#             */
/*   Updated: 2024/10/18 13:00:59 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	dest_len;

	dest_len = ft_strlen (dest);
	ft_memcpy (&dest[dest_len], src, n);
	dest[dest_len + n] = '\0';
	return (dest);
}

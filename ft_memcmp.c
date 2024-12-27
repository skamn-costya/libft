/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 22:23:03 by ksorokol          #+#    #+#             */
/*   Updated: 2024/09/18 12:43:01 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	idx;

	if (n == 0)
		return (0);
	idx = 0;
	while (idx < n
		&& ((unsigned char *) s1)[idx] == ((unsigned char *) s2)[idx])
		idx++;
	if (idx == n)
		return (0);
	return (((unsigned char *) s1)[idx] - ((unsigned char *) s2)[idx]);
}

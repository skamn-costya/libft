/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 22:14:35 by ksorokol          #+#    #+#             */
/*   Updated: 2024/09/18 12:42:19 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	idx;

	idx = 0;
	while (idx < n)
	{
		if ((unsigned char) s1[idx] == 0 || (unsigned char) s2[idx] == 0
			|| (unsigned char) s1[idx] != (unsigned char) s2[idx])
			return ((unsigned char) s1[idx] - (unsigned char) s2[idx]);
		idx++;
	}
	return (0);
}

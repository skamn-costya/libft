/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 21:23:31 by ksorokol          #+#    #+#             */
/*   Updated: 2024/10/14 21:30:47 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	idx[2];

	idx[0] = ft_strlen (s1);
	idx[1] = ft_strlen (s2);
	if (idx[0] > idx[1])
		idx[0] = idx[1];
	idx[1] = 0;
	while (idx[1] <= idx[0])
	{
		if ((unsigned char) s1[idx[1]] != (unsigned char) s2[idx[1]])
			return ((unsigned char) s1[idx[1]] - (unsigned char) s2[idx[1]]);
		idx[1]++;
	}
	return (0);
}

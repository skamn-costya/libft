/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 22:07:28 by ksorokol          #+#    #+#             */
/*   Updated: 2024/09/18 21:32:30 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	idx;
	char	chr;

	idx = 0;
	chr = (char) c;
	while (s[idx])
	{
		if (s[idx] == chr)
			return ((char *) &s[idx]);
		idx++;
	}
	if (s[idx] == chr)
		return ((char *) &s[idx]);
	return (NULL);
}

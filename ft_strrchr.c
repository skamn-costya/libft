/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 22:11:26 by ksorokol          #+#    #+#             */
/*   Updated: 2024/09/18 12:41:55 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	idx;

	idx = ft_strlen(s);
	if ((unsigned char) s[idx] == (unsigned char) c)
		return ((char *) &s[idx]);
	while (idx > 0)
	{
		idx--;
		if ((unsigned char) s[idx] == (unsigned char) c)
			return ((char *) &s[idx]);
	}
	return (NULL);
}

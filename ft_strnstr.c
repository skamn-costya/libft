/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 22:33:34 by ksorokol          #+#    #+#             */
/*   Updated: 2024/09/18 22:38:37 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	idx1;
	size_t	idx2;

	idx1 = 0;
	if ((haystack == needle) || needle[idx1] == '\0')
		return ((char *) haystack);
	while (haystack[idx1] && idx1 < n)
	{
		if ((unsigned char) haystack[idx1] == (unsigned char) needle[0])
		{
			idx2 = 1;
			while (needle[idx2] && idx1 + idx2 < n)
			{
				if ((unsigned char) haystack[idx1 + idx2]
					!= (unsigned char) needle[idx2])
					break ;
				idx2++;
			}
			if (!needle[idx2])
				return ((char *) &haystack[idx1]);
		}
		idx1++;
	}
	return (NULL);
}

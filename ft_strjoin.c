/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 22:47:03 by ksorokol          #+#    #+#             */
/*   Updated: 2024/09/20 12:03:28 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		len1;
	int		len2;

	if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen (s1);
	len2 = ft_strlen (s2);
	newstr = ft_calloc (len1 + len2 + 1, sizeof (char));
	if (!newstr)
		return (NULL);
	ft_memcpy (newstr, s1, len1);
	ft_memcpy (&newstr[len1], s2, len2);
	return (newstr);
}

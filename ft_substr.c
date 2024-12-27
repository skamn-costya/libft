/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:29:57 by ksorokol          #+#    #+#             */
/*   Updated: 2024/09/20 12:04:40 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	len_s;

	str = (char *) ft_calloc (sizeof(char), 1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	len_s = ft_strlen (s);
	if (start > len_s)
		return (str);
	free (str);
	len_s = ft_strlen (&s[start]);
	if (len_s < len)
		len = len_s;
	str = (char *) ft_calloc (len + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy (str, &s[start], len);
	str[len + 1] = '\0';
	return (str);
}

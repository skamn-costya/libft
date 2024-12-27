/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 23:46:54 by ksorokol          #+#    #+#             */
/*   Updated: 2024/09/18 12:25:07 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*newstr;
	size_t	len;

	len = ft_strlen (s);
	newstr = (char *) malloc (len + 1);
	if (!newstr)
		return (NULL);
	return (ft_memcpy(newstr, s, len + 1));
}

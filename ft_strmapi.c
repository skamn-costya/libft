/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:00:30 by ksorokol          #+#    #+#             */
/*   Updated: 2024/09/20 12:03:43 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*newstr;
	unsigned int	idx;

	if (!s || !f)
		return (NULL);
	newstr = ft_calloc (ft_strlen (s) + 1, sizeof (char));
	if (!newstr)
		return (NULL);
	idx = 0;
	while (s[idx])
	{
		newstr[idx] = f (idx, s[idx]);
		idx++;
	}
	return (newstr);
}

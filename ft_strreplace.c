/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:07:02 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/27 23:10:56 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplace(char const *s, char const *set, char c)
{
	char	*result;
	size_t	idx;

	result = ft_strdup (s);
	idx = 0;
	while (result[idx])
	{
		if (ft_strchr (set, result[idx]))
			result[idx] = c;
		idx++;
	}
	return (result);
}

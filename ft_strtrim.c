/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 22:11:16 by ksorokol          #+#    #+#             */
/*   Updated: 2024/10/08 12:24:26 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newstr;
	size_t	start;
	size_t	finish;

	start = 0;
	while (ft_strchr (set, s1[start]) && s1[start])
		start++;
	finish = ft_strlen (s1);
	while (ft_strchr (set, s1[finish]) && finish > 0)
		finish--;
	if (finish < start || !(ft_strlen (s1)))
	{
		newstr = (char *) ft_calloc (1, sizeof(char));
		if (!newstr)
			return (NULL);
	}
	else
	{
		newstr = (char *) ft_calloc (finish - start + 2, sizeof(char));
		if (!newstr)
			return (NULL);
		ft_memcpy (newstr, &s1[start], finish - start + 1);
	}
	return (newstr);
}

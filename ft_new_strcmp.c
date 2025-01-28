/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_strcmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:30:24 by ksorokol          #+#    #+#             */
/*   Updated: 2025/01/28 19:10:05 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Function: ft_new_strcmp
* -----------------------
*	Return new string = str1 + str2
*	Additional functionality is freeing memory of arguments
*	str1:		the first string
*	str2:		the second string
*	free_ixd:
*				if 0 it doesn't free any arguments
*				if 1 it frees the first argument
*				if 2 it frees the second argument
*				if 3 it frees both arguments
*	returns: new string of concatenation of the first and the second strings
*/
char	*ft_new_strcmp(char *str1, char *str2, char free_ixd)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	str = (char *) malloc ((len1 + len2 + 1) * sizeof (char));
	if (!str)
		return (NULL);
	str[len1 + len2] = '\0';
	ft_memcpy(str, str1, len1);
	ft_memcpy(&str[len1], str2, len2);
	if (free_ixd & 1)
		free (str1);
	if (free_ixd & 2)
		free (str2);
	return (str);
}

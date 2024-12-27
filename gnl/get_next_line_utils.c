/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:16:18 by ksorokol          #+#    #+#             */
/*   Updated: 2024/10/20 21:43:55 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	gnl_strings(t_gnl *pgnl, char *pnl)
{
	char	*str_tmp;
	size_t	size;

	if (pgnl->buf_len == -1 || (pgnl->buf_len == 0 && !pgnl->str))
		return ;
	if (pnl)
	{
		size = pnl - pgnl->str + 1;
		str_tmp = gnl_strdup ((char *)(pnl + 1), -1);
	}
	else
	{
		size = gnl_strlen(pgnl->str);
		str_tmp = NULL;
	}
	pgnl->str_rslt = (char *) malloc ((size + 1) * sizeof (char));
	if (!pgnl->str_rslt)
		return ;
	pgnl->str_rslt[0] = '\0';
	pgnl->str_rslt[size] = '\0';
	gnl_strncat (pgnl->str_rslt, pgnl->str, size);
	free (pgnl->str);
	pgnl->str = str_tmp;
}

char	*gnl_strncat(char *dest, const char *src, size_t n)
{
	size_t	dest_len;

	dest_len = gnl_strlen (dest);
	dest[dest_len + n] = '\0';
	while (n-- > 0)
		((char *) dest)[dest_len + n] = ((char *) src)[n];
	return (dest);
}

char	*gnl_strdup(const char *src, ssize_t src_len)
{
	char	*dest;
	size_t	len;

	if (!src)
		return (NULL);
	if (src_len > -1)
		len = src_len;
	else
		len = gnl_strlen (src);
	dest = (char *) malloc (len + 1);
	if (!dest)
		return (NULL);
	dest[len] = '\0';
	while (len > 0)
	{
		len--;
		((char *) dest)[len] = ((char *) src)[len];
	}
	return (dest);
}

char	*gnl_strchr(const char *s, int c)
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

size_t	gnl_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx])
		idx++;
	return (idx);
}

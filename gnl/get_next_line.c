/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:16:22 by ksorokol          #+#    #+#             */
/*   Updated: 2024/10/23 14:22:06 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_gnl	*first = NULL;
	t_gnl			*pgnl;
	char			*result;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	if (fd < 0)
	{
		pgnl = gnl_search (&first, fd * -1);
		gnl_delete(&first, pgnl);
		return (NULL);
	}
	pgnl = gnl_search (&first, fd);
	if (!pgnl)
		return (NULL);
	gnl_readfile (pgnl);
	if (!pgnl->str_rslt || pgnl->buf_len == -1)
		return (gnl_delete (&first, pgnl), NULL);
	result = gnl_strdup (pgnl->str_rslt, -1);
	free (pgnl->str_rslt);
	pgnl->str_rslt = NULL;
	if (pgnl->str == NULL || pgnl->str[0] == '\0')
		gnl_delete(&first, pgnl);
	return (result);
}

t_gnl	*gnl_search(t_gnl **first, int fd)
{
	t_gnl	*pgnl;
	t_gnl	*pgnl_last;

	if (!*first)
		return (*first = gnl_new (fd), *first);
	pgnl = *first;
	while (pgnl)
	{
		if (pgnl->fd == fd)
			return (pgnl);
		pgnl_last = pgnl;
		pgnl = pgnl->next;
	}
	pgnl_last->next = gnl_new (fd);
	if (pgnl_last->next)
		pgnl_last->next->prev = pgnl_last;
	return (pgnl_last->next);
}

t_gnl	*gnl_new(int fd)
{
	t_gnl	*pgnl;

	pgnl = (t_gnl *) malloc (sizeof (t_gnl));
	if (!pgnl)
		return (NULL);
	pgnl->fd = fd;
	pgnl->buf = (char *) malloc (BUFFER_SIZE * sizeof (char));
	if (!pgnl->buf)
		return (NULL);
	pgnl->buf_len = BUFFER_SIZE;
	pgnl->str = NULL;
	pgnl->str_rslt = NULL;
	pgnl->prev = NULL;
	pgnl->next = NULL;
	return (pgnl);
}

void	gnl_delete(t_gnl **pfirst, t_gnl *pgnl)
{
	free (pgnl->buf);
	free (pgnl->str);
	free (pgnl->str_rslt);
	if (pgnl->prev)
		pgnl->prev->next = pgnl->next;
	if (pgnl->next)
		pgnl->next->prev = pgnl->prev;
	if (*pfirst == pgnl)
		*pfirst = pgnl->next;
	free (pgnl);
}

void	gnl_readfile(t_gnl *pgnl)
{
	char	*pstr[2];

	pstr[0] = NULL;
	if (pgnl->str)
		pstr[0] = gnl_strchr (pgnl->str, '\n');
	while (pgnl->buf_len == BUFFER_SIZE && !pstr[0])
	{
		pgnl->buf_len = read (pgnl->fd, pgnl->buf, BUFFER_SIZE);
		if (pgnl->buf_len < 1)
			break ;
		if (pgnl->str)
		{
			pstr[1] = (char *) malloc ((gnl_strlen (pgnl->str)
						+ pgnl->buf_len + 1) * sizeof (char));
			pstr[1][0] = '\0';
			gnl_strncat (pstr[1], pgnl->str, gnl_strlen(pgnl->str));
			free (pgnl->str);
			pgnl->str = pstr[1];
			gnl_strncat (pgnl->str, pgnl->buf, pgnl->buf_len);
		}
		else
			pgnl->str = gnl_strdup (pgnl->buf, pgnl->buf_len);
		pstr[0] = gnl_strchr (pgnl->str, '\n');
	}
	gnl_strings (pgnl, pstr[0]);
}

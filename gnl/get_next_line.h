/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:16:27 by ksorokol          #+#    #+#             */
/*   Updated: 2024/10/20 21:43:48 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1042
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_gnl
{
	int				fd;
	char			*buf;
	ssize_t			buf_len;
	char			*str;
	char			*str_rslt;
	size_t			s_pos;
	size_t			c_pos;
	struct s_gnl	*prev;
	struct s_gnl	*next;
}	t_gnl;

char	*get_next_line(int fd);
t_gnl	*gnl_new(int fd);
t_gnl	*gnl_search(t_gnl **first, int fd);
void	gnl_delete(t_gnl **pfirst, t_gnl *pgnl);
void	gnl_readfile(t_gnl *pgnl);

void	gnl_strings(t_gnl *pgnl, char *pnl);
char	*gnl_strncat(char *dest, const char *src, size_t n);
char	*gnl_strdup(const char *src, ssize_t src_len);
char	*gnl_strchr(const char *s, int c);
size_t	gnl_strlen(const char *s);

#endif
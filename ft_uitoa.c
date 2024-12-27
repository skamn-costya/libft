/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 23:07:16 by ksorokol          #+#    #+#             */
/*   Updated: 2024/10/03 00:23:33 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa(unsigned int n)
{
	return (ft_uitoa_base (n, "0123456789"));
}

// static int	ft_uilen(unsigned long ul);
// static char	*ft_recursion(unsigned long ul, char *pstr, size_t *pidx);

// char	*ft_uitoa(unsigned int n)
// {
// 	char			*newstr;
// 	size_t			idx;
// 	unsigned long	ul;

// 	newstr = (char *) ft_calloc (ft_uilen(n) + 1, sizeof (char));
// 	if (!newstr)
// 		return (NULL);
// 	ul = (unsigned long) n;
// 	idx = 0;
// 	ft_recursion (ul, newstr, &idx);
// 	return (newstr);
// }

// static int	ft_uilen(unsigned long ul)
// {
// 	int		i;

// 	i = 0;
// 	if (ul == 0)
// 		return (1);
// 	while (ul)
// 	{
// 		i++;
// 		ul = ul / 10;
// 	}
// 	return (i);
// }

// static char	*ft_recursion(unsigned long ul, char *pstr, size_t *pidx)
// {
// 	if (ul / 10)
// 		ft_recursion (ul / 10, pstr, pidx);
// 	pstr[*pidx] = ul % 10 + '0';
// 	(*pidx)++;
// 	return (pstr);
// }

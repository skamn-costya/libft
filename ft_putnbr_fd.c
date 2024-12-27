/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 21:40:35 by ksorokol          #+#    #+#             */
/*   Updated: 2024/09/19 11:17:27 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_recursion(long l, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	long	l;

	l = n;
	if (l < 0)
	{
		ft_putchar_fd ('-', fd);
		l *= -1;
	}
	ft_recursion (l, fd);
}

static void	ft_recursion(long l, int fd)
{
	if (l / 10)
		ft_recursion (l / 10, fd);
	ft_putchar_fd (l % 10 + '0', fd);
}

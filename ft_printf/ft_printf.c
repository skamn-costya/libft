/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:40:06 by ksorokol          #+#    #+#             */
/*   Updated: 2024/10/21 13:44:51 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

// : c : s : p : d : i : u : x : X : % : mix
// ’-0.’ width ’# +’

void	ft_printf_arg(const char *format, int *idx, va_list *argptr, int *cntr);
void	ft_print_wrog(int *idx, int sidx);

int	ft_printf(const char *format, ...)
{
	va_list	argptr;
	int		idx;
	int		counter;

	if (!format)
		return (-1);
	counter = 0;
	va_start (argptr, format);
	idx = 0;
	while (format[idx])
	{
		if (format[idx] != '%')
		{
			write (FD, &format[idx], 1);
			counter++;
		}
		else
			ft_printf_arg (format, &idx, &argptr, &counter);
		idx++;
	}
	va_end (argptr);
	return (counter);
}

void	ft_printf_percent(int *counter)
{
	(*counter)++;
	write (FD, "%", 1);
}

void	ft_printf_arg(const char *format, int *idx, va_list *argptr, int *cntr)
{
	t_cnv_spc	cnv_spc;
	int			sidx;

	sidx = ++(*idx);
	if (!ft_printf_cnvspc (&cnv_spc, format, idx, argptr))
		return ;
	if (format[*idx] == 'c')
		ft_printf_c (&cnv_spc, argptr, cntr);
	else if (format[*idx] == 's')
		ft_printf_s (&cnv_spc, argptr, cntr);
	else if (format[*idx] == 'p')
		ft_printf_p (&cnv_spc, argptr, cntr);
	else if (format[*idx] == 'd' || format[*idx] == 'i')
		ft_printf_di (&cnv_spc, argptr, cntr);
	else if (format[*idx] == 'u')
		ft_printf_u (&cnv_spc, argptr, cntr);
	else if (format[*idx] == 'x')
		ft_printf_xxx (&cnv_spc, argptr, cntr, "0123456789abcdef");
	else if (format[*idx] == 'X')
		ft_printf_xxx (&cnv_spc, argptr, cntr, "0123456789ABCDEF");
	else if (format[*idx] == '%')
		ft_printf_percent(cntr);
	else
		ft_print_wrog(idx, --sidx);
}

void	ft_print_wrog(int *idx, int sidx)
{
	write (FD, "%", 1);
	*idx = sidx;
}

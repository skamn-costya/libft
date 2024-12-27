/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cnvspc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:01:51 by ksorokol          #+#    #+#             */
/*   Updated: 2024/10/20 23:36:03 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_printf_flags(t_cnv_spc *cnv_spc, const char *format,
		int *idx, va_list *argptr);
int	ft_printf_wl(t_cnv_spc *cnv_spc, const char *format,
		int *idx, va_list *argptr);
int	ft_printf_setflg(int *flag, t_cnv_spc *cnv_spc);

int	ft_printf_cnvspc(t_cnv_spc *cnv_spc, const char *format,
			int *idx, va_list *argptr)
{
	int	i;
	int	idxs;

	idxs = *idx - 1;
	cnv_spc->flag_minus = 0;
	cnv_spc->flag_zero = 0;
	cnv_spc->flag_dot = 0;
	cnv_spc->flag_dot_s = 0;
	cnv_spc->flag_hash = 0;
	cnv_spc->flag_space = 0;
	cnv_spc->flag_plus = 0;
	cnv_spc->width_b = -1;
	cnv_spc->width_s = -1;
	cnv_spc->len = -1;
	cnv_spc->negative = 0;
	cnv_spc->spn = 0;
	i = ft_printf_flags (cnv_spc, format, idx, argptr);
	if (!i)
	{
		*idx = idxs;
		write (FD, "%", 1);
	}
	return (i);
}

int	ft_printf_flags(t_cnv_spc *cnv_spc, const char *format,
		int *idx, va_list *argptr)
{
	int	i;

	while (ft_strchr ("-0.# +*", format[*idx]) || ft_isdigit (format[*idx]))
	{
		if (format[*idx] == '-')
			i = ft_printf_setflg(&cnv_spc->flag_minus, cnv_spc);
		else if (format[*idx] == '0' && !cnv_spc->flag_dot)
			i = ft_printf_setflg(&cnv_spc->flag_zero, cnv_spc);
		else if (format[*idx] == '.')
			i = ft_printf_setflg(&cnv_spc->flag_dot, cnv_spc);
		else if (format[*idx] == '#')
			i = ft_printf_setflg(&cnv_spc->flag_hash, cnv_spc);
		else if (format[*idx] == ' ')
			i = ft_printf_setflg(&cnv_spc->flag_space, cnv_spc);
		else if (format[*idx] == '+')
			i = ft_printf_setflg(&cnv_spc->flag_plus, cnv_spc);
		else
			i = ft_printf_wl (cnv_spc, format, idx, argptr);
		if (!i)
			return (0);
		(*idx)++;
	}
	return (1);
}

int	ft_printf_wl(t_cnv_spc *cnv_spc, const char *format,
		int *idx, va_list *argptr)
{
	int	i;

	if (format[*idx] == '*')
		i = va_arg (*argptr, int);
	else if (ft_isdigit (format[*idx]))
	{
		i = ft_atoi (&format[*idx]);
		(*idx) += ft_nbrlen (i) - 1;
	}
	else
		return (0);
	if (i < 0 && !cnv_spc->flag_dot)
	{
		i *= -1;
		cnv_spc->flag_minus = 1;
	}
	else if (i < 0 && cnv_spc->flag_dot)
		cnv_spc->flag_dot = 0;
	if (!cnv_spc->flag_dot && cnv_spc->width_b == -1)
		cnv_spc->width_b = i;
	else if (cnv_spc->flag_dot && cnv_spc->width_s < 0)
		cnv_spc->width_s = i;
	return (1);
}

int	ft_printf_setflg(int *flag, t_cnv_spc *cnv_spc)
{
	if (cnv_spc->flag_dot_s)
		return (0);
	if (flag == &cnv_spc->flag_dot)
		cnv_spc->flag_dot_s = 1;
	*flag = 1;
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:22:00 by ksorokol          #+#    #+#             */
/*   Updated: 2024/10/20 23:36:16 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

// %d uses - minus, zero, dot, space, plus and whide
// '0' flag ignored with '-' flag
// '0' flag ignored with precision
// ' ' flag ignored with '+' flag
// The int argument is converted to signed decimal notation.
// The precision, if any, gives the minimum number of digits 
// that must appear; if the converted value requires fewer 
// digits, it is padded on the left with zeros. The default 
// precision is 1. When 0 is printed with an explicit precision 0, 
// the output is empty.

static void	ft_printf_di_(t_cnv_spc *cnv_spc);
static char	*ft_printf_di_sub_rslt(t_cnv_spc *cnv_spc, int nbr);
static void	ft_printf_di_begin(t_cnv_spc *cnv_spc, char *sub_rslt);

void	ft_printf_di(t_cnv_spc *cnv_spc, va_list *argptr, int *counter)
{
	int		nbr;
	char	*rslt;
	char	*sub_rslt;

	nbr = va_arg (*argptr, int);
	ft_printf_di_ (cnv_spc);
	sub_rslt = ft_printf_di_sub_rslt (cnv_spc, nbr);
	rslt = (char *) ft_calloc (cnv_spc->width_b + 1, sizeof(char));
	if (!rslt)
		return ;
	ft_memset (rslt, ' ', cnv_spc->width_b);
	if (cnv_spc->flag_minus)
		ft_memcpy (rslt, sub_rslt, cnv_spc->width_s + cnv_spc->spn);
	else
		ft_memcpy (rslt + (cnv_spc->width_b
				- (cnv_spc->width_s + cnv_spc->spn)),
			sub_rslt, cnv_spc->width_s + cnv_spc->spn);
	free (sub_rslt);
	(*counter) += cnv_spc->width_b;
	write (FD, rslt, cnv_spc->width_b);
	free (rslt);
}

static void	ft_printf_di_(t_cnv_spc *cnv_spc)
{
	if (cnv_spc->flag_minus)
		cnv_spc->flag_zero = 0;
	if (cnv_spc->flag_dot)
		cnv_spc->flag_zero = 0;
	if (cnv_spc->flag_plus)
		cnv_spc->flag_space = 0;
	cnv_spc->flag_hash = 0;
}

static char	*ft_printf_di_sub_rslt(t_cnv_spc *cnv_spc, int nbr)
{
	char	*str;
	char	*sub_rslt;

	str = ft_printf_di_size (nbr, cnv_spc, "0123456789");
	sub_rslt = (char *) ft_calloc (cnv_spc->width_s + 1
			+ cnv_spc->spn, sizeof(char));
	if (!sub_rslt)
		return (NULL);
	ft_memset (sub_rslt, ' ', cnv_spc->width_s + cnv_spc->spn);
	if (cnv_spc->flag_zero || cnv_spc->flag_dot)
		ft_memset (sub_rslt, '0', cnv_spc->width_s + cnv_spc->spn);
	ft_printf_di_begin (cnv_spc, sub_rslt);
	if (cnv_spc->flag_zero || cnv_spc->flag_dot || !cnv_spc->flag_minus)
		ft_memcpy (sub_rslt + (cnv_spc->width_s - cnv_spc->len
				+ cnv_spc->spn), str, cnv_spc->len);
	else
		ft_memcpy (sub_rslt + cnv_spc->spn, str, cnv_spc->len);
	free (str);
	return (sub_rslt);
}

static void	ft_printf_di_begin(t_cnv_spc *cnv_spc, char *sub_rslt)
{
	if (cnv_spc->flag_zero || cnv_spc->flag_dot || cnv_spc->flag_minus)
	{
		if (cnv_spc->negative)
			sub_rslt[0] = '-';
		else if (cnv_spc->flag_plus && !cnv_spc->negative)
			sub_rslt[0] = '+';
		else if (cnv_spc->flag_space && !cnv_spc->negative)
			sub_rslt[0] = ' ';
	}
	else
	{
		if (cnv_spc->negative)
			sub_rslt[cnv_spc->width_s - cnv_spc->len] = '-';
		else if (cnv_spc->flag_plus && !cnv_spc->negative)
			sub_rslt[cnv_spc->width_s - cnv_spc->len] = '+';
		else if (cnv_spc->flag_space && !cnv_spc->negative)
			sub_rslt[cnv_spc->width_s - cnv_spc->len] = ' ';
	}
}

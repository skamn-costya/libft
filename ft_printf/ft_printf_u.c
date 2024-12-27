/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 22:33:24 by ksorokol          #+#    #+#             */
/*   Updated: 2024/10/20 23:36:48 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

// %u uses - minus, zero, dot and whide
// '0' flag ignored with '-' flag
// '0' flag ignored with precision
// The unsigned int argument is converted to unsigned hexadecimal (x and X) 
// notation. The letters abcdef are used for x conversions; 
// the letters ABCDEF are used for X conversions. The precision, if any, 
// gives the minimum number of digits that must appear; if the converted 
// value requires fewer digits, it is padded on the left with zeros. 
// The default precision is 1. When 0 is printed with an explicit precision 0, 
// the output is empty.

static void	ft_printf_u_(t_cnv_spc *cnv_spc);
static char	*ft_printf_u_sub_rslt(t_cnv_spc *cnv_spc, unsigned int nbr);
static void	ft_printf_u_begin(t_cnv_spc *cnv_spc, char *sub_rslt);

void	ft_printf_u(t_cnv_spc *cnv_spc, va_list *argptr, int *counter)
{
	unsigned int	nbr;
	char			*rslt;
	char			*sub_rslt;

	nbr = va_arg (*argptr, unsigned int);
	ft_printf_u_ (cnv_spc);
	sub_rslt = ft_printf_u_sub_rslt (cnv_spc, nbr);
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

static void	ft_printf_u_(t_cnv_spc *cnv_spc)
{
	if (cnv_spc->flag_minus)
		cnv_spc->flag_zero = 0;
	if (cnv_spc->flag_dot)
		cnv_spc->flag_zero = 0;
	cnv_spc->flag_space = 0;
	cnv_spc->flag_plus = 0;
	cnv_spc->flag_hash = 0;
}

static char	*ft_printf_u_sub_rslt(t_cnv_spc *cnv_spc, unsigned int nbr)
{
	char	*str;
	char	*sub_rslt;

	str = ft_printf_u_size (nbr, cnv_spc, "0123456789");
	sub_rslt = (char *) ft_calloc (cnv_spc->width_s + 1
			+ cnv_spc->spn, sizeof(char));
	if (!sub_rslt)
		return (NULL);
	ft_memset (sub_rslt, ' ', cnv_spc->width_s + cnv_spc->spn);
	if (cnv_spc->flag_zero || cnv_spc->flag_dot)
		ft_memset (sub_rslt, '0', cnv_spc->width_s + cnv_spc->spn);
	ft_printf_u_begin (cnv_spc, sub_rslt);
	if (cnv_spc->flag_zero || cnv_spc->flag_dot || !cnv_spc->flag_minus)
		ft_memcpy (sub_rslt + (cnv_spc->width_s - cnv_spc->len
				+ cnv_spc->spn), str, cnv_spc->len);
	else
		ft_memcpy (sub_rslt + cnv_spc->spn, str, cnv_spc->len);
	free (str);
	return (sub_rslt);
}

static void	ft_printf_u_begin(t_cnv_spc *cnv_spc, char *sub_rslt)
{
	if (cnv_spc->flag_zero || cnv_spc->flag_dot || cnv_spc->flag_minus)
	{
		if (cnv_spc->negative)
			sub_rslt[0] = '-';
		else if (cnv_spc->flag_plus)
			sub_rslt[0] = '+';
		else if (cnv_spc->flag_space)
			sub_rslt[0] = ' ';
	}
	else
	{
		if (cnv_spc->negative)
			sub_rslt[cnv_spc->width_s - cnv_spc->len] = '-';
		else if (cnv_spc->flag_plus)
			sub_rslt[cnv_spc->width_s - cnv_spc->len] = '+';
		else if (cnv_spc->flag_space)
			sub_rslt[cnv_spc->width_s - cnv_spc->len] = ' ';
	}
}

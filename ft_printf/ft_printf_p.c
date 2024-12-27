/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:27:45 by ksorokol          #+#    #+#             */
/*   Updated: 2024/10/20 23:36:30 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

// %p uses - minus, plus, space and whide

static void	ft_printf_p_(t_cnv_spc *cnv_spc, unsigned long nbr);
static char	*ft_printf_p_sub_rslt(t_cnv_spc *cnv_spc, unsigned long nbr,
				char *base);
static void	ft_printf_p_hash(t_cnv_spc *cnv_spc, char *sub_rslt);
static void	ft_printf_p_begin(t_cnv_spc *cnv_spc, char *sub_rslt);

void	ft_printf_p(t_cnv_spc *cnv_spc, va_list *argptr, int *counter)
{
	unsigned long	nbr;
	char			*rslt;
	char			*sub_rslt;

	nbr = va_arg (*argptr, unsigned long);
	ft_printf_p_ (cnv_spc, nbr);
	sub_rslt = ft_printf_p_sub_rslt (cnv_spc, nbr, "0123456789abcdef");
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

static void	ft_printf_p_(t_cnv_spc *cnv_spc, unsigned long nbr)
{
	cnv_spc->flag_hash = 1;
	if (!nbr)
		cnv_spc->flag_hash = 0;
	if (cnv_spc->flag_minus)
		cnv_spc->flag_zero = 0;
	if (cnv_spc->flag_dot)
		cnv_spc->flag_zero = 0;
	if (cnv_spc->flag_plus)
		cnv_spc->flag_space = 0;
}

static char	*ft_printf_p_sub_rslt(t_cnv_spc *cnv_spc, unsigned long nbr,
				char *base)
{
	char	*str;
	char	*sub_rslt;

	str = ft_printf_p_size (nbr, cnv_spc, base);
	sub_rslt = (char *) ft_calloc (cnv_spc->width_s + 1
			+ cnv_spc->spn, sizeof(char));
	if (!sub_rslt)
		return (NULL);
	ft_memset (sub_rslt, ' ', cnv_spc->width_s + cnv_spc->spn);
	if (cnv_spc->flag_zero || cnv_spc->flag_dot)
		ft_memset (sub_rslt, '0', cnv_spc->width_s + cnv_spc->spn);
	ft_printf_p_hash (cnv_spc, sub_rslt);
	ft_printf_p_begin (cnv_spc, sub_rslt);
	if (cnv_spc->flag_zero || cnv_spc->flag_dot || !cnv_spc->flag_minus)
		ft_memcpy (sub_rslt + (cnv_spc->width_s - cnv_spc->len
				+ cnv_spc->spn), str, cnv_spc->len);
	else
		ft_memcpy (sub_rslt + cnv_spc->spn, str, cnv_spc->len);
	free (str);
	return (sub_rslt);
}

static void	ft_printf_p_hash(t_cnv_spc *cnv_spc, char *sub_rslt)
{
	int	shift;

	shift = 0;
	if (cnv_spc->flag_plus || cnv_spc->flag_space)
		shift++;
	if (cnv_spc->flag_hash)
	{
		if (cnv_spc->flag_zero || cnv_spc->flag_dot || cnv_spc->flag_minus)
		{
			sub_rslt[shift] = '0';
			sub_rslt[shift + 1] = 'x';
		}
		else
		{
			sub_rslt[cnv_spc->width_s - cnv_spc->len + shift] = '0';
			sub_rslt[cnv_spc->width_s - cnv_spc->len + shift + 1] = 'x';
		}
	}
}

static void	ft_printf_p_begin(t_cnv_spc *cnv_spc, char *sub_rslt)
{
	if (cnv_spc->flag_zero || cnv_spc->flag_dot || cnv_spc->flag_minus)
	{
		if (cnv_spc->flag_plus)
			sub_rslt[0] = '+';
		else if (cnv_spc->flag_space)
			sub_rslt[0] = ' ';
	}
	else
	{
		if (cnv_spc->flag_plus)
			sub_rslt[cnv_spc->width_s - cnv_spc->len] = '+';
		else if (cnv_spc->flag_space)
			sub_rslt[cnv_spc->width_s - cnv_spc->len] = ' ';
	}
}

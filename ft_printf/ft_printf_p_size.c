/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:49:47 by ksorokol          #+#    #+#             */
/*   Updated: 2024/10/20 23:36:23 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	ft_printf_p_sizes(t_cnv_spc *cnv_spc, char *str_nbr);

char	*ft_printf_p_size(unsigned long nbr, t_cnv_spc *cnv_spc, char *base)
{
	unsigned long	l;
	char			*str_nbr;

	l = nbr;
	if (!nbr)
	{
		str_nbr = ft_strdup ("(nil)");
		cnv_spc->flag_hash = 0;
		cnv_spc->flag_zero = 0;
		cnv_spc->flag_plus = 0;
		cnv_spc->flag_space = 0;
	}
	else
		str_nbr = ft_ultoa_base(l, base);
	ft_printf_p_sizes(cnv_spc, str_nbr);
	return (str_nbr);
}

static int	ft_printf_p_sizes(t_cnv_spc *cnv_spc, char *str_nbr)
{
	if (cnv_spc->flag_plus || cnv_spc->flag_space)
		cnv_spc->spn = 1;
	if (cnv_spc->flag_hash)
		cnv_spc->spn += 2;
	cnv_spc->len = ft_strlen (str_nbr);
	if (cnv_spc->width_s < 0 && cnv_spc->width_b == -1)
	{
		cnv_spc->width_s = cnv_spc->len;
		cnv_spc->width_b = cnv_spc->len + cnv_spc->spn;
	}
	else if (cnv_spc->width_s && cnv_spc->width_b == -1)
		cnv_spc->width_b = cnv_spc->width_s + cnv_spc->spn;
	else if (cnv_spc->width_s < 0 && cnv_spc->width_b)
	{
		if (cnv_spc->flag_dot)
			cnv_spc->width_s = cnv_spc->len;
		else
			cnv_spc->width_s = cnv_spc->width_b - cnv_spc->spn;
	}
	if (cnv_spc->width_s < cnv_spc->len)
		cnv_spc->width_s = cnv_spc->len;
	if (cnv_spc->width_b < cnv_spc->width_s + cnv_spc->spn)
		cnv_spc->width_b = cnv_spc->width_s + cnv_spc->spn;
	return (0);
}

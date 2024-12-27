/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:44:45 by ksorokol          #+#    #+#             */
/*   Updated: 2024/10/20 23:34:55 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

// %c uses - minus and whide

void	ft_printf_c(t_cnv_spc *cnv_spc, va_list *argptr, int *counter)
{
	char	*rslt;
	char	c;

	cnv_spc->width_s = 1;
	if (cnv_spc->width_b < cnv_spc->width_s)
		cnv_spc->width_b = cnv_spc->width_s ;
	rslt = (char *) ft_calloc (cnv_spc->width_b, sizeof(char));
	if (!rslt)
		return ;
	c = va_arg (*argptr, unsigned int);
	ft_memset (rslt, ' ', cnv_spc->width_b);
	if (cnv_spc->flag_minus)
		rslt[0] = c;
	else
		rslt[cnv_spc->width_b - cnv_spc->width_s] = c;
	(*counter) += cnv_spc->width_b;
	write (FD, rslt, cnv_spc->width_b);
	free (rslt);
	rslt = NULL;
}

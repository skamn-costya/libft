/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:02:54 by ksorokol          #+#    #+#             */
/*   Updated: 2024/10/20 23:36:36 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

// %s uses - minus, dot and whide
// The precision specifies the maximum number of characters to be printed. 
// Characters in excess of precision aren't printed.

static void	ft_printf_s_(t_cnv_spc *cnv_spc, char *str);

void	ft_printf_s(t_cnv_spc *cnv_spc, va_list *argptr, int *counter)
{
	char	*rslt;
	char	*str;

	str = va_arg (*argptr, char *);
	if (cnv_spc->flag_dot && cnv_spc->width_s < 0 && cnv_spc->width_b == -1)
		return ;
	if (!str && cnv_spc->flag_dot && (cnv_spc->width_s < 6))
		str = "";
	if (!str)
		str = "(null)";
	ft_printf_s_ (cnv_spc, str);
	if (!cnv_spc->width_b)
		return ;
	rslt = (char *) ft_calloc (cnv_spc->width_b, sizeof(char));
	if (!rslt)
		return ;
	ft_memset (rslt, ' ', cnv_spc->width_b);
	if (cnv_spc->flag_minus)
		ft_memcpy (rslt, str, cnv_spc->width_s);
	else
		ft_memcpy (rslt + cnv_spc->width_b - cnv_spc->width_s, str,
			cnv_spc->width_s);
	(*counter) += cnv_spc->width_b;
	write (FD, rslt, cnv_spc->width_b);
	free (rslt);
}

static void	ft_printf_s_(t_cnv_spc *cnv_spc, char *str)
{
	int	len;

	len = ft_strlen (str);
	if (cnv_spc->width_s > len
		|| (cnv_spc->width_s < 0 && !cnv_spc->flag_dot))
		cnv_spc->width_s = len;
	else if (cnv_spc->width_s < 0 && cnv_spc->flag_dot)
		cnv_spc->width_s = 0;
	if (cnv_spc->width_b < cnv_spc->width_s)
		cnv_spc->width_b = cnv_spc->width_s;
}

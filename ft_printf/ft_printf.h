/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:47:13 by ksorokol          #+#    #+#             */
/*   Updated: 2024/10/20 23:35:35 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>

# ifndef FD
#  define FD 1
# endif

typedef struct s_conversion_specification
{
	int	flag_minus;
	int	flag_zero;
	int	flag_dot;
	int	flag_dot_s;
	int	flag_hash;
	int	flag_space;
	int	flag_plus;
	int	width_b;
	int	width_s;
	int	len;
	int	negative;
	int	spn;
}	t_cnv_spc;

int		ft_printf(const char *format, ...);
int		ft_check_format(const char *format);
void	ft_printf_c(t_cnv_spc *cnv_spc, va_list *argptr, int *counter);
void	ft_printf_s(t_cnv_spc *cnv_spc, va_list *argptr, int *counter);
void	ft_printf_p(t_cnv_spc *cnv_spc, va_list *argptr, int *counter);
void	ft_printf_di(t_cnv_spc *cnv_spc, va_list *argptr, int *counter);
void	ft_printf_u(t_cnv_spc *cnv_spc, va_list *argptr, int *counter);
void	ft_printf_xxx(t_cnv_spc *cnv_spc, va_list *argptr, int *counter,
			char *base);

int		ft_printf_cnvspc(t_cnv_spc *cnv_spc, const char *format,
			int *idx, va_list *argptr);
void	ft_printf_putarg(const char *str, t_cnv_spc *cnv_spc, int *cntr);
char	*ft_printf_p_size(unsigned long nbr, t_cnv_spc *cnv_spc, char *base);
char	*ft_printf_di_size(int nbr, t_cnv_spc *cnv_spc, char *base);
char	*ft_printf_u_size(unsigned int nbr, t_cnv_spc *cnv_spc, char *base);

void	*ft_temp(char	*str);

#endif

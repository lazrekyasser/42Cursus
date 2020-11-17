/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 19:48:46 by ylazrek           #+#    #+#             */
/*   Updated: 2019/12/14 19:48:56 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_i_p_q(char *str, t_flags *f)
{
	int	x;

	x = 0;
	if (str[0] == '-')
	{
		x += write_space(f->width - ft_max(ft_strlen(str + 1),
		f->precision_len) - 1);
		x += write(1, "-", 1);
		x += write_zero(f->precision_len - ft_strlen(str + 1));
		x += write(1, str + 1, ft_strlen(str + 1));
		return (x);
	}
	x += write_space(f->width - ft_max(ft_strlen(str), f->precision_len));
	x += write_zero(f->precision_len - ft_strlen(str));
	x += write(1, str, ft_strlen(str));
	return (x);
}

int	ft_i_p_m(char *str, t_flags *f)
{
	int	x;

	x = 0;
	if (str[0] == '-')
	{
		x += write(1, "-", 1);
		x += write_zero(f->precision_len - ft_strlen(str + 1));
		x += write(1, str + 1, ft_strlen(str + 1));
		x += write_space(f->width - ft_max(ft_strlen(str + 1),
		f->precision_len) - 1);
		return (x);
	}
	x += write_zero(f->precision_len - ft_strlen(str));
	x += write(1, str, ft_strlen(str));
	x += write_space(f->width - ft_max(ft_strlen(str), f->precision_len));
	return (x);
}

int	put_intp(char *str, t_flags *f)
{
	int	cnt;

	cnt = 0;
	if (f->flags == 'q' || f->flags == '0')
		return (ft_i_p_q(str, f));
	if (f->flags == '-')
		return (ft_i_p_m(str, f));
	return (cnt);
}

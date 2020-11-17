/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 09:09:51 by ylazrek           #+#    #+#             */
/*   Updated: 2019/12/14 19:51:37 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_p_q(unsigned int n, t_flags *f)
{
	int	x;

	x = 0;
	x += write_space(f->width - ft_max(len_hex(n), f->precision_len));
	x += write_zero(f->precision_len - len_hex(n));
	write_hex(n, f);
	x += len_hex(n);
	return (x);
}

int	ft_hex_p_m(unsigned int n, t_flags *f)
{
	int	x;

	x = 0;
	x += write_zero(f->precision_len - len_hex(n));
	write_hex(n, f);
	x += len_hex(n);
	x += write_space(f->width - ft_max(len_hex(n), f->precision_len));
	return (x);
}

int	put_hexp(unsigned int n, t_flags *f)
{
	int	cnt;

	cnt = 0;
	if (f->flags == 'q' || f->flags == '0')
		return (ft_hex_p_q(n, f));
	if (f->flags == '-')
		return (ft_hex_p_m(n, f));
	return (cnt);
}

int	print_hex_zero(unsigned int n, t_flags *f)
{
	int	cnt;

	cnt = 0;
	if (f->point == 0)
		cnt += put_hex(n, f);
	else
	{
		if (f->precision_len == 0)
		{
			if (f->width != 0)
				cnt += write_space(f->width);
		}
		else
			cnt += put_hexp(n, f);
	}
	return (cnt);
}

int	print_hex(t_flags *f, va_list p)
{
	int				cnt;
	unsigned int	a;

	cnt = 0;
	a = va_arg(p, unsigned int);
	(a == 0) ? cnt += print_hex_zero(a, f) : 1;
	if (a != 0)
	{
		(f->point == 0) ? cnt += put_hex(a, f) : 1;
		if (f->point != 0)
		{
			if (f->precision_len == 0)
			{
				if (f->width == 0)
					cnt += write_hex(a, f) + len_hex(a);
				else
				{
					(f->flags == '0') ? f->flags = 'q' : 1;
					cnt += put_hex(a, f);
				}
			}
			(f->precision_len != 0) ? cnt += put_hexp(a, f) : 1;
		}
	}
	return (cnt);
}

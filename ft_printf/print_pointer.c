/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 08:56:32 by ylazrek           #+#    #+#             */
/*   Updated: 2019/12/14 08:57:22 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_p(unsigned long int n, t_flags *f)
{
	int	cnt;

	cnt = 0;
	if (f->flags == 'q' && f->width > len_pointer(n))
		cnt += write_space(f->width - len_pointer(n));
	write(1, "0x", 2);
	write_pointer(n);
	cnt += len_pointer(n);
	if (f->flags == '-' && f->width > len_pointer(n))
		cnt += write_space(f->width - len_pointer(n));
	return (cnt);
}

int	print_pointer(t_flags *f, va_list p)
{
	int					cnt;
	unsigned long int	a;

	cnt = 0;
	a = va_arg(p, unsigned long int);
	if (f->point == 0)
		cnt += print_p(a, f);
	return (cnt);
}

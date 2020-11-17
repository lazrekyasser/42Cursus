/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_car.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 08:51:01 by ylazrek           #+#    #+#             */
/*   Updated: 2019/12/14 08:51:47 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_car(char s, t_flags *f)
{
	int cnt;

	cnt = 0;
	if (f->flags == 'q')
		cnt += write_space(f->width - 1);
	if (f->flags == '0')
		cnt += write_zero(f->width - 1);
	cnt += write(1, &s, 1);
	if (f->flags == '-')
		cnt += write_space(f->width - 1);
	return (cnt);
}

int	print_car(t_flags *f, va_list p)
{
	int		cnt;
	char	c;

	cnt = 0;
	c = (char)va_arg(p, int);
	if (f->point == 0)
		cnt += put_car(c, f);
	return (cnt);
}

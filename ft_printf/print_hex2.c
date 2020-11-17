/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 19:53:26 by ylazrek           #+#    #+#             */
/*   Updated: 2019/12/14 19:53:31 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_hex(unsigned int n, t_flags *f)
{
	int	cnt;

	cnt = 0;
	if (f->flags == 'q' && f->width > len_hex(n))
		cnt += write_space(f->width - len_hex(n));
	if (f->flags == '0' && f->width > len_hex(n))
		cnt += write_zero(f->width - len_hex(n));
	write_hex(n, f);
	cnt += len_hex(n);
	if (f->flags == '-' && f->width > len_hex(n))
		cnt += write_space(f->width - len_hex(n));
	return (cnt);
}

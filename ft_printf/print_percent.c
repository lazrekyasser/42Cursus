/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 09:12:50 by ylazrek           #+#    #+#             */
/*   Updated: 2019/12/14 09:28:34 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_percent(t_flags *f)
{
	int		cnt;
	char	c;

	cnt = 0;
	c = '%';
	if (f->point == 0)
		cnt += put_car(c, f);
	else
	{
		if (f->precision_len == 0)
		{
			if (f->width == 0)
				cnt += write(1, &c, 1);
			else
				cnt += put_car(c, f);
		}
		else
			cnt += put_car(c, f);
	}
	return (cnt);
}

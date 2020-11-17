/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 08:57:38 by ylazrek           #+#    #+#             */
/*   Updated: 2019/12/14 19:34:14 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_unsint(unsigned int n, t_flags *f)
{
	int		cnt;
	char	*str;

	cnt = 0;
	str = ft_utoa(n);
	if (f->flags == 'q' && f->width > ft_strlen(str))
		cnt += write_space(f->width - ft_strlen(str));
	if (f->flags == '0' && f->width > ft_strlen(str))
		cnt += write_zero(f->width - ft_strlen(str));
	cnt += write(1, str, ft_strlen(str));
	if (f->flags == '-' && f->width > ft_strlen(str))
		cnt += write_space(f->width - ft_strlen(str));
	free(str);
	return (cnt);
}

int	put_unsintp(char *str, t_flags *f)
{
	int	cnt;

	cnt = 0;
	if (f->flags == 'q' || f->flags == '0')
		return (ft_unsi_p_q(str, f));
	if (f->flags == '-')
		return (ft_unsi_p_m(str, f));
	return (cnt);
}

int	print_unsi_zero(unsigned int n, t_flags *f)
{
	int		cnt;
	char	*str;

	cnt = 0;
	str = ft_utoa(n);
	if (f->point == 0)
		cnt += put_unsint(n, f);
	else
	{
		if (f->precision_len == 0)
		{
			if (f->width != 0)
				cnt += write_space(f->width);
		}
		else
			cnt += put_unsintp(str, f);
	}
	free(str);
	return (cnt);
}

int	width_zero(t_flags *f, unsigned int a)
{
	int cnt;

	cnt = 0;
	(f->flags == '0') ? f->flags = 'q' : 1;
	cnt += put_unsint(a, f);
	return (cnt);
}

int	print_unsint(t_flags *f, va_list p)
{
	int				cnt;
	unsigned int	a;
	char			*str;

	cnt = 0;
	a = va_arg(p, unsigned int);
	str = ft_utoa(a);
	(a == 0) ? cnt += print_unsi_zero(a, f) : 1;
	if (a != 0)
	{
		(f->point == 0) ? cnt += put_unsint(a, f) : 1;
		if (f->point != 0)
		{
			if (f->precision_len == 0)
			{
				(f->width == 0) ? cnt += write(1, str, ft_strlen(str)) : 1;
				(f->width != 0) ? cnt += width_zero(f, a) : 1;
			}
			(f->precision_len != 0) ? cnt += put_unsintp(str, f) : 1;
		}
	}
	free(str);
	return (cnt);
}

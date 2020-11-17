/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 08:52:22 by ylazrek           #+#    #+#             */
/*   Updated: 2019/12/14 19:47:51 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	cas_minusint(char *str, t_flags *f)
{
	int cnt;

	cnt = 0;
	if (f->flags == 'q' && f->width > ft_strlen(str))
	{
		cnt += write_space(f->width - ft_strlen(str));
		cnt += write(1, str, ft_strlen(str));
	}
	if (f->flags == '0' && f->width > ft_strlen(str))
	{
		cnt += write(1, "-", 1);
		cnt += write_zero(f->width - ft_strlen(str));
		cnt += write(1, str + 1, ft_strlen(str + 1));
	}
	if (f->flags == '-' && f->width > ft_strlen(str))
	{
		cnt += write(1, str, ft_strlen(str));
		cnt += write_space(f->width - ft_strlen(str));
	}
	if (f->width <= ft_strlen(str))
		cnt += write(1, str, ft_strlen(str));
	return (cnt);
}

int	put_int(int n, t_flags *f)
{
	int		cnt;
	char	*str;

	cnt = 0;
	str = ft_itoa(n);
	if (str[0] == '-')
	{
		cnt += cas_minusint(str, f);
		free(str);
		return (cnt);
	}
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

int	print_i_zero(int n, t_flags *f)
{
	int		cnt;
	char	*str;

	cnt = 0;
	str = ft_itoa(n);
	if (f->point == 0)
		cnt += put_int(n, f);
	else
	{
		if (f->precision_len == 0)
		{
			if (f->width != 0)
				cnt += write_space(f->width);
		}
		else
			cnt += put_intp(str, f);
	}
	free(str);
	return (cnt);
}

int	prec_zero(t_flags *f, char *str, int a)
{
	int cnt;

	cnt = 0;
	if (f->width == 0)
		cnt += write(1, str, ft_strlen(str));
	else
	{
		(f->flags == '0') ? f->flags = 'q' : 1;
		cnt += put_int(a, f);
	}
	return (cnt);
}

int	print_int(t_flags *f, va_list p)
{
	int		cnt;
	int		a;
	char	*str;

	cnt = 0;
	a = va_arg(p, int);
	str = ft_itoa(a);
	if (a == 0)
		cnt += print_i_zero(a, f);
	else
	{
		if (f->point == 0)
			cnt += put_int(a, f);
		else
		{
			if (f->precision_len == 0)
				cnt += prec_zero(f, str, a);
			else
				cnt += put_intp(str, f);
		}
	}
	free(str);
	return (cnt);
}

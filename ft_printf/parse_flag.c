/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 09:08:21 by ylazrek           #+#    #+#             */
/*   Updated: 2019/12/14 19:50:05 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialisation_flags(t_flags *f)
{
	f->flags = 'q';
	f->precision_len = 0;
	f->width = 0;
	f->specifier = 'q';
	f->point = 0;
}

void	set_flags(char *s, t_flags *f, int *i)
{
	while (s[*i] == '-' || s[*i] == '0')
	{
		if (s[*i] == '-')
			f->flags = '-';
		if (s[*i] == '0' && f->flags == 'q')
			f->flags = '0';
		*i = *i + 1;
	}
}

void	cas_flagm(t_flags *f)
{
	if (f->width < 0)
	{
		f->flags = '-';
		f->width *= -1;
	}
	if (f->precision_len < 0)
	{
		f->precision_len = 0;
		f->point = 0;
	}
}

int		parse_flags(char *str, t_flags *f, va_list p)
{
	int	i;

	i = 1;
	initialisation_flags(f);
	set_flags(str, f, &i);
	(str[i] == '*') ? f->width = va_arg(p, int) : 1;
	(str[i] == '*') ? i++ : 1;
	(ft_isdigit(str[i])) ? f->width = ft_atoi(&str[i]) : 1;
	(ft_isdigit(str[i])) ? i += countdigit(f->width) : 1;
	(str[i] == '*') ? f->width = va_arg(p, int) : 1;
	(str[i] == '*') ? i++ : 1;
	if (str[i] == '.')
	{
		i++;
		f->point = 1;
		set_flags(str, f, &i);
		(ft_isdigit(str[i])) ? f->precision_len = ft_atoi(&str[i]) : 1;
		(ft_isdigit(str[i])) ? i += countdigit(f->precision_len) : 1;
		(str[i] == '*') ? f->precision_len = va_arg(p, int) : 1;
		(str[i] == '*') ? i++ : 1;
	}
	(ft_isalpha(str[i]) || str[i] == '%') ? f->specifier = str[i] : 1;
	(ft_isalpha(str[i]) || str[i] == '%') ? i++ : 1;
	cas_flagm(f);
	return (i);
}

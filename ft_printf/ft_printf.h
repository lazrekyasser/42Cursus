/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 09:21:48 by ylazrek           #+#    #+#             */
/*   Updated: 2019/12/14 19:52:18 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

typedef	struct	s_flags
{
	char		flags;
	int			precision_len;
	int			point;
	char		specifier;
	int			width;
}				t_flags;
int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_printf(const char *format, ...);
void			initialisation_flags(t_flags *f);
int				print_depspe(t_flags *f, va_list r);
char			*ft_strdup(const char *s);
int				print_car(t_flags *f, va_list p);
int				ft_strlen(const char *s);
int				ft_atoi(const char *s);
char			*ft_utoa(unsigned int n);
char			*ft_itoa(int n);
char			*ft_strdup(const char *s);
int				print_int(t_flags *f, va_list p);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				parse_flags(char *str, t_flags *f, va_list p);
int				write_hex(unsigned int p, t_flags *f);
int				len_hex(unsigned int p);
int				write_zero(int n);
int				write_space(int n);
int				putnstr(char *s, int n);
int				ft_putnstr(char *s, int n);
int				print_string(t_flags *f, va_list p);
int				print_percent(t_flags *f);
int				print_unsint(t_flags *f, va_list p);
int				print_hex(t_flags *f, va_list p);
int				put_car(char s, t_flags *f);
int				countdigit(int n);
int				ft_max(int x, int y);
int				print_pointer(t_flags *f, va_list p);
int				len_pointer(unsigned long int p);
void			write_pointer(unsigned long int n);
int				ft_unsi_p_q(char *str, t_flags *f);
int				ft_unsi_p_m(char *str, t_flags *f);
int				ft_i_p_q(char *str, t_flags *f);
int				ft_i_p_m(char *str, t_flags *f);
int				put_intp(char *str, t_flags *f);
int				put_hex(unsigned int n, t_flags *f);

#endif

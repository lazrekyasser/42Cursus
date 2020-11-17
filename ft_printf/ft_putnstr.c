/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 09:06:44 by ylazrek           #+#    #+#             */
/*   Updated: 2019/12/14 09:07:12 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnstr(char *s, int n)
{
	int	i;

	i = 0;
	while (n-- && s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

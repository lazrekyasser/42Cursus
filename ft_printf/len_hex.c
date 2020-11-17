/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 09:07:33 by ylazrek           #+#    #+#             */
/*   Updated: 2019/12/14 09:08:07 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_hex(unsigned int p)
{
	int	i;

	i = 0;
	if (p == 0)
		return (1);
	while (p)
	{
		p /= 16;
		i++;
	}
	return (i);
}

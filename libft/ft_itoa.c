/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 22:23:50 by ylazrek           #+#    #+#             */
/*   Updated: 2019/11/03 17:23:26 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_lentnbr(int nbr)
{
	int i;

	i = 0;
	while (nbr != 0)
	{
		i++;
		nbr = nbr / 10;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		k;

	k = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0 && (k = 1))
		n = -n;
	i = ft_lentnbr(n);
	if (!(str = (char *)malloc(i + k + 1)))
		return (NULL);
	str[i + k] = '\0';
	(k == 1) ? str[0] = '-' : 0;
	while (n != 0)
	{
		str[i + k - 1] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (str);
}

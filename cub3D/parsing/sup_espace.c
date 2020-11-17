/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sup_espace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 09:55:43 by ylazrek           #+#    #+#             */
/*   Updated: 2020/02/02 09:57:00 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"
#include "parse.h"
#include "check.h"

char	*sup_espace(char *s)
{
	int		i;
	int		n;
	int		j;
	int		k;
	char	*str;

	i = 0;
	k = 0;
	n = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != ' ' && s[i] != '\t')
			n++;
		i++;
	}
	str = (char*)malloc(n + 1);
	while (s[j] != '\0')
	{
		if (s[j] != ' ' && s[j] != '\t')
			str[k++] = s[j];
		j++;
	}
	str[k] = '\0';
	return (str);
}

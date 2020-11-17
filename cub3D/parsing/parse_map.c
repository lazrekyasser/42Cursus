/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 09:44:03 by ylazrek           #+#    #+#             */
/*   Updated: 2020/11/14 11:59:02 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"
#include "parse.h"
#include "check.h"

char	*tab_esp(int len)
{
	char	*t;
	int		i;

	i = 0;
	t = (char*)malloc(len + 1);
	while (i < len)
	{
		t[i] = ' ';
		i++;
	}
	t[i] = '\0';
	return (t);
}

char	*parse_map(char *s, int *inc)
{
	int		len;
	char	*esp;
	char	*tmp;

	len = g_m.mapwidth - ft_strlen(s);
	if (ft_strlen(s) != g_m.mapwidth)
	{
		esp = tab_esp(len);
		tmp = s;
		s = ft_strjoin(s, esp);
		free(tmp);
		free(esp);
		ft_strlcpy(g_m.grid[*inc], s, ft_strlen(s) + 1);
		(*inc)++;
		return (s);
	}
	else
	{
		ft_strlcpy(g_m.grid[*inc], s, ft_strlen(s) + 1);
		(*inc)++;
		return (ft_strdup(s));
	}
	return (ft_strdup(s));
}

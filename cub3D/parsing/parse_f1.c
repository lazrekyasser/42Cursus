/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_f1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 19:57:17 by ylazrek           #+#    #+#             */
/*   Updated: 2020/11/14 09:27:34 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"
#include "parse.h"
#include "check.h"

void	alloc_tab(void)
{
	size_t	a;

	a = 0;
	g_m.grid = (char**)malloc(sizeof(char*) * g_m.mapheigth);
	while (a < g_m.mapheigth)
	{
		g_m.grid[a] = (char*)malloc(sizeof(char) * g_m.mapwidth);
		a++;
	}
}

char	**get_f(char *p)
{
	char	**tab;
	int		ret;
	char	*line;
	int		fd;

	fd = open(p, O_RDONLY);
	if (fd < 0)
	{
		write(1, "error open file\n", 16);
		exit(1);
	}
	tab = new_table();
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		tab = ft_join_table(tab, line);
		free(line);
	}
	tab = ft_join_table(tab, line);
	free(line);
	return (tab);
}

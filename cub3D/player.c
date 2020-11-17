/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 11:51:13 by ylazrek           #+#    #+#             */
/*   Updated: 2020/10/27 18:36:27 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include "parsing/parse.h"
#include "parsing/check.h"
#include "mlx.h"
#include "cub.h"
#include <stdio.h>
#include <math.h>

void	init_ply(t_ply *p)
{
	p->pos.x = 0;
	p->pos.y = 0;
	p->dir.x = 0;
	p->dir.y = 0;
	p->plane.x = 0;
	p->plane.y = 0;
}

void	get_psply(t_ply *p)
{
	size_t	i;
	size_t	j;

	i = 0;
	init_ply(p);
	while (i < g_m.mapheigth)
	{
		j = 0;
		while (j < g_m.mapwidth)
		{
			if (g_m.grid[i][j] == 'N')
				get_nord(p, i, j);
			else if (g_m.grid[i][j] == 'S')
				get_south(p, i, j);
			else if (g_m.grid[i][j] == 'W')
				get_west(p, i, j);
			else if (g_m.grid[i][j] == 'E')
				get_east(p, i, j);
			j++;
		}
		i++;
	}
	if ((p->pos.x == 0 || p->pos.y == 0) && write(2, "error\n", 6))
		exit(1);
}

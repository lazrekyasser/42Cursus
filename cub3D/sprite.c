/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 11:51:45 by ylazrek           #+#    #+#             */
/*   Updated: 2020/11/10 18:21:20 by ylazrek          ###   ########.fr       */
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

void	count_sprite(void)
{
	size_t	i;
	size_t	j;

	i = 0;
	g_nbr_sp = 0;
	while (i < g_m.mapheigth)
	{
		j = 0;
		while (j < g_m.mapwidth)
		{
			if (g_m.grid[i][j] == '2')
				g_nbr_sp++;
			j++;
		}
		i++;
	}
}

void	sort_sprite(t_ply *p)
{
	int		i;
	int		sorted;
	t_spt	tmp;

	sorted = 0;
	while (sorted == 0)
	{
		sorted = 1;
		i = 0;
		while (i < g_nbr_sp - 1)
		{
			if (p->sprite[i].dist < p->sprite[i + 1].dist)
			{
				tmp = p->sprite[i];
				p->sprite[i] = p->sprite[i + 1];
				p->sprite[i + 1] = tmp;
				sorted = 0;
			}
			i++;
		}
	}
}

void	dist_sprite(t_ply *p)
{
	int	i;

	i = 0;
	while (i < g_nbr_sp)
	{
		p->sprite[i].dist = pow(p->pos.x - p->sprite[i].spos.x, 2)
		+ pow(p->pos.y - p->sprite[i].spos.y, 2);
		i++;
	}
}

void	find_sprite1(size_t i, size_t j, int *count, t_spt *sprites)
{
	if (g_m.grid[i][j] == '2')
	{
		sprites[*count].spos.x = i + 0.5;
		sprites[*count].spos.y = j + 0.5;
		(*count)++;
	}
}

void	find_sprite(t_ply *p)
{
	t_spt	*sprites;
	int		count;
	size_t	i;
	size_t	j;

	count_sprite();
	sprites = malloc(sizeof(t_spt) * g_nbr_sp);
	count = 0;
	i = 0;
	while (i < g_m.mapheigth)
	{
		j = 0;
		while (j < g_m.mapwidth)
		{
			find_sprite1(i, j, &count, sprites);
			j++;
		}
		i++;
	}
	p->sprite = sprites;
	dist_sprite(p);
	sort_sprite(p);
	free(sprites);
}

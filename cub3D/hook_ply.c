/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_ply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:22:09 by ylazrek           #+#    #+#             */
/*   Updated: 2020/11/08 09:43:07 by ylazrek          ###   ########.fr       */
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

void	clear(void)
{
	int i;

	i = -1;
	while (++i < g_f.width * g_f.heigth)
		g_mlx.img.data[i] = 0;
}

void	up(t_all *a)
{
	if (g_m.grid[(int)(a->p->pos.x + 0.2 * a->p->dir.x)][(int)(a->p->pos.y)] !=
	'1' &&
	g_m.grid[(int)(a->p->pos.x + 0.2 * a->p->dir.x)][(int)(a->p->pos.y)] != '2')
		a->p->pos.x += 0.2 * a->p->dir.x;
	if (g_m.grid[(int)(a->p->pos.x)][(int)(a->p->pos.y + 0.2 * a->p->dir.y)] !=
	'1' &&
	g_m.grid[(int)(a->p->pos.x)][(int)(a->p->pos.y + 0.2 * a->p->dir.y)] != '2')
		a->p->pos.y += 0.2 * a->p->dir.y;
	clear();
	find_sprite(a->p);
	game_loop(a->f, a->p, a->m, g_save);
}

void	down(t_all *a)
{
	if (g_m.grid[(int)(a->p->pos.x - 0.2 * a->p->dir.x)][(int)(a->p->pos.y)] !=
	'1' &&
	g_m.grid[(int)(a->p->pos.x - 0.2 * a->p->dir.x)][(int)(a->p->pos.y)] != '2')
		a->p->pos.x += -0.2 * a->p->dir.x;
	if (g_m.grid[(int)(a->p->pos.x)][(int)(a->p->pos.y - 0.2 * a->p->dir.y)] !=
	'1' &&
	g_m.grid[(int)(a->p->pos.x)][(int)(a->p->pos.y - 0.2 * a->p->dir.y)] != '2')
		a->p->pos.y += -0.2 * a->p->dir.y;
	clear();
	find_sprite(a->p);
	game_loop(a->f, a->p, a->m, g_save);
}

void	left(t_all *a)
{
	if (g_m.grid[(int)(a->p->pos.x - 0.2 * a->p->plane.x)][(int)(a->p->pos.y)]
	!= '1' &&
	g_m.grid[(int)(a->p->pos.x - 0.2 * a->p->plane.x)][(int)(a->p->pos.y)]
	!= '2')
		a->p->pos.x += -0.2 * a->p->plane.x;
	if (g_m.grid[(int)(a->p->pos.x)][(int)(a->p->pos.y - 0.2 * a->p->plane.y)]
	!= '1' &&
	g_m.grid[(int)(a->p->pos.x)][(int)(a->p->pos.y - 0.2 * a->p->plane.y)]
	!= '2')
		a->p->pos.y += -0.2 * a->p->plane.y;
	clear();
	find_sprite(a->p);
	game_loop(a->f, a->p, a->m, g_save);
}

void	right(t_all *a)
{
	if (g_m.grid[(int)(a->p->pos.x + 0.2 * a->p->plane.x)][(int)(a->p->pos.y)]
	!= '1' &&
	g_m.grid[(int)(a->p->pos.x + 0.2 * a->p->plane.x)][(int)(a->p->pos.y)]
	!= '2')
		a->p->pos.x += 0.2 * a->p->plane.x;
	if (g_m.grid[(int)(a->p->pos.x)][(int)(a->p->pos.y + 0.2 * a->p->plane.y)]
	!= '1' &&
	g_m.grid[(int)(a->p->pos.x)][(int)(a->p->pos.y + 0.2 * a->p->plane.y)]
	!= '2')
		a->p->pos.y += 0.2 * a->p->plane.y;
	clear();
	find_sprite(a->p);
	game_loop(a->f, a->p, a->m, g_save);
}

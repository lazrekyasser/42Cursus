/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_ply1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:23:32 by ylazrek           #+#    #+#             */
/*   Updated: 2020/10/29 17:23:59 by ylazrek          ###   ########.fr       */
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

double	ft_abs(double n)
{
	return ((n < 0) ? n * -1 : n);
}

int		ft_close(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void	rot_left(double rotspeed, double olddirx, double oldplanex, t_all *a)
{
	rotspeed = 0.1;
	olddirx = a->p->dir.x;
	a->p->dir.x = a->p->dir.x * cos(rotspeed) - a->p->dir.y * sin(rotspeed);
	a->p->dir.y = olddirx * sin(rotspeed) + a->p->dir.y * cos(rotspeed);
	oldplanex = a->p->plane.x;
	a->p->plane.x = a->p->plane.x * cos(rotspeed) -
	a->p->plane.y * sin(rotspeed);
	a->p->plane.y = oldplanex * sin(rotspeed) + a->p->plane.y * cos(rotspeed);
	clear();
	find_sprite(a->p);
	game_loop(a->f, a->p, a->m, g_save);
}

void	rot_right(double rotspeed, double olddirx, double oldplanex, t_all *a)
{
	rotspeed = 0.1;
	olddirx = a->p->dir.x;
	a->p->dir.x = a->p->dir.x * cos(-rotspeed) - a->p->dir.y * sin(-rotspeed);
	a->p->dir.y = olddirx * sin(-rotspeed) + a->p->dir.y * cos(-rotspeed);
	oldplanex = a->p->plane.x;
	a->p->plane.x = a->p->plane.x * cos(-rotspeed) -
	a->p->plane.y * sin(-rotspeed);
	a->p->plane.y = oldplanex * sin(-rotspeed) + a->p->plane.y * cos(-rotspeed);
	clear();
	find_sprite(a->p);
	game_loop(a->f, a->p, a->m, g_save);
}

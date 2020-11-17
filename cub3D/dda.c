/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 12:02:14 by ylazrek           #+#    #+#             */
/*   Updated: 2020/11/10 18:20:04 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include "parsing/parse.h"
#include "parsing/check.h"
#include "mlx.h"
#include "cub.h"

void	detect_col(t_ply *p, int color, t_vec2 *d, t_vec2 *t)
{
	if (color == p->wl.col_c)
	{
		d->x = p->wl.start.x - p->wl.c.x;
		d->y = p->wl.start.y - p->wl.c.y;
		t->x = p->wl.c.x;
		t->y = p->wl.c.y;
	}
	else if (color == p->wl.col_f)
	{
		d->x = p->wl.end.x - p->wl.f.x;
		d->y = p->wl.end.y - p->wl.f.y;
		t->x = p->wl.f.x;
		t->y = p->wl.f.y;
	}
}

void	dda(t_ply *p, t_mlx *mlx, t_para *f, int color)
{
	t_vec2	d;
	t_vec2	t;
	t_vec2	inc;
	int		i;
	int		steps;

	i = 0;
	detect_col(p, color, &d, &t);
	steps = ft_abs(d.x) > ft_abs(d.y) ? ft_abs(d.x) : ft_abs(d.y);
	inc.x = d.x / (float)steps;
	inc.y = d.y / (float)steps;
	while (i <= steps)
	{
		if (t.x < f->width && t.x >= 0 && t.y < f->heigth && t.y >= 0)
			mlx->img.data[(int)(t.y * f->width + t.x)] = color;
		t.x += inc.x;
		t.y += inc.y;
		i++;
	}
}

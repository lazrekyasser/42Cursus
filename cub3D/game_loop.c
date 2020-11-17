/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 09:42:16 by ylazrek           #+#    #+#             */
/*   Updated: 2020/11/09 20:12:55 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include "parsing/parse.h"
#include "parsing/check.h"
#include "mlx.h"
#include <math.h>
#include "cub.h"

double	dot_vec2(t_vec2 v1, t_vec2 v2)
{
	double	a;

	a = 0;
	a = (v1.x * v2.x) + (v1.y * v2.y);
	return (a);
}

int		is_up(t_vec2 v)
{
	t_vec2	a;

	a.x = -1;
	a.y = 0;
	if (dot_vec2(v, a) >= 0)
		return (1);
	return (0);
}

int		is_right(t_vec2 v)
{
	t_vec2	a;

	a.x = 0;
	a.y = 1;
	if (dot_vec2(v, a) >= 0)
		return (1);
	return (0);
}

double	*cast_wall(t_para *f, t_ply *p, t_mlx *mlx)
{
	int		c;
	double	*zbuffer;

	c = 0;
	zbuffer = (double*)malloc(sizeof(double) * f->width);
	while (c < f->width)
	{
		p->wl.camerax = 2 * (c / (double)f->width) - 1;
		p->wl.raydir.x = p->dir.x + p->plane.x * p->wl.camerax;
		p->wl.raydir.y = p->dir.y + p->plane.y * p->wl.camerax;
		p->wl.map.x = (int)p->pos.x;
		p->wl.map.y = (int)p->pos.y;
		p->wl.deltadist.x = ft_abs(1 / p->wl.raydir.x);
		p->wl.deltadist.y = ft_abs(1 / p->wl.raydir.y);
		cast_wall1(p);
		cast_wall2(p);
		cast_wall3(f, p, c);
		cast_wall4(p);
		cast_wall5(f, p, mlx, c);
		zbuffer[c] = p->wl.perpwalldist;
		dda(p, mlx, f, p->wl.col_c);
		dda(p, mlx, f, p->wl.col_f);
		c++;
	}
	return (zbuffer);
}

void	game_loop(t_para *f, t_ply *p, t_mlx *mlx, int save)
{
	double	*t;

	t = cast_wall(f, p, mlx);
	cast_sprite(f, p, mlx, t);
	free(t);
	if (save == 0)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
}

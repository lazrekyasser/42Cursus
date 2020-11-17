/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 20:13:58 by ylazrek           #+#    #+#             */
/*   Updated: 2020/11/10 18:19:24 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include "parsing/parse.h"
#include "parsing/check.h"
#include "mlx.h"
#include <math.h>
#include "cub.h"

void	cast_wall1(t_ply *p)
{
	p->wl.hit = 0;
	if (p->wl.raydir.x < 0)
	{
		p->wl.stepx = -1;
		p->wl.sidedist.x = (p->pos.x - p->wl.map.x) * p->wl.deltadist.x;
	}
	else
	{
		p->wl.stepx = 1;
		p->wl.sidedist.x = (p->wl.map.x + 1.0 - p->pos.x) *
		p->wl.deltadist.x;
	}
	if (p->wl.raydir.y < 0)
	{
		p->wl.stepy = -1;
		p->wl.sidedist.y = (p->pos.y - p->wl.map.y) * p->wl.deltadist.y;
	}
	else
	{
		p->wl.stepy = 1;
		p->wl.sidedist.y = (p->wl.map.y + 1.0 - p->pos.y) *
		p->wl.deltadist.y;
	}
}

void	cast_wall2(t_ply *p)
{
	while (p->wl.hit == 0)
	{
		if (p->wl.sidedist.x < p->wl.sidedist.y)
		{
			p->wl.sidedist.x += p->wl.deltadist.x;
			p->wl.map.x += p->wl.stepx;
			p->wl.side = 0;
		}
		else
		{
			p->wl.sidedist.y += p->wl.deltadist.y;
			p->wl.map.y += p->wl.stepy;
			p->wl.side = 1;
		}
		if (g_m.grid[(int)p->wl.map.x][(int)p->wl.map.y] == '1')
			p->wl.hit = 1;
	}
}

void	cast_wall3(t_para *f, t_ply *p, int c)
{
	if (p->wl.side == 0)
		p->wl.perpwalldist = (p->wl.map.x - p->pos.x +
		(1 - p->wl.stepx) / 2) / p->wl.raydir.x;
	else
		p->wl.perpwalldist = (p->wl.map.y - p->pos.y +
		(1 - p->wl.stepy) / 2) / p->wl.raydir.y;
	p->wl.lineheight = (int)(f->heigth / p->wl.perpwalldist);
	p->wl.drawstart = -p->wl.lineheight / 2 + f->heigth / 2;
	if (p->wl.drawstart < 0)
		p->wl.drawstart = 0;
	p->wl.drawend = p->wl.lineheight / 2 + f->heigth / 2;
	if (p->wl.drawend >= f->heigth)
		p->wl.drawend = f->heigth - 1;
	p->wl.c.x = c;
	p->wl.c.y = 0;
	p->wl.f.x = c;
	p->wl.f.y = f->heigth - 1;
	p->wl.start.x = c;
	p->wl.start.y = p->wl.drawstart;
	p->wl.end.x = c;
	p->wl.end.y = p->wl.drawend;
	p->wl.col_c = f->c.r * pow(256, 2) + f->c.g * 256 + f->c.b;
	p->wl.col_f = f->f.r * pow(256, 2) + f->f.g * 256 + f->f.b;
}

void	cast_wall4(t_ply *p)
{
	if (p->wl.side == 0)
	{
		if (is_up(p->wl.raydir) > 0)
			p->wl.num_text = 1;
		else
			p->wl.num_text = 0;
	}
	else
	{
		if (is_right(p->wl.raydir) > 0)
			p->wl.num_text = 2;
		else
			p->wl.num_text = 3;
	}
	if (p->wl.side == 0)
		p->wl.wallx = p->pos.y + p->wl.perpwalldist * p->wl.raydir.y;
	else
		p->wl.wallx = p->pos.x + p->wl.perpwalldist * p->wl.raydir.x;
	p->wl.wallx -= floor((p->wl.wallx));
	p->wl.texx = (int)(p->wl.wallx * (double)(g_textw));
	if (p->wl.side == 0 && p->wl.raydir.x < 0)
		p->wl.texx = g_textw - p->wl.texx - 1;
	if (p->wl.side == 1 && p->wl.raydir.y > 0)
		p->wl.texx = g_textw - p->wl.texx - 1;
}

void	cast_wall5(t_para *f, t_ply *p, t_mlx *mlx, int c)
{
	p->wl.step = (1.0 * g_texth) / p->wl.lineheight;
	p->wl.texpos = (p->wl.drawstart - f->heigth / 2 + p->wl.lineheight / 2)
	* p->wl.step;
	p->wl.y = p->wl.drawstart;
	while (p->wl.y < p->wl.drawend)
	{
		p->wl.texy = ((int)(p->wl.texpos)) & (g_texth - 1);
		p->wl.texpos += p->wl.step;
		mlx->img.data[(int)(p->wl.y * f->width + c)] =
		mlx->texture[p->wl.num_text].data[(int)(g_texth
		* p->wl.texy + p->wl.texx)];
		p->wl.y++;
	}
}

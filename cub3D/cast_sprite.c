/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 20:10:16 by ylazrek           #+#    #+#             */
/*   Updated: 2020/10/27 20:11:07 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include "parsing/parse.h"
#include "parsing/check.h"
#include "mlx.h"
#include <math.h>
#include "cub.h"

void	cast_sprite1(t_para *f, t_ply *p, int i)
{
	p->sp.spritex = p->sprite[i].spos.x - p->pos.x;
	p->sp.spritey = p->sprite[i].spos.y - p->pos.y;
	p->sp.invdet = 1.0 / (p->plane.x * p->dir.y - p->dir.x * p->plane.y);
	p->sp.transformx = p->sp.invdet *
	(p->dir.y * p->sp.spritex - p->dir.x * p->sp.spritey);
	p->sp.transformy = p->sp.invdet *
	(-p->plane.y * p->sp.spritex + p->plane.x * p->sp.spritey);
	p->sp.spritescreenx = (int)((f->width / 2) *
	(1 + p->sp.transformx / p->sp.transformy));
	p->sp.spriteheight = ft_abs((int)(f->heigth / (p->sp.transformy)));
	p->sp.drawstarty = -p->sp.spriteheight / 2 + f->heigth / 2;
	if (p->sp.drawstarty < 0)
		p->sp.drawstarty = 0;
	p->sp.drawendy = p->sp.spriteheight / 2 + f->heigth / 2;
	if (p->sp.drawendy >= f->heigth)
		p->sp.drawendy = f->heigth - 1;
	p->sp.spritewidth = ft_abs((int)(f->heigth / (p->sp.transformy)));
	p->sp.drawstartx = -p->sp.spritewidth / 2 + p->sp.spritescreenx;
	if (p->sp.drawstartx < 0)
		p->sp.drawstartx = 0;
	p->sp.drawendx = p->sp.spritewidth / 2 + p->sp.spritescreenx;
	if (p->sp.drawendx >= f->width)
		p->sp.drawendx = f->width - 1;
	p->sp.stripe = p->sp.drawstartx;
}

void	cast_sprite2(t_para *f, t_ply *p, t_mlx *mlx, double *t)
{
	p->sp.texx = (int)(256 * (p->sp.stripe - (-p->sp.spritewidth / 2 +
	p->sp.spritescreenx)) * g_textw / p->sp.spritewidth) / 256;
	if (p->sp.transformy > 0 && p->sp.stripe > 0 &&
	p->sp.stripe < f->width && p->sp.transformy < t[p->sp.stripe])
	{
		p->sp.y = p->sp.drawstarty;
		while (p->sp.y < p->sp.drawendy)
		{
			p->sp.d = (p->sp.y) * 256 - f->heigth * 128 +
			p->sp.spriteheight * 128;
			p->sp.texy = ((p->sp.d * g_texth) /
			p->sp.spriteheight) / 256;
			p->sp.color =
			mlx->texture[4].data[(int)(g_textw * p->sp.texy
			+ p->sp.texx)];
			if ((p->sp.color & 0x00FFFFFF) != 0)
				mlx->img.data[(int)(p->sp.y * f->width +
				p->sp.stripe)] = p->sp.color;
			p->sp.y++;
		}
	}
	p->sp.stripe++;
}

void	cast_sprite(t_para *f, t_ply *p, t_mlx *mlx, double *t)
{
	int i;

	i = 0;
	while (i < g_nbr_sp)
	{
		cast_sprite1(f, p, i);
		while (p->sp.stripe < p->sp.drawendx)
			cast_sprite2(f, p, mlx, t);
		i++;
	}
}

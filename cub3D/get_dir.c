/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 12:02:51 by ylazrek           #+#    #+#             */
/*   Updated: 2020/10/24 12:02:53 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include "parsing/parse.h"
#include "parsing/check.h"
#include "mlx.h"
#include "cub.h"

void	get_nord(t_ply *p, int i, int j)
{
	if (p->pos.x != 0 || p->pos.y != 0 || p->dir.x != 0 || p->dir.y != 0)
	{
		write(1, "error\n", 6);
		exit(1);
	}
	p->dir.x = -1;
	p->dir.y = 0;
	p->pos.x = i + 0.5;
	p->pos.y = j + 0.5;
	p->plane.x = 0;
	p->plane.y = 0.66;
}

void	get_south(t_ply *p, int i, int j)
{
	if (p->pos.x != 0 || p->pos.y != 0 || p->dir.x != 0 || p->dir.y != 0)
	{
		write(1, "error\n", 6);
		exit(1);
	}
	p->dir.x = 1;
	p->dir.y = 0;
	p->pos.x = i + 0.5;
	p->pos.y = j + 0.5;
	p->plane.x = 0;
	p->plane.y = -0.66;
}

void	get_west(t_ply *p, int i, int j)
{
	if (p->pos.x != 0 || p->pos.y != 0 || p->dir.x != 0 || p->dir.y != 0)
	{
		write(1, "error\n", 6);
		exit(1);
	}
	p->dir.x = 0;
	p->dir.y = -1;
	p->pos.x = i + 0.5;
	p->pos.y = j + 0.5;
	p->plane.x = -0.66;
	p->plane.y = 0;
}

void	get_east(t_ply *p, int i, int j)
{
	if (p->pos.x != 0 || p->pos.y != 0 || p->dir.x != 0 || p->dir.y != 0)
	{
		write(1, "error\n", 6);
		exit(1);
	}
	p->dir.x = 0;
	p->dir.y = 1;
	p->pos.x = i + 0.5;
	p->pos.y = j + 0.5;
	p->plane.x = 0.66;
	p->plane.y = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inisialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 09:15:38 by ylazrek           #+#    #+#             */
/*   Updated: 2020/03/10 18:46:27 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"
#include "parse.h"
#include "check.h"

void	init_para(t_para *f)
{
	f->width = 0;
	f->heigth = 0;
	f->no = "q";
	f->so = "q";
	f->we = "q";
	f->ea = "q";
	f->s = "q";
	f->f.r = -1;
	f->f.g = -1;
	f->f.b = -1;
	f->c.r = -1;
	f->c.g = -1;
	f->c.b = -1;
}

void	init_map(void)
{
	g_m.mapwidth = 0;
	g_m.mapheigth = 0;
	g_m.grid = NULL;
}

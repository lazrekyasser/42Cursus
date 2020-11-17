/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 09:17:16 by ylazrek           #+#    #+#             */
/*   Updated: 2020/11/14 12:08:13 by ylazrek          ###   ########.fr       */
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

int		key_press(int key, void *param)
{
	t_all	*a;
	double	rotspeed;
	double	olddirx;
	double	oldplanex;

	rotspeed = 0.0;
	olddirx = 0.0;
	oldplanex = 0.0;
	a = (t_all *)param;
	if (key == 53)
		exit(1);
	if (key == 13)
		up(a);
	else if (key == 1)
		down(a);
	else if (key == 0)
		left(a);
	else if (key == 2)
		right(a);
	else if (key == 123)
		rot_left(rotspeed, olddirx, oldplanex, a);
	else if (key == 124)
		rot_right(rotspeed, olddirx, oldplanex, a);
	return (0);
}

void	key_handel(t_all *a)
{
	mlx_hook(g_mlx.win, 17, 0, ft_close, (void *)0);
	mlx_hook(g_mlx.win, 2, 0, key_press, a);
}

void	save(t_all *a, char **t)
{
	bitmap();
	free(a);
	free_grid();
	free_table(t);
	exit(1);
}

void	init_win(t_para *g_f, t_ply *p, char **t)
{
	t_all *a;

	g_mlx.mlx_ptr = mlx_init();
	if (g_save == 0)
		g_mlx.win = mlx_new_window(g_mlx.mlx_ptr, g_f->width,
		g_f->heigth, "cub");
	g_mlx.img.img_ptr = mlx_new_image(g_mlx.mlx_ptr, g_f->width, g_f->heigth);
	g_mlx.img.data = (int *)mlx_get_data_addr(g_mlx.img.img_ptr,
	&g_mlx.img.bpp, &g_mlx.img.size_l, &g_mlx.img.endian);
	load_texture(&g_mlx, g_f);
	find_sprite(p);
	game_loop(g_f, p, &g_mlx, g_save);
	a = (t_all *)malloc(sizeof(t_all));
	a->f = g_f;
	a->m = &g_mlx;
	a->p = p;
	if (g_save == 1)
		save(a, t);
	key_handel(a);
	mlx_loop(g_mlx.mlx_ptr);
	free(a);
}

int		main(int ac, char **av)
{
	t_ply	p;
	char	**t;

	g_save = 0;
	if (ac >= 2)
	{
		t = parse_f(av[1], &g_f);
		get_psply(&p);
		if (ac == 3)
			(ft_strncmp(av[2], "--save", 6) != 0) ? error_msg(t) : 1;
		if (ac == 3 && (ft_strncmp(av[2], "--save", 6) == 0))
			g_save = 1;
		init_win(&g_f, &p, t);
		free_table(t);
		free_grid();
	}
	else
	{
		write(1, "error\n", 6);
		exit(1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 09:42:02 by ylazrek           #+#    #+#             */
/*   Updated: 2020/11/14 19:17:38 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"
#include "../parsing/parse.h"
#include "../parsing/check.h"
#include "mlx.h"
#include "../cub.h"
#include <stdio.h>
#include <math.h>

void	error_lod(void)
{
	write(1, "error\n", 6);
	write(1, "error loading/n", 14);
	exit(1);
}

void	data_text(t_mlx *mlx)
{
	mlx->texture[0].data = (int*)mlx_get_data_addr(mlx->texture[0].img_ptr,
	&mlx->texture[0].bpp, &mlx->texture[0].size_l, &mlx->texture[0].endian);
	mlx->texture[1].data = (int*)mlx_get_data_addr(mlx->texture[1].img_ptr,
	&mlx->texture[1].bpp, &mlx->texture[1].size_l, &mlx->texture[1].endian);
	mlx->texture[2].data = (int*)mlx_get_data_addr(mlx->texture[2].img_ptr,
	&mlx->texture[2].bpp, &mlx->texture[2].size_l, &mlx->texture[2].endian);
	mlx->texture[3].data = (int*)mlx_get_data_addr(mlx->texture[3].img_ptr,
	&mlx->texture[3].bpp, &mlx->texture[3].size_l, &mlx->texture[3].endian);
	mlx->texture[4].data = (int*)mlx_get_data_addr(mlx->texture[4].img_ptr,
	&mlx->texture[4].bpp, &mlx->texture[4].size_l, &mlx->texture[4].endian);
}

void	load_texture(t_mlx *mlx, t_para *f)
{
	if (!(mlx->texture[0].img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
	f->no, &g_textw, &g_texth)))
		error_lod();
	if (!(mlx->texture[1].img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
	f->so, &g_textw, &g_texth)))
		error_lod();
	if (!(mlx->texture[2].img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
	f->we, &g_textw, &g_texth)))
		error_lod();
	if (!(mlx->texture[3].img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
	f->ea, &g_textw, &g_texth)))
		error_lod();
	if (!(mlx->texture[4].img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
	f->s, &g_textw, &g_texth)))
		error_lod();
	data_text(mlx);
}

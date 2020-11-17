/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 12:03:30 by ylazrek           #+#    #+#             */
/*   Updated: 2020/11/08 13:00:19 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include "parsing/parse.h"
#include "parsing/check.h"
#include "mlx.h"
#include <math.h>
#include "cub.h"

static t_bmp	new_bmp(int w, int h, t_file_bmp *f_bmp)
{
	t_bmp	bmp;

	f_bmp->file_size = 54 + 4 * w * h;
	f_bmp->reserved = 0;
	f_bmp->offset = 54;
	f_bmp->header_size = 54 - 14;
	f_bmp->width = w;
	f_bmp->height = -h;
	bmp.plane[0] = 1;
	bmp.plane[1] = 0;
	bmp.bpp[0] = 32;
	bmp.bpp[1] = 0;
	bmp.compression = 0;
	bmp.bit_size = 4 * w * h;
	bmp.perpexx = 0;
	bmp.perpexy = 0;
	bmp.num_color = 0;
	bmp.imp_color = 0;
	return (bmp);
}

void			write_inverse(int *line, int w, int fd)
{
	int i;

	i = 0;
	while (i < w)
	{
		write(fd, &line[i], 4);
		i++;
	}
}

void			write_bitmap(int *data, int h, int w, int fd)
{
	int i;

	i = 0;
	while (i < h)
	{
		write_inverse(&data[i * w], w, fd);
		i++;
	}
}

void			bitmap(void)
{
	t_bmp		bmp;
	int			fd;
	t_file_bmp	f_bmp;

	bmp = new_bmp(g_f.width, g_f.heigth, &f_bmp);
	fd = open("save.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	write(fd, "BM", 2);
	write(fd, &f_bmp, 24);
	write(fd, &bmp, 28);
	write_bitmap(g_mlx.img.data, g_f.heigth, g_f.width, fd);
	close(fd);
}

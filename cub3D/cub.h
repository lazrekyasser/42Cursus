/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 09:42:25 by ylazrek           #+#    #+#             */
/*   Updated: 2020/11/09 19:27:30 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# include <fcntl.h>
# define SIZE 2

typedef struct	s_file_bmp
{
	int			file_size;
	int			reserved;
	int			offset;
	int			header_size;
	int			width;
	int			height;
}				t_file_bmp;

typedef struct	s_bmp
{
	char		plane[SIZE];
	char		bpp[SIZE];
	int			compression;
	int			bit_size;
	int			perpexx;
	int			perpexy;
	int			num_color;
	int			imp_color;
}				t_bmp;

typedef	struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef	struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
	t_img		img;
	t_img		texture[5];
}				t_mlx;

typedef	struct	s_vec2
{
	double		x;
	double		y;
}				t_vec2;

typedef	struct	s_spt
{
	t_vec2		spos;
	double		dist;
}				t_spt;

typedef	struct	s_wll
{
	double		camerax;
	t_vec2		raydir;
	t_vec2		map;
	t_vec2		sidedist;
	t_vec2		deltadist;
	double		perpwalldist;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
	t_vec2		start;
	t_vec2		end;
	t_vec2		c;
	t_vec2		f;
	double		wallx;
	int			texx;
	double		step;
	int			col_c;
	int			col_f;
	int			num_text;
	double		texpos;
	int			y;
	int			texy;
}				t_wll;

typedef	struct	s_fc
{
	int			t;
	float		posz;
	float		raydirx0;
	float		raydiry0;
	float		raydirx1;
	float		raydiry1;
	float		rowdistance;
	float		floorstepx;
	float		floorstepy;
	float		floorx;
	float		floory;
	int			cellx;
	int			celly;
	int			tx;
	int			ty;
}				t_fc;

typedef	struct	s_csp
{
	double		spritex;
	double		spritey;
	double		invdet;
	double		transformx;
	double		transformy;
	int			spritescreenx;
	int			spriteheight;
	int			drawstarty;
	int			drawendy;
	int			spritewidth;
	int			drawstartx;
	int			drawendx;
	int			stripe;
	int			texx;
	int			y;
	int			d;
	int			texy;
	int			color;
}				t_csp;

typedef	struct	s_ply
{
	t_vec2		pos;
	t_vec2		dir;
	t_vec2		plane;
	t_spt		*sprite;
	t_wll		wl;
	t_fc		fc;
	t_csp		sp;
}				t_ply;

typedef	struct	s_all
{
	t_para		*f;
	t_ply		*p;
	t_mlx		*m;
}				t_all;

int				g_nbr_sp;
t_mlx			g_mlx;
int				g_textw;
int				g_texth;
int				g_save;

void			clear(void);
double			ft_abs(double n);
int				ft_close(void *param);
double			dot_vec2(t_vec2 v1, t_vec2 v2);
int				is_up(t_vec2 v);
int				is_right(t_vec2 v);
void			get_nord(t_ply *p, int i, int j);
void			get_south(t_ply *p, int i, int j);
void			get_west(t_ply *p, int i, int j);
void			get_east(t_ply *p, int i, int j);
void			get_psply(t_ply *p);
void			init_ply(t_ply *p);
void			init_win(t_para *f, t_ply *p, char **t);
double			ft_abs(double n);
void			dda(t_ply *p, t_mlx *mlx, t_para *f, int color);
void			detect_col(t_ply *p, int color, t_vec2 *d, t_vec2 *t);
void			game_loop(t_para *f, t_ply *p, t_mlx *mlx, int save);
int				avance_key(int key, void *param);
void			load_texture(t_mlx *mlx, t_para *f);
void			bitmap(void);
void			save(t_all *a, char **t);
void			write_bitmap(int *data, int h, int w, int fd);
void			write_inverse(int *line, int w, int fd);
void			count_sprite();
void			find_sprite(t_ply *p);
void			find_sprite1(size_t i, size_t j, int *count, t_spt *sprites);
void			dist_sprite(t_ply *p);
void			sort_sprite(t_ply *p);
void			data_text(t_mlx *mlx);
void			error_lod(void);
double			*cast_wall(t_para *f, t_ply *p, t_mlx *mlx);
void			cast_wall1(t_ply *p);
void			cast_wall2(t_ply *p);
void			cast_wall3(t_para *f, t_ply *p, int c);
void			cast_wall4(t_ply *p);
void			cast_wall5(t_para *f, t_ply *p, t_mlx *mlx, int c);
void			cast_sprite(t_para *f, t_ply *p, t_mlx *mlx, double *t);
void			cast_sprite1(t_para *f, t_ply *p, int i);
void			cast_sprite2(t_para *f, t_ply *p, t_mlx *mlx, double *t);
void			up(t_all	*a);
void			down(t_all	*a);
void			left(t_all	*a);
void			right(t_all	*a);
void			rot_left(double rotspeed, double olddirx,
double oldplanex, t_all *a);
void			rot_right(double rotspeed, double olddirx,
double oldplanex, t_all *a);

#endif

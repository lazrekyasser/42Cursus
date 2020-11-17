/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 09:26:11 by ylazrek           #+#    #+#             */
/*   Updated: 2020/10/27 18:32:13 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

typedef struct	s_col
{
	float		r;
	float		g;
	float		b;
}				t_col;

typedef struct	s_para
{
	int			width;
	int			heigth;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	t_col		f;
	t_col		c;
}				t_para;

typedef struct	s_map
{
	size_t		mapwidth;
	size_t		mapheigth;
	char		**grid;
}				t_map;

t_map			g_m;
t_para			g_f;

#endif

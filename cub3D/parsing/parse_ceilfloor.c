/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ceilfloor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 09:48:09 by ylazrek           #+#    #+#             */
/*   Updated: 2020/11/14 11:23:03 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"
#include "parse.h"
#include "check.h"

static int	count_virgule(char *s)
{
	int i;
	int r;

	i = 0;
	r = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ',')
			r++;
		i++;
	}
	return (r);
}

void		parse_sol1(int len1, t_para *f, char **tab, char **str)
{
	if (len1 == 3)
	{
		f->f.r = ft_atoi(tab[0]);
		f->f.g = ft_atoi(tab[1]);
		f->f.b = ft_atoi(tab[2]);
		if (f->f.r < 0 || f->f.r > 255 || f->f.g < 0 || f->f.g > 255 ||
		f->f.b < 0 || f->f.b > 255 || is_num(tab[0]) != 0 ||
		is_num(tab[1]) != 0 || is_num(tab[2]) != 0)
		{
			error_msg(tab);
			free_table(str);
		}
		free_table(str);
		free_table(tab);
	}
	else
	{
		free_table(tab);
		error_msg(str);
	}
}

void		parse_sol(char *s, t_para *f)
{
	char	**str;
	char	**tab;
	int		len;
	int		len1;

	if (f->f.r != -1 || f->f.g != -1 || f->f.b != -1)
	{
		write(1, "error\n", 6);
		exit(1);
	}
	str = ft_split(s, ' ');
	len = count_table(str);
	if (len == 2)
	{
		(ft_strncmp(str[0], "F", ft_strlen(str[0])) != 0) ? error_msg(str) : 1;
		if (count_virgule(str[1]) >= 3 || count_virgule(str[1]) < 2)
			error_msg(str);
		tab = ft_split(str[1], ',');
		len1 = count_table(tab);
		parse_sol1(len1, f, tab, str);
	}
	else
		error_msg(str);
}

void		parse_plafont1(int len1, t_para *f, char **tab, char **str)
{
	if (len1 == 3)
	{
		f->c.r = ft_atoi(tab[0]);
		f->c.g = ft_atoi(tab[1]);
		f->c.b = ft_atoi(tab[2]);
		if (f->c.r < 0 || f->c.r > 255 || f->c.g < 0 || f->c.g > 255 ||
		f->c.b < 0 || f->c.b > 255 || is_num(tab[0]) != 0 ||
		is_num(tab[1]) != 0 || is_num(tab[2]) != 0)
		{
			error_msg(tab);
			free_table(str);
		}
		free_table(str);
		free_table(tab);
	}
	else
	{
		free_table(tab);
		error_msg(str);
	}
}

void		parse_plafont(char *s, t_para *f)
{
	char	**str;
	char	**tab;
	int		len;
	int		len1;

	if (f->c.r != -1 || f->c.g != -1 || f->c.b != -1)
	{
		write(1, "error\n", 6);
		exit(1);
	}
	str = ft_split(s, ' ');
	len = count_table(str);
	if (len == 2)
	{
		(ft_strncmp(str[0], "C", ft_strlen(str[0])) != 0) ? error_msg(str) : 1;
		if (count_virgule(str[1]) >= 3 || count_virgule(str[1]) < 2)
			error_msg(str);
		tab = ft_split(str[1], ',');
		len1 = count_table(tab);
		parse_plafont1(len1, f, tab, str);
	}
	else
		error_msg(str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 09:30:50 by ylazrek           #+#    #+#             */
/*   Updated: 2020/10/27 19:58:00 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"
#include "parse.h"
#include "check.h"

void	get_info(char **tab, t_para *f, int *i)
{
	while (tab[*i] != NULL)
	{
		if (!(ft_strncmp(tab[*i], "R", 1)))
			parse_resolution(tab[*i], f);
		else if (!(ft_strncmp(tab[*i], "NO", 2)))
			parse_nord(tab[*i], f);
		else if (!(ft_strncmp(tab[*i], "SO", 2)))
			parse_south(tab[*i], f);
		else if (!(ft_strncmp(tab[*i], "WE", 2)))
			parse_west(tab[*i], f);
		else if (!(ft_strncmp(tab[*i], "EA", 2)))
			parse_east(tab[*i], f);
		else if (!(ft_strncmp(tab[*i], "S", 1)))
			parse_spirite(tab[*i], f);
		else if (!(ft_strncmp(tab[*i], "F", 1)))
			parse_sol(tab[*i], f);
		else if (!(ft_strncmp(tab[*i], "C", 1)))
			parse_plafont(tab[*i], f);
		else if (!(ft_strncmp(tab[*i], "1", 1)) ||
		!(ft_strncmp(tab[*i], " ", 1)))
			break ;
		else if (tab[*i][0] != '\0')
			error_msg(tab);
		(*i)++;
	}
}

void	get_map(char **tab, int *i, int *inc)
{
	char	*tmp;

	while (tab[*i] != NULL)
	{
		if (!(ft_strncmp(tab[*i], "1", 1)) || !(ft_strncmp(tab[*i], " ", 1)))
		{
			tmp = parse_map(tab[*i], inc);
			tab[*i] = ft_strdup(tmp);
			free(tmp);
		}
		else
			error_msg(tab);
		(*i)++;
	}
}

void	free_grid(void)
{
	size_t	i;

	i = 0;
	while (i < g_m.mapheigth)
	{
		free(g_m.grid[i]);
		i++;
	}
	free(g_m.grid);
}

int		get_max(char **t)
{
	int		i;
	size_t	max;

	i = 0;
	max = ft_strlen(t[i]);
	while (t[i] != NULL)
	{
		if (ft_strlen(t[i]) > max)
			max = ft_strlen(t[i]);
		i++;
	}
	return (max);
}

char	**parse_f(char *p, t_para *f)
{
	char	**tab;
	int		i;
	int		j;
	int		inc;

	inc = 0;
	i = 0;
	j = 0;
	init_para(f);
	init_map();
	tab = get_f(p);
	check_firsterror(tab);
	get_info(tab, f, &i);
	check_2error(f, tab);
	g_m.mapheigth = count_table(tab + i);
	g_m.mapwidth = get_max(tab + i);
	alloc_tab();
	get_map(tab, &i, &inc);
	last_check(tab);
	return (tab);
}

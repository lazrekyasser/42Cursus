/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 09:09:49 by ylazrek           #+#    #+#             */
/*   Updated: 2020/11/15 16:33:06 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"
#include "parse.h"
#include "check.h"

void	check_edge(size_t i, size_t j, char **t)
{
	if (j == 0)
	{
		if ((g_m.grid[i - 1][j] != ' ' && g_m.grid[i - 1][j] != '1') ||
		(g_m.grid[i + 1][j] != ' ' && g_m.grid[i + 1][j] != '1') ||
		(g_m.grid[i][j + 1] != ' ' && g_m.grid[i][j + 1] != '1'))
			error_msg(t);
	}
	else if (j == g_m.mapwidth - 1)
	{
		if ((g_m.grid[i - 1][j] != ' ' && g_m.grid[i - 1][j] != '1') ||
		(g_m.grid[i + 1][j] != ' ' && g_m.grid[i + 1][j] != '1') ||
		(g_m.grid[i][j - 1] != ' ' && g_m.grid[i][j - 1] != '1'))
			error_msg(t);
	}
	else
	{
		if ((g_m.grid[i - 1][j] != ' ' && g_m.grid[i - 1][j] != '1') ||
		(g_m.grid[i + 1][j] != ' ' && g_m.grid[i + 1][j] != '1') ||
		(g_m.grid[i][j + 1] != ' ' && g_m.grid[i][j + 1] != '1') ||
		(g_m.grid[i][j - 1] != ' ' && g_m.grid[i][j - 1] != '1'))
			error_msg(t);
	}
}

void	check_top(char **t)
{
	size_t	i;

	i = 0;
	while (i < g_m.mapwidth)
	{
		if (g_m.grid[0][i] != '1' && g_m.grid[0][i] != ' ')
		{
			error_msg(t);
		}
		if (g_m.grid[0][i] == ' ')
			check_up(0, i, t);
		i++;
	}
}

void	check_bottom(char **t)
{
	size_t	i;

	i = 0;
	while (i < g_m.mapwidth)
	{
		if (g_m.grid[g_m.mapheigth - 1][i] != '1' &&
		g_m.grid[g_m.mapheigth - 1][i] != ' ')
			error_msg(t);
		if (g_m.grid[g_m.mapheigth - 1][i] == ' ')
			check_down(g_m.mapheigth - 1, i, t);
		i++;
	}
}

void	check_corps(char **t)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (i < g_m.mapheigth - 1)
	{
		j = 0;
		if (g_m.grid[i][g_m.mapwidth - 1] == '2' ||
		g_m.grid[i][g_m.mapwidth - 1] == '0' ||
		g_m.grid[i][g_m.mapwidth - 1] == 'N' ||
		g_m.grid[i][g_m.mapwidth - 1] == 'E' ||
		g_m.grid[i][g_m.mapwidth - 1] == 'W' ||
		g_m.grid[i][g_m.mapwidth - 1] == 'S')
			error_msg(t);
		while (j < g_m.mapwidth)
		{
			if (g_m.grid[i][j] == ' ')
				check_edge(i, j, t);
			j++;
		}
		i++;
	}
}

void	last_check(char **tab)
{
	check_top(tab);
	check_bottom(tab);
	check_corps(tab);
}

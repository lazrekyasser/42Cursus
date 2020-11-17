/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_updwn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:32:42 by ylazrek           #+#    #+#             */
/*   Updated: 2020/11/15 16:33:15 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"
#include "parse.h"
#include "check.h"

void	check_up(size_t i, size_t j, char **t)
{
	if (j == 0)
	{
		if ((g_m.grid[i + 1][j] != ' ' && g_m.grid[i + 1][j] != '1') ||
		(g_m.grid[i][j + 1] != ' ' && g_m.grid[i][j + 1] != '1'))
			error_msg(t);
	}
	else if (j == g_m.mapwidth - 1)
	{
		if ((g_m.grid[i + 1][j] != ' ' && g_m.grid[i + 1][j] != '1') ||
		(g_m.grid[i][j - 1] != ' ' && g_m.grid[i][j - 1] != '1'))
			error_msg(t);
	}
	else
	{
		if ((g_m.grid[i + 1][j] != ' ' && g_m.grid[i + 1][j] != '1') ||
		(g_m.grid[i][j + 1] != ' ' && g_m.grid[i][j + 1] != '1') ||
		(g_m.grid[i][j - 1] != ' ' && g_m.grid[i][j - 1] != '1'))
			error_msg(t);
	}
}

void	check_down(size_t i, size_t j, char **t)
{
	if (j == 0)
	{
		if ((g_m.grid[i - 1][j] != ' ' && g_m.grid[i - 1][j] != '1') ||
		(g_m.grid[i][j + 1] != ' ' && g_m.grid[i][j + 1] != '1'))
			error_msg(t);
	}
	else if (j == g_m.mapwidth - 1)
	{
		if ((g_m.grid[i - 1][j] != ' ' && g_m.grid[i - 1][j] != '1') ||
		(g_m.grid[i][j - 1] != ' ' && g_m.grid[i][j - 1] != '1'))
			error_msg(t);
	}
	else
	{
		if ((g_m.grid[i - 1][j] != ' ' && g_m.grid[i - 1][j] != '1') ||
		(g_m.grid[i][j + 1] != ' ' && g_m.grid[i][j + 1] != '1') ||
		(g_m.grid[i][j - 1] != ' ' && g_m.grid[i][j - 1] != '1'))
			error_msg(t);
	}
}

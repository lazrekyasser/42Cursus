/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 19:54:12 by ylazrek           #+#    #+#             */
/*   Updated: 2020/10/27 19:54:31 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"
#include "parse.h"
#include "check.h"

int		ft_isin(char c, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	error_msg(char **s)
{
	write(1, "error\n", 6);
	free_table(s);
	exit(1);
}

void	check_2error(t_para *f, char **tab)
{
	if (f->width == 0 || f->heigth == 0 || !(ft_strncmp(f->no, "q", 1)))
		error_msg(tab);
	if (!(ft_strncmp(f->so, "q", 1)) || !(ft_strncmp(f->we, "q", 1)) ||
			!(ft_strncmp(f->ea, "q", 1)) || !(ft_strncmp(f->s, "q", 1)))
		error_msg(tab);
	if (f->f.r == -1 || f->f.g == -1 || f->f.b == -1)
		error_msg(tab);
	if (f->c.r == -1 || f->c.g == -1 || f->c.b == -1)
		error_msg(tab);
}

void	check_firsterror(char **t)
{
	char	*s;

	s = ft_strdup("10");
	if ((ft_isin(t[0][0], s) == 1))
	{
		write(1, "error/n", 6);
		free(s);
		free_table(t);
		exit(1);
	}
	free(s);
}

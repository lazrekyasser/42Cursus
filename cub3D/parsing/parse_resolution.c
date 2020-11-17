/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 09:46:51 by ylazrek           #+#    #+#             */
/*   Updated: 2020/11/14 11:15:22 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"
#include "parse.h"
#include "check.h"

int		is_num(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

void	parse_resolution(char *s, t_para *f)
{
	char	**str;
	int		len;

	str = ft_split(s, ' ');
	len = count_table(str);
	if (f->width != 0 || f->heigth != 0)
		error_msg(str);
	if (len == 3)
	{
		(ft_strncmp(str[0], "R", ft_strlen(str[0])) != 0) ? error_msg(str) : 1;
		if (is_num(str[1]) != 0 || is_num(str[2]) != 0)
			error_msg(str);
		f->width = ft_atoi(str[1]);
		f->heigth = ft_atoi(str[2]);
		f->width = (f->width > 2560) ? 2560 : f->width;
		(f->width <= 0) ? error_msg(str) : f->width;
		(f->width < 600) ? f->width = 600 : f->width;
		f->heigth = (f->heigth > 1440) ? 1440 : f->heigth;
		(f->heigth <= 0) ? error_msg(str) : f->heigth;
		(f->heigth < 400) ? f->heigth = 400 : f->heigth;
		free_table(str);
	}
	else
		error_msg(str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 09:52:19 by ylazrek           #+#    #+#             */
/*   Updated: 2020/11/14 11:16:12 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"
#include "parse.h"
#include "check.h"

void	parse_nord(char *s, t_para *f)
{
	char	**str;
	int		len;

	if (ft_strncmp(f->no, "q", 1) != 0)
	{
		write(1, "error\n", 6);
		exit(1);
	}
	str = ft_split(s, ' ');
	len = count_table(str);
	if (len == 2)
	{
		(ft_strncmp(str[0], "NO", ft_strlen(str[0])) != 0) ? error_msg(str) : 1;
		f->no = ft_strdup(str[1]);
		free_table(str);
	}
	else
	{
		write(1, "error\n", 6);
		free_table(str);
		exit(1);
	}
}

void	parse_south(char *s, t_para *f)
{
	char	**str;
	int		len;

	if (ft_strncmp(f->so, "q", 1) != 0)
	{
		write(1, "error\n", 6);
		exit(1);
	}
	str = ft_split(s, ' ');
	len = count_table(str);
	if (len == 2)
	{
		(ft_strncmp(str[0], "SO", ft_strlen(str[0])) != 0) ? error_msg(str) : 1;
		f->so = ft_strdup(str[1]);
		free_table(str);
	}
	else
	{
		write(1, "error\n", 6);
		free_table(str);
		exit(1);
	}
}

void	parse_west(char *s, t_para *f)
{
	char	**str;
	int		len;

	if (ft_strncmp(f->we, "q", 1) != 0)
	{
		write(1, "error\n", 6);
		exit(1);
	}
	str = ft_split(s, ' ');
	len = count_table(str);
	if (len == 2)
	{
		(ft_strncmp(str[0], "WE", ft_strlen(str[0])) != 0) ? error_msg(str) : 1;
		f->we = ft_strdup(str[1]);
		free_table(str);
	}
	else
	{
		write(1, "error\n", 6);
		free_table(str);
		exit(1);
	}
}

void	parse_east(char *s, t_para *f)
{
	char	**str;
	int		len;

	if (ft_strncmp(f->ea, "q", 1) != 0)
	{
		write(1, "error\n", 6);
		exit(1);
	}
	str = ft_split(s, ' ');
	len = count_table(str);
	if (len == 2)
	{
		(ft_strncmp(str[0], "EA", ft_strlen(str[0])) != 0) ? error_msg(str) : 1;
		f->ea = ft_strdup(str[1]);
		free_table(str);
	}
	else
	{
		write(1, "error\n", 6);
		free_table(str);
		exit(1);
	}
}

void	parse_spirite(char *s, t_para *f)
{
	char	**str;
	int		len;

	if (ft_strncmp(f->s, "q", 1) != 0)
	{
		write(1, "error\n", 6);
		exit(1);
	}
	str = ft_split(s, ' ');
	len = count_table(str);
	if (len == 2)
	{
		(ft_strncmp(str[0], "S", ft_strlen(str[0])) != 0) ? error_msg(str) : 1;
		f->s = ft_strdup(str[1]);
		free_table(str);
	}
	else
	{
		write(1, "error\n", 6);
		free_table(str);
		exit(1);
	}
}

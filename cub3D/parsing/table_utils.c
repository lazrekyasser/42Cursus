/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 09:57:08 by ylazrek           #+#    #+#             */
/*   Updated: 2020/11/12 17:15:50 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"
#include "parse.h"
#include "check.h"

int		count_table(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

void	free_table(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**new_table(void)
{
	char	**tab;

	tab = (char**)malloc(sizeof(char*) * 1);
	tab[0] = NULL;
	return (tab);
}

char	**ft_join_table(char **tab, char *str)
{
	int		len;
	char	**new_t;
	int		i;

	i = 0;
	len = count_table(tab);
	new_t = (char**)malloc(sizeof(char*) * (len + 2));
	while (tab[i] != NULL)
	{
		new_t[i] = ft_strdup(tab[i]);
		i++;
	}
	new_t[i] = ft_strdup(str);
	new_t[++i] = NULL;
	free_table(tab);
	return (new_t);
}

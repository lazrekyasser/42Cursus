/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 10:16:48 by ylazrek           #+#    #+#             */
/*   Updated: 2020/02/02 10:16:57 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_get_table(char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	counter;
	char	**tab;

	i = 0;
	j = 0;
	counter = 0;
	while (i < ft_strlen(s))
	{
		j = i;
		while (j < ft_strlen(s) && s[j] != c)
			j++;
		if (j > i)
		{
			counter++;
			i = j;
		}
		i++;
	}
	tab = (char**)malloc(sizeof(char*) * (counter + 1));
	return (tab);
}

static char		*get_str(char *s, size_t len)
{
	char	*str;

	str = malloc(sizeof(char) * (len + 1));
	if (str)
	{
		ft_memmove(str, s, len);
		str[len] = '\0';
	}
	return (str);
}

static char		**free_tab(int counter, char **tab)
{
	int i;

	i = 0;
	while (i < counter + 1)
		free(tab[counter++]);
	free(tab);
	return (NULL);
}

static char		**ft_fill_table(char **tab, char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	counter;

	i = 0;
	j = 0;
	counter = 0;
	while (i < ft_strlen(s))
	{
		j = i;
		while (j < ft_strlen(s) && s[j] != c)
			j++;
		if (j > i)
		{
			tab[counter] = get_str((char*)&s[i], j - i);
			if (!tab[counter])
				return (free_tab(counter, tab));
			counter++;
			i = j;
		}
		i++;
	}
	tab[counter] = NULL;
	return (tab);
}

char			**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = ft_get_table((char*)s, c);
	if (!tab)
		return (NULL);
	return (ft_fill_table(tab, (char*)s, c));
}

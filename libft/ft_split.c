/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 18:57:53 by ylazrek           #+#    #+#             */
/*   Updated: 2019/10/31 16:10:42 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nbr_word(char const *str, char c)
{
	int		i;
	int		nb;

	nb = 0;
	i = -1;
	while (str[++i])
		if ((str[i] == c || i == 0) && str[i + 1] != c && str[i + 1])
			nb++;
	return (nb);
}

static int		len_word(char const *str, char c)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

static char		*ft_strncpy(char *dst, char const *src, int n)
{
	int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static char		**ft_free(char **str, int count)
{
	int i;

	i = 0;
	while (i < count + 1)
	{
		free(str[i++]);
	}
	free(str);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**splt;
	int		i;
	int		k;
	int		nbr_wrd;
	int		len_wrd;

	if (s == NULL)
		return (NULL);
	nbr_wrd = nbr_word(s, c);
	if (!(splt = (char **)malloc(sizeof(char *) * (nbr_wrd + 1))))
		return (NULL);
	i = 0;
	k = 0;
	while (k < nbr_wrd)
	{
		while (s[i] == c)
			i++;
		len_wrd = len_word(s + i, c);
		if (!(splt[k] = (char *)malloc(sizeof(char) * (len_wrd + 1))))
			return (ft_free(splt, k));
		ft_strncpy(splt[k++], s + i, len_wrd);
		i += len_wrd;
	}
	splt[k] = NULL;
	return (splt);
}

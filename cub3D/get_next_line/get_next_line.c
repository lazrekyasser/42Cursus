/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:31:50 by ylazrek           #+#    #+#             */
/*   Updated: 2020/10/27 19:01:23 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_return(char **rem, int n, char **line, int fd)
{
	char	*temp;
	int		i;

	i = 0;
	while (rem[fd][i] && rem[fd][i] != '\n')
		i++;
	*line = ft_strsub(rem[fd], 0, i);
	if (!rem[fd][i])
	{
		temp = rem[fd];
		rem[fd] = NULL;
		free(temp);
		return (0);
	}
	else
	{
		temp = rem[fd];
		rem[fd] = ft_strdup_gnl((rem[fd]) + i + 1);
		free(temp);
	}
	if (!rem[fd] || !*line)
		return (-1);
	if (n || (n == 0 && rem[fd] != NULL))
		return (1);
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*rem[4864];
	char		*temp;
	int			n;

	buf = NULL;
	if (!line || fd < 0 || fd >= 4864 || BUFFER_SIZE <= 0
			|| !(buf = malloc(BUFFER_SIZE + 1)) || read(fd, buf, 0) == -1)
		return (-1);
	if (!rem[fd])
		if (!(rem[fd] = ft_strdup_gnl("")))
			return (-1);
	while ((n = read(fd, buf, BUFFER_SIZE)))
	{
		temp = rem[fd];
		buf[n] = '\0';
		if (!(rem[fd] = ft_strjoin_gnl(rem[fd], buf)))
			return (-1);
		free(temp);
		if (ft_strchr_gnl(rem[fd], '\n') != 0)
			break ;
	}
	free(buf);
	return (ft_return(rem, n, line, fd));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:31:05 by ahhammou          #+#    #+#             */
/*   Updated: 2021/10/25 14:31:25 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_w12(char *src, int fd)
{
	char	*buffer;
	int		size;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
	{
		free (buffer);
		return (NULL);
	}
	size = 1;
	while (!ft_strchr(src, '\n') && size != 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[size] = '\0';
		src = ft_strjoin(src, buffer);
	}
	free (buffer);
	return (src);
}

char	*get_next_line(int fd)
{
	char		*d;
	static char	*s[256];

	d = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	s[fd] = ft_w12(s[fd], fd);
	if (s[fd] == NULL)
		return (NULL);
	d = ft_read_line(s[fd]);
	s[fd] = ft_future_line(s[fd]);
	if (d[0] == '\0')
	{
		free(s[fd]);
		free(d);
		return (NULL);
	}
	return (d);
}

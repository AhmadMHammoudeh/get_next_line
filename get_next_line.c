/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:31:05 by ahhammou          #+#    #+#             */
/*   Updated: 2021/11/21 10:53:47 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_w16(char *s, int fd)
{
	char	*temp;
	int		size;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	size = 1337;
	while (!ft_strchr(s) && size != 0)
	{
		size = read(fd, temp, BUFFER_SIZE);
		if (size == -1)
		{
			free (temp);
			return (NULL);
		}
		temp[size] = '\0';
		s = ft_strjoin(s, temp);
	}
	free (temp);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*s[256];
	char		*d;

	d = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	s[fd] = ft_w16(s[fd], fd);
	if (s[fd] == NULL)
		return (NULL);
	d = ft_speedo(s[fd]);
	s[fd] = ft_future_line(s[fd]);
	if (d[0] == '\0')
	{
		free(s[fd]);
		free(d);
		return (NULL);
	}
	return (d);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:31:05 by ahhammou          #+#    #+#             */
/*   Updated: 2021/10/19 18:43:43 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)));
	if (!ptr)
		return (NULL);
	while (*s1 != '\0')
		ptr[i++] = *s1++;
	while (*s2)
		ptr[i++] = *s2++;
	return (ptr);
}

char	*ft_strchr(const char *s, char c)
{
	char	*str;

	str = (char *)s;
	while (*str != '\0')
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (NULL);
}

char	*ft_engine(int fd, char *s)
{
	int			sz;
	char		*c;
	int			i;

	i = 0;
	c = (char *)malloc(1000 * sizeof(char));
	if (!c)
		return (NULL);
	sz = read(fd, c, BUFFER_SIZE);
	while (c[i] != '\n' && i < (sz - 1))
	{
		s[i] = c[i];
		i++;
	}
	// if (c[i] != '\n')
	// 	ft_engine(fd, s);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*s;

	s = (char *)malloc(1000 * sizeof(char));
	if (!s)
		return (NULL);
	return (ft_engine(fd, s));
}

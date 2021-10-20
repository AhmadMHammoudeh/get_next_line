/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:31:05 by ahhammou          #+#    #+#             */
/*   Updated: 2021/10/19 15:32:53 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	while (*s1 != '\0')
	{
		ptr[i++] = *s1++;
	}
	while (*s2)
	{
		ptr[i++] = *s2++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*get_next_line(int fd)
{
	int			sz;
	static char	*s;
	char		*c;
	int			i;
	int			j;

	i = 0;
	c = (char *)malloc(1000 * sizeof(char));
	if (!c)
		return (NULL);
	sz = read(fd, c, BUFFER_SIZE);
	j = ft_strlen(c);
	s = (char *)malloc((j + 1) * sizeof(char));
	if (!s)
		return (NULL);
	while (c[i] != '\n' && i < (j - 1))
	{
		s[i] = c[i];
		i++;
	}
	s[i++] = '\n';
	return (s);
}

// int	main(void)
// {
// 	int		fd;
	
// 	fd = open("/Users/ahhammou/Cursus/Get_next_line/hi.text", O_RDONLY);
// 	get_next_line(fd);
// }

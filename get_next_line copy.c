/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:31:05 by ahhammou          #+#    #+#             */
/*   Updated: 2021/10/19 17:27:32 by ahhammou         ###   ########.fr       */
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
	// ptr[i] = '\0';
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

char	*get_next_line(int fd)
{
	int			sz;
	int			i;
	// static char	*s;
	char		*c;

	if (fd > 0)
	{
		c = (char *)malloc(1000 * sizeof(char));
		if (!c)
			return (NULL);
		sz = read(fd, c, 5);
		if (ft_strchr(c, '\n') == NULL)
		{
			s = ft_strjoin(s, c);
			get_next_line(fd, s);
		}
		else if (ft_strchr(c, '\n') != NULL)
		{
			c = ft_strchr(s, '\n');
			s = ft_strjoin(s, c);
			return (0);
		}
		free(c);
	}
	// printf("%s", s);
	return (s);
}

// int	main(void)
// {
// 	int		fd;
// 	static char	*s;
	
// 	s = (char *)malloc(10000 * sizeof(char));
// 	fd = open("/Users/ahhammou/Cursus/Get_next_line/hi.text", O_RDONLY);
// 	get_next_line(fd, s);
// 	printf("%s", s);
// }

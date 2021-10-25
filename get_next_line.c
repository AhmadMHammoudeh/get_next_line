/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:31:05 by ahhammou          #+#    #+#             */
/*   Updated: 2021/10/25 14:05:49 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (s1 == NULL)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[j] != '\0')
		str[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *src, int c)
{
	size_t	i;

	i = 0;
	if (src == NULL)
		return (0);
	if (c == '\0')
		return ((char *)&src[ft_strlen(src)]);
	while (src[i] != '\0')
	{
		if (src[i] == (char)c)
			return ((char *)&src[i]);
		i++;
	}
	return (0);
}



///////////////////////////////////
//1st protect
//2nd read buffersize
// if no \n join buff with s
// if \n join buff till \n with s && save after \n
//return s and leftovers


// char *ft_check_d(char *d)
// {
// 	int i;

// 	i = 0;
// 	while (d[i] != '\n' && d[i] != '\0')
// 		i++;
// 	if (d[i] == '\n')
// 		return (d);
// 	ft_free(&d);
// 	return (0);

// }

// char *ft_engine( char *s, int fd)
// {
// 	char	*c;
// 	char	*a;
// 	int		sz;

// 	c = malloc((BUFFER_SIZE + 1) * sizeof(char));
// 	if (!c)
// 		return (NULL);
// 	sz = read(fd, c, BUFFER_SIZE);
// 	while (sz != 0)
// 	{
// 		if (sz == -1)
// 		{
// 			free(c);
// 			return (NULL);
// 		}
// 		c[sz] = '\0';
// 		a = ft_strchr(c, '\n');
// 		if (a)
// 		{
// 			c = ft_beforenew(c);
// 			s = ft_strjoin(s, c);
// 			break ;
// 		}
// 		s = ft_strjoin(s, c);
// 		sz = read(fd, c, BUFFER_SIZE);
// 	}
// 	free(&c);
// 	return (s);
// }

char	*ft_engine(char *src, int fd)
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
	s[fd] = ft_engine(s[fd], fd);
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

// char	*get_next_line(int fd)
// {
// 	static char	*d;
// 	char		*s;

// 	if (fd < 0 || BUFFER_SIZE < 1)
// 		return (NULL);
// 	d = malloc(sizeof(char));
// 	if (!d)
// 		return (NULL);
// 	s = NULL;
// 	s = ft_engine(fd, s, d);
// 	d = ft_check_d(d);
// 	return (s);
// }

// #include "get_next_line_utils.c"

// int	main(void)
// {
// 	int		fd;
// 	char *s;
// 	// char *s1;
// 	fd = open("/Users/ahhammou/Cursus/Get_next_line/gnlTester/files/nl", O_RDONLY);
// 	// fd = (int)'%';
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	// s = get_next_line(fd);
// 	// printf("%s", s);
// 	// s = get_next_line(fd);
// 	// printf("%s", s);
// 	// s = get_next_line(fd);
// 	// printf("%s", s);
// 	// s1 = ft_strjoin("NOPE", "MAYBE");
// 	// printf("%s", s1);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:31:05 by ahhammou          #+#    #+#             */
/*   Updated: 2021/10/20 14:02:17 by ahhammou         ###   ########.fr       */
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

	if (!s2)
		return (s1);
	i = 0;
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!ptr)
		return (NULL);
	while (*s1 != '\0')
		ptr[i++] = *s1++;
	while (*s2)
		ptr[i++] = *s2++;
	ptr[i] = '\0';
	// free(s1);
	// s1 = NULL;
	return (ptr);
}

char	*ft_beforenew(char *s, int c)
{
	int		i;
	char	*a;

	a = s;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			a[i++] = '\n';
			a[i] = '\0';
			return (a);
		}
		a[i] = s[i];
		i++;
	}
	if (c == '\0')
		return (a);
	return (NULL);
}

char	*ft_strchr(char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return (++s);
		s++;
	}
	if (c == '\0')
		return (s);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		i;

	ptr = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	i = 0;
	if (!ptr)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*get_next_line(int fd)
{
	char		*s;
	static char	*d;
	char		*c;
	int			j;
	int			i;
	int			sz;

	if (fd <= 0 || fd >= 1000 || BUFFER_SIZE <= 0)
		return (NULL);
	s = (char *)malloc(sizeof(char));
	if (!s)
		return (NULL);
	j = 0;
	i = 0;
	if (d)
		s = ft_strdup(d);
	while (j == 0)
	{
		c = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
		if (!c)
			return (NULL);
		sz = read(fd, c, BUFFER_SIZE);
		if (sz == 0)
			break ;
		c[BUFFER_SIZE] = '\0';
		if (ft_strchr(c, '\n'))
		{
			d = ft_strdup(ft_strchr(c, '\n'));
			//  printf("%s", d);
			c = ft_beforenew(c, '\n');
			s = ft_strjoin(s, c);
			j = 1;
			i++;
		}
		else
		{
			s = ft_strjoin(s, c);
			i++;
		}
	}
	free(c);
	return (s);
}

// int	main(void)
// {
// 	int		fd;
// 	char *s;
// 	// char *s1;
// 	fd = open("/Users/ahhammou/Cursus/Get_next_line/hi.text", O_RDONLY);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	// s1 = ft_strjoin("NOPE", "MAYBE");
// 	// printf("%s", s1);
// }

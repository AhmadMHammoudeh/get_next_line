/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:31:05 by ahhammou          #+#    #+#             */
/*   Updated: 2021/10/19 14:16:30 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>

// int	ft_strlen(const char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		i++;
// 	}
// 	return (i);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*ptr;
// 	int		i;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	i = 0;
// 	ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
// 	if (!ptr)
// 		return (NULL);
// 	while (*s1 != '\0')
// 	{
// 		ptr[i++] = *s1++;
// 	}
// 	while (*s2)
// 	{
// 		ptr[i++] = *s2++;
// 	}
// 	ptr[i] = '\0';
// 	return (ptr);
// }

// char	*get_next_line(int fd)
// {
// 	int		sz;
// 	static char	*c;
// 	char	*s;
// 	int		i;

// 	i = 0;
// 	s = (char *)malloc(10000 * sizeof(char));
// 	c = (char *)malloc(1000 * sizeof(char));
// 	sz = read(fd, c, 100);
// //	printf("%s", c);
// 	while (c[i] != '\n')
// 	{
// 		s[i] = c[i];
// 		// printf("%c", s[i]);
// 		i++;
// 	}
// 	s[i] = '\n';
// 	// printf("%c", s[i]);
// 	// printf("called read(%d, c, 10). returned that"
// 	// 	   " %d bytes were read.\n",
// 	// 	   fd, sz);
// 	// printf("Those bytes are as follows: %s\n", s);
// 	// if ()
// 	return (s);
// }

// // int	main(void)
// // {
// // 	int		fd;
	
// // 	fd = open("/Users/ahhammou/Cursus/Get_next_line/hi.text", O_RDONLY);
// // 	get_next_line(fd);
// // }

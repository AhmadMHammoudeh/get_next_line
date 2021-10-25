/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:31:05 by ahhammou          #+#    #+#             */
/*   Updated: 2021/10/25 14:02:14 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	int	i;
// 	int	j;
// 	char	*str;

// 	i = 0;
// 	j = 0;
// 	if (s1 == NULL)
// 	{
// 		s1 = (char *)malloc(sizeof(char) * 1);
// 		s1[0] = '\0';
// 	}
// 	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
// 	if (str == NULL)
// 		return (NULL);
// 	while (s1[j] != '\0')
// 		str[i++] = s1[j++];
// 	j = 0;
// 	while (s2[j] != '\0')
// 		str[i++] = s2[j++];
// 	str[i] = '\0';
// 	ft_free(&s1);
// 	// free(s1);
// 	return (str);
// }

// int	ft_strlen(char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 		i++;
// 	return (i);
// }

// char	*ft_strchr(char *src)
// {
// 	int	i;

// 	i = 0;
// 	if (src == NULL)
// 		return (0);
// 	while (src[i] != '\0')
// 	{
// 		if (src[i] == '\n')
// 			return ((char *)&src[i]);
// 		i++;
// 	}
// 	return (0);
// }

char	*ft_beforenew(char *s)
{
	int		i;
	char	*a;

	if (!s)
		return (NULL);
	a = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (! a)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		a[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		a[i] = s[i];
	// ft_free(&s);
	free(s);
	return (a);
}

char	*ft_strdup(char *s1)
{
	char	*ptr;
	int		i;

	ptr = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	i = 0;
	if (!ptr)
		return (NULL);
	while (s1[i] != '\0')
	{
		if (s1[i] == '\n')
			
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	// ft_free(&s1);
	free(s1);
	return (ptr);
}

char	*ft_read_line(char *src)
{
	int	i;
	char	*str;

	i = 0;
	if (src == NULL)
		return (NULL);
	while (src[i] != '\n' && src[i] != '\0')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\n' && src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*ft_future_line(char *src)
{
	int	i;
	int	j;
	char	*str;

	i = 0;
	while (src[i] != '\n' && src[i] != '\0')
		i++;
	if (src[i] == '\0')
	{
		free (src);
		return (0);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(src) - i + 1));
	if (str == NULL)
		return (NULL);
	i++;
	j = 0;
	while (src[i] != '\0')
		str[j++] = src[i++];
	str[j] = '\0';
	free (src);
	return (str);
}

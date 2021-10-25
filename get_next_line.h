/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:48:23 by ahhammou          #+#    #+#             */
/*   Updated: 2021/10/25 14:00:14 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

// # ifndef BUFFER_SIZE
// #  define BUFFER_SIZE 1

int		ft_strlen(char *s);
char	*ft_check_d(char *d);
char	*ft_strchr(char *src, int c);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_beforenew(char *s);
char	*get_next_line(int fd);
char	*ft_engine(char *s, int fd);
void	ft_free(char **str);
char	*ft_strnew(char *s);
char	*ft_future_line(char *src);
char	*ft_read_line(char *src);

// # endif
#endif

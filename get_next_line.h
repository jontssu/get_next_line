/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jole <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:07:45 by jole              #+#    #+#             */
/*   Updated: 2022/11/23 15:44:18 by jole             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char	*surplus;
	char	*beginning;
	int		i;
	int		len;
	int		total_len;
}				t_list;

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(t_list *list, char const *s2, int s2_len);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		strlen_newline(char *str);
char	*ft_strdup(const char *s1);
char	*get_line(int fd, t_list *list);
char	*move_surplus(t_list *list);
void	skip_line(t_list *list);

#endif

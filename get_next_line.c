/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jole <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:07:00 by jole              #+#    #+#             */
/*   Updated: 2022/11/16 20:46:19 by jole             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> /// LOL
char	*get_next_line(int fd)
{
	char		*str;
	static char	*surplus;

	if (fd < 0 || fd > 4095 || BUFFER_SIZE <= 0)
		return (0);
	surplus = get_line(fd, surplus);
	if (!surplus || !*surplus)
		return (0);
	str = malloc((strlen_newline(surplus) + 2) * sizeof(char));
	ft_strlcpy(str, surplus, (strlen_newline(surplus) + 2));
	surplus = trim_surplus(surplus);
	return (str);
}

char	*get_line(int fd, char *surplus)
{
	int			read_val;
	char		*buf;

	read_val = 1;
	while (!ft_strchr(surplus, '\n') && read_val)
	{
		buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buf)
			return (0);
		read_val = read(fd, buf, BUFFER_SIZE);
		if (read_val == -1)
		{
			free(buf);
			return (0);
		}
		buf[read_val] = 0;
		surplus = ft_strjoin(surplus, buf);
	}
	return (surplus);
}

int	strlen_newline(char	*str)
{
	int	len;

	len = 0;
	while (*str != '\n' && *str != 0)
	{
		str++;
		len++;
	}
	return (len);
}

char	*trim_surplus(char *str)
{
	char	*trimmed_str;
	int		len;
	int		i;

	i = 0;
	len = strlen_newline(str) + 1;
	trimmed_str = malloc((ft_strlen(str) - len + 1) * sizeof(char));
	while (str[len])
		trimmed_str[i++] = str[len++];
	trimmed_str[i] = 0;
	return (trimmed_str);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		i;

	i = 0;
	p = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!p)
		return (0);
	while (*s1 != 0)
	{
		*p = *s1;
		p++;
		s1++;
		i++;
	}
	*p = '\0';
	return (p - i);
}
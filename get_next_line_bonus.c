/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:55:11 by dmdemirk          #+#    #+#             */
/*   Updated: 2023/11/30 13:55:25 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;

	if (!s)
		return ((void *)0);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	substring = malloc((len + 1) * sizeof(char));
	if (!substring)
		return ((void *)0);
	i = 0;
	while (i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}

static char	*fn_fillbuffer(int fd, char *remain, char *buffer)
{
	ssize_t	bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (remain);
			return ((void *)0);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!remain)
			remain = ft_strdup("");
		temp = remain;
		remain = ft_strjoin(temp, buffer);
		free(temp);
		temp = ((void *)0);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (remain);
}

static char	*fn_lineout(char *line)
{
	char	*output;
	ssize_t	c;

	c = 0;
	while (line[c] != '\n' && line[c] != '\0')
		c++;
	if (line[c] == 0 || line[1] == 0)
		return ((void *)0);
	output = ft_substr(line, c + 1, ft_strlen(line) - c);
	if (*output == 0)
	{
		free(output);
		output = ((void *)0);
	}
	line[c + 1] = '\0';
	return (output);
}

char	*get_next_line(int fd)
{
	static char	*remain[MAX_FD];
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(remain[fd]);
		free(buffer);
		remain[fd] = ((void *)0);
		buffer = ((void *)0);
		return ((void *)0);
	}
	if (!buffer)
		return ((void *)0);
	line = fn_fillbuffer(fd, remain[fd], buffer);
	free(buffer);
	buffer = ((void *)0);
	if (!line)
		return ((void *)0);
	remain[fd] = fn_lineout(line);
	return (line);
}

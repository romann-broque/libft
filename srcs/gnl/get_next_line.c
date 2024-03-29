/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:12:42 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/28 23:44:11 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_line_status	get_line_from_buff(char **line, char *buffer)
{
	size_t	index;

	index = abs_index(buffer, '\n');
	if (*buffer != '\0')
	{
		*line = ft_strnjoin_free(*line, buffer, index + 1);
		if (buffer[index] == '\n')
		{
			ft_strlcpy(buffer, buffer + index + 1, BUFFER_SIZE + 1);
			return (VALID_LINE);
		}
	}
	return (INVALID_LINE);
}

static t_line_status	fill_line_from_file(char **line,
											char *rest, const int fd)
{
	ssize_t	read_bytes;
	char	buffer[BUFFER_SIZE + 1];

	ft_bzero(buffer, BUFFER_SIZE + 1);
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	while (read_bytes > 0 && get_line_from_buff(line, buffer) == INVALID_LINE)
	{
		ft_bzero(buffer, BUFFER_SIZE + 1);
		read_bytes = read(fd, buffer, BUFFER_SIZE);
	}
	if (read_bytes == -1)
		return (INVALID_LINE);
	ft_strlcpy(rest, buffer, read_bytes + 1);
	return (VALID_LINE);
}

static void	get_line(int fd, char **line)
{
	static char		rest[OPEN_MAX_FD][BUFFER_SIZE + 1] = {{0}};

	if (get_line_from_buff(line, rest[fd]) == INVALID_LINE)
		fill_line_from_file(line, rest[fd], fd);
}

char	*get_next_line(int fd)
{
	char	*line;

	line = NULL;
	if (fd > -1 && fd < OPEN_MAX_FD)
		get_line(fd, &line);
	return (line);
}

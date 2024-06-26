/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:03:29 by jberdugo          #+#    #+#             */
/*   Updated: 2023/11/02 16:57:44 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_buffer(int fd, char **static_buffer);
static char	*get_line(char **static_buffer);
static char	*clean_buffer(char **static_buffer);
static char	*free_malloc(char **buffer_to_clean);

char	*get_next_line(int fd)
{
	static char	*static_buffer;
	char		*next_line;

	if (fd < 0)
		return (NULL);
	if (!static_buffer || !ft_strchr(static_buffer, '\n'))
		static_buffer = get_buffer(fd, &static_buffer);
	if (!static_buffer)
		return (NULL);
	next_line = get_line(&static_buffer);
	if (!next_line)
		return (NULL);
	static_buffer = clean_buffer(&static_buffer);
	if (!static_buffer && !next_line)
		return (NULL);
	return (next_line);
}

static char	*get_buffer(int fd, char **static_buffer)
{
	char	*read_buffer;
	char	*free_buffer;
	ssize_t	fd_read;

	read_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_buffer)
		return (free_malloc(static_buffer));
	fd_read = 1;
	read_buffer[0] = '\0';
	while (fd_read > 0 && !ft_strchr(read_buffer, '\n'))
	{
		fd_read = read(fd, read_buffer, BUFFER_SIZE);
		if (fd_read > 0)
		{
			read_buffer[fd_read] = '\0';
			free_buffer = *static_buffer;
			*static_buffer = ft_strjoin(free_buffer, read_buffer);
			free(free_buffer);
		}
	}
	free(read_buffer);
	if (fd_read < 0)
		return (free_malloc(static_buffer));
	return (*static_buffer);
}

static char	*get_line(char **static_buffer)
{
	char	*new_line;
	char	*end_line;
	size_t	len;

	end_line = ft_strchr(*static_buffer, '\n');
	if (end_line)
		len = end_line - *static_buffer + 1;
	else
		len = ft_strlen(*static_buffer);
	new_line = ft_substr(*static_buffer, 0, len);
	if (!new_line)
		return (free_malloc(static_buffer));
	return (new_line);
}

static char	*clean_buffer(char **static_buffer)
{
	char	*new_buffer;
	char	*end_line;
	size_t	start;
	size_t	len;

	end_line = ft_strchr(*static_buffer, '\n');
	if (end_line)
		start = end_line - *static_buffer + 1;
	else
		return (free_malloc(static_buffer));
	len = ft_strlen(*static_buffer + start);
	new_buffer = ft_substr(*static_buffer, start, len);
	if (!new_buffer)
		return (free_malloc(static_buffer));
	free(*static_buffer);
	return (new_buffer);
}

static char	*free_malloc(char **buffer_to_clean)
{
	free(*buffer_to_clean);
	*buffer_to_clean = NULL;
	return (NULL);
}

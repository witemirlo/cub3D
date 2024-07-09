/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:07:22 by jberdugo          #+#    #+#             */
/*   Updated: 2024/07/09 15:53:11 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "colors.h"
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

static t_list	*create_list(int fd);

/* Read all source file and returns a t_list * with all its content */
t_list	*read_file(char *name)
{
	t_list	*list;
	int		fd;

	fd = open(name, O_RDONLY | O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		ft_putstr_fd(RED"Error: "NC"'", 2);
		ft_putstr_fd(name, 2);
		ft_putendl_fd("': is a directory", 2);
	}
	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (perror("Error"), NULL);
	list = create_list(fd);
	close (fd);
	return (list);
}

static t_list	*create_list(int fd)
{
	t_list	*list;
	t_list	*node;
	char	*tmp;

	list = NULL;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		if (tmp[ft_strlen(tmp) - 1] == '\n')
			tmp[ft_strlen(tmp) - 1] = '\0';
		node = ft_lstnew(tmp);
		if (!node)
		{
			free(tmp);
			ft_lstclear(&list, free);
			perror("Error");
			return (NULL);
		}
		ft_lstadd_back(&list, node);
	}
	return (list);
}

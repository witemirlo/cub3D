/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:07:22 by jberdugo          #+#    #+#             */
/*   Updated: 2024/06/28 16:25:11 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

static t_list	*create_list(int fd);

/* Read all source file and returns a t_list * with all its content */
t_list	*read_file(char const *name)
{
	t_list	*list;
	int		fd;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (NULL);
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
			break ;
		}
		ft_lstadd_back(&list, node);
	}
	if (errno == ENOMEM)
	{
		ft_lstclear(&list, free);
		list = NULL;
	}
	return (list);
}

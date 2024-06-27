/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:07:22 by jberdugo          #+#    #+#             */
/*   Updated: 2024/06/27 12:36:21 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

/**
 * Read all source file and returns a t_list * with all its content
 */
t_list	*read_map(char const *name)
{
	t_list	*list;
	t_list	*node;
	int		fd;
	char	*tmp;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		node = ft_lstnew(tmp);
		if (!node)
			break ;
		ft_lstadd_back(&list, node);
	}
	if (errno == ENOMEM)
	{
		ft_lstclear(&list, free);
		list = NULL;
	}
	close (fd);
	return (list);
}

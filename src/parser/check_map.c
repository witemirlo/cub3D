/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:24:46 by jberdugo          #+#    #+#             */
/*   Updated: 2024/07/03 13:32:57 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

static t_check_flags	check_map_chars(t_list *map);
static t_check_flags	check_map_closed(t_list *map);

t_check_flags	check_map(t_list *map)
{
	t_check_flags	mask;

	mask = 0;
	mask |= check_map_chars(map);
	mask |= check_map_closed(map);
	// TODO: una sola posicion de player
	return (mask);
}

static t_check_flags	check_map_chars(t_list *map)
{
	const char	allowed_chars[] = " 01NSEW";
	char 		*tmp;

	while (map)
	{
		tmp = (char *)(map->content);
		while (*tmp)
		{
			if (ft_strchr(allowed_chars, *tmp) == NULL)
				return (FAILURE | FORBIDDEN_MAP);
			tmp++;
		}
		map = map->next;
	}
	return (0);
}

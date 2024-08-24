/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:24:46 by jberdugo          #+#    #+#             */
/*   Updated: 2024/08/24 15:08:11 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include <stdlib.h>

static t_error_flags	check_map_chars(char **map);
static t_error_flags	check_map_unique_player(char **map);
static t_error_flags	check_map_not_break(char **map);

t_error_flags	check_map(t_list *map)
{
	t_error_flags	mask;
	char			**tmp_map;

	tmp_map = generate_map(map);
	if (!tmp_map)
		return (FAILURE);
	mask = 0;
	mask |= check_map_chars(tmp_map);
	mask |= check_map_closed(tmp_map);
	mask |= check_map_unique_player(tmp_map);
	mask |= check_map_not_break(tmp_map);
	clear_2d_array(&tmp_map);
	return (mask);
}

static t_error_flags	check_map_chars(char **map)
{
	t_error_flags	mask;
	size_t			i;	
	size_t			j;	

	mask = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr(MAP_VALID_CHARS, map[i][j]) == NULL)
				return (FAILURE | FORBIDDEN_MAP);
			if (map[i][j] == 'A')
				mask |= F_SPRITE_MAP;
			else if (map[i][j] == 'C' || map[i][j] == 'O')
				mask |= F_DOOR_MAP;
			j++;
		}
		i++;
	}
	return (mask);
}

static t_error_flags	check_map_unique_player(char **map)
{
	size_t	i;
	size_t	j;
	int		check;

	check = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NSWE", map[i][j]))
			{
				if (check == 1)
					return (FAILURE | REPEATED_PLAYER);
				check = 1;
			}
			j++;
		}
		i++;
	}
	if (check == 0)
		return (FAILURE | NO_PLAYER);
	return (0);
}

static t_error_flags	check_map_not_break(char **map)
{
	size_t			i;
	t_error_flags	mask;

	i = 0;
	mask = 0;
	while (map[i])
	{
		if (map[i][0] == '\0')
		{
			while (map[i] && map[i][0] == '\0')
				i++;
			if (map[i] && map[i][0] != '\0')
				mask |= (FAILURE | MAP_BREAK);
			else
				mask |= (FAILURE | BAD_SITE_MAP);
		}
		else
			i++;
	}
	return (mask);
}

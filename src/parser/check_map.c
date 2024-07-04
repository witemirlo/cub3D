/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:24:46 by jberdugo          #+#    #+#             */
/*   Updated: 2024/07/04 15:39:29 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

static char 			**generate_map(t_list *map);
static t_check_flags	check_map_chars(char **map);
static t_check_flags	check_map_closed(char **map);
static t_check_flags	check_map_unique_player(char **map);

t_check_flags	check_map(t_list *map)
{
	t_check_flags	mask;
	char			**tmp_map;

	tmp_map = generate_map(map);
	if (!tmp_map)
		return (FAILURE);
	mask = 0;
	mask |= check_map_chars(tmp_map);
	mask |= check_map_closed(tmp_map);
	mask |= check_map_unique_payer(tmp_map);
	clear_2d_array(tmp_map);
	return (mask);
}

static char **generate_map(t_list *list_map)
{
	char	**array_map;
	size_t	i;

	array_map = ft_calloc(ft_lstsize(list_map), sizeof(char **));
	i = 0;
	while (list_map)
	{
		array_map[i] = ft_strdup((char *)(list_map->content));
		if (!array_map)
		{
			clear_2d_array(array_map);
			return (NULL);
		}
		i++;
		list_map = list_map->next;
	}
	return (array_map);
}


static t_check_flags	check_map_chars(char **map)
{
	const char	allowed_chars[] = " 01NSEW";
	size_t		i;	
	size_t		j;	

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr(allowed_chars, map[i][j]) == NULL)
				return (FAILURE | FORBIDDEN_MAP);
			j++;
		}
		i++;
	}
	return (0);
}

static t_check_flags	check_map_closed(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
			{
				if (j && map[i][j - 1] == ' ')
					return (FAILURE | MAP_NOT_CLOSED);
				else if (map[i][j + 1] && map[i][j + 1] == ' ')
					return (FAILURE | MAP_NOT_CLOSED);
				else if (i && ft_strlen(map[i - 1]) >= j && map[i - 1][j] == ' ')
					return (FAILURE | MAP_NOT_CLOSED);
				else if (map[i + 1][j] && ft_strlen(map[i + 1]) >= j && map[i][j] == ' ')
					return (FAILURE | MAP_NOT_CLOSED);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static t_check_flags	check_map_unique_player(char **map)
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

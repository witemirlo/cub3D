/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_closed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:46:28 by jberdugo          #+#    #+#             */
/*   Updated: 2024/08/06 19:28:51 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

static int	check_map_surrounding(char **map, size_t i, size_t j);

t_error_flags	check_map_closed(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (!check_map_surrounding(map, i, j))
				return (FAILURE | MAP_NOT_CLOSED);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_map_surrounding(char **map, size_t i, size_t j)
{
	if (ft_strchr("0NSEW", map[i][j]))
	{
		if (j == 0 || j == ft_strlen(map[i]) - 1
			|| i == 0 || ft_strlen(map[i - 1]) < j)
			return (0);
		else if (j
			&& map[i][j - 1] == ' ')
			return (0);
		else if (map[i][j + 1]
			&& map[i][j + 1] == ' ')
			return (0);
		else if (i
			&& ft_strlen(map[i - 1]) >= j
			&& map[i - 1][j] == ' ')
			return (0);
		else if (map[i + 1]
			&& ft_strlen(map[i + 1]) >= j
			&& map[i + 1][j] == ' ')
			return (0);
		else if (!map[i + 1] || ft_strlen(map[i + 1]) < j)
			return (0);
	}
	return (1);
}

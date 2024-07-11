/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:44:24 by jberdugo          #+#    #+#             */
/*   Updated: 2024/07/11 15:00:37 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

static t_vector	get_position(char **map);
static t_vector	get_direction(t_vector position, char **map);

t_player	get_player(char **map)
{
	t_player	player;

	player = (t_player){0};
	if (!map)
		return (player);
	player.position = get_position(map);
	player.direction = get_direction(player.position, map);
	map[(size_t){player.position.x}][(size_t){player.position.y}] = '0';
	return (player);
}

static t_vector	get_position(char **map)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (map[y])
	{
		y = 0;
		while (map[y][x])
		{
			if (ft_strchr("NSWE", map[y][x]))
				break ;
			x++;
		}
		y++;
	}
	if (!map[y][x])
		return ((t_vector){-1, -1});
	return ((t_vector){x, y});
}

static t_vector	get_direction(t_vector position, char **map)
{
	size_t const	x = position.x;
	size_t const	y = position.y;

	if (map[y][x] == 'N')
		return ((t_vector){x, (y - 1)});
	else if (map[y][x] == 'S')
		return ((t_vector){x, (y + 1)});
	else if (map[y][x] == 'W')
		return ((t_vector){(x - 1), y});
	else if (map[y][x] == 'E')
		return ((t_vector){(x + 1), y});
	else
		return ((t_vector){-1, -1});
}

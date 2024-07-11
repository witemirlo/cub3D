/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:44:24 by jberdugo          #+#    #+#             */
/*   Updated: 2024/07/11 14:27:54 by jberdugo         ###   ########.fr       */
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
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (ft_strchr("NSWE", map[x][y]))
				break ;
			y++;
		}
		x++;
	}
	if (!map[x][y])
		return ((t_vector){-1, -1});
	return ((t_vector){x, y});
}

static t_vector	get_direction(t_vector position, char **map)
{
	size_t const	x = position.x;
	size_t const	y = position.y;

	if (map[x][y] == 'N')
		return ((t_vector){x, (y - 1)});
	else if (map[x][y] == 'S')
		return ((t_vector){x, (y + 1)});
	else if (map[x][y] == 'W')
		return ((t_vector){(x - 1), y});
	else if (map[x][y] == 'E')
		return ((t_vector){(x + 1), y});
	else
		return ((t_vector){-1, -1});
}

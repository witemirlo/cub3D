/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:44:24 by jberdugo          #+#    #+#             */
/*   Updated: 2024/07/16 13:29:15 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

static t_vector	get_position(char **map);
static t_vector	get_dir(char content);

t_player	get_player(char **map)
{
	t_player	player;

	player = (t_player){0};
	if (!map)
		return (player);
	player.position = get_position(map);
	if (player.position.x == -1 && player.position.y == -1)
		return (player);
	player.direction = \
		get_dir(map[(size_t)(player.position.y)][(size_t)(player.position.x)]);
	if (player.direction.x == -1 && player.direction.y == -1)
		return (player);
	player.camera = (t_vector){1, 0};
	map[(size_t)(player.position.x)][(size_t)(player.position.y)] = '0';
	return (player);
}

static t_vector	get_position(char **map)
{
	size_t	x;
	size_t	y;
	int		check;

	check = 0;
	y = 0;
	while (map[y] && !check)
	{
		x = 0;
		while (map[y][x] && !check)
		{
			if (ft_strchr("NSWE", map[y][x]))
			{
				check = 1;
				break ;
			}
			if (!check)
				x++;
		}
		if (!check)
			y++;
	}
	if (!map[y])
		return ((t_vector){-1, -1});
	return ((t_vector){x, y});
}

static t_vector	get_dir(char content)
{
	if (content == 'N')
		return ((t_vector){0, -1});
	else if (content == 'S')
		return ((t_vector){0, 1});
	else if (content == 'W')
		return ((t_vector){-1, 0});
	else if (content == 'E')
		return ((t_vector){1, 0});
	else
		return ((t_vector){-1, -1});
}

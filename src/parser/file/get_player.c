/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psacrist <psacrist@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:44:24 by jberdugo          #+#    #+#             */
/*   Updated: 2024/07/23 11:41:10 by psacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

static t_vector	get_position(char **map);
static t_vector	get_dir(char content);
static t_vector	get_cam(char content);

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
	player.camera = \
		get_cam(map[(size_t)(player.position.y)][(size_t)(player.position.x)]);
	map[(size_t)(player.position.y)][(size_t)(player.position.x)] = '0';
	return (player);
}

static t_vector	get_cam(char content)
{
	if (content == 'N')
		return ((t_vector){(double)2 / 3, 0});
	else if (content == 'S')
		return ((t_vector){(double)-2 / 3, 0});
	else if (content == 'W')
		return ((t_vector){0, (double)-2 / 3});
	else if (content == 'E')
		return ((t_vector){0, (double)2 / 3});
	else
		return ((t_vector){-1, -1});
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
	return ((t_vector){x + 0.5, y + 0.5});
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

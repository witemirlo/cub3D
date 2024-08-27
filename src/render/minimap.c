/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psacrist <psacrist@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:41:20 by jberdugo          #+#    #+#             */
/*   Updated: 2024/08/27 18:24:26 by psacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"
#include "libft.h"

#include <math.h>

static int		mini_color(t_vector map_coord, char **map);
static void		draw_player(int cam_w, mlx_image_t *img);
static t_vector	rot_map(t_vector map, t_vector dir, t_vector pos);
static int		door_tile(t_vector map_coord, int tile);

void	minimap(t_data *data)
{
	t_vector	map;
	int			i;
	int			j;
	int			cam_w;

	cam_w = HEIGHT / MINI_FRAC;
	i = 0;
	while (i < cam_w)
	{
		j = 0;
		while (j < cam_w)
		{
			map.x = data->player.position.x + \
				(i + 1 - (double)cam_w / 2) / MINI_TILE;
			map.y = data->player.position.y + \
				(j + 1 - (double)cam_w / 2) / MINI_TILE;
			map = rot_map(map, data->player.direction, data->player.position);
			if (pow(i - cam_w / 2, 2) + pow(j - cam_w / 2, 2) <= \
				pow(cam_w / 2, 2))
				mlx_put_pixel(data->minimap, i, j, mini_color(map, data->map));
			j++;
		}
		i++;
	}
	draw_player(cam_w, data->minimap);
}

static t_vector	rot_map(t_vector map, t_vector dir, t_vector pos)
{
	t_vector	centered;
	t_vector	transformed;

	centered = (t_vector){map.x - pos.x, map.y - pos.y};
	transformed.x = (-dir.x * centered.y - dir.y * centered.x) + pos.x;
	transformed.y = (dir.x * centered.x - dir.y * centered.y) + pos.y;
	return (transformed);
}

static int	mini_color(t_vector map_coord, char **map)
{
	char	tile;

	if (map_coord.x <= 0 || map_coord.y <= 0)
		return (MINI_VOID_COL);
	if (map_coord.y > size_2d_array((char const **)map))
		return (MINI_VOID_COL);
	if (map_coord.x > ft_strlen(map[(int)map_coord.y]))
		return (MINI_VOID_COL);
	tile = map[(int)map_coord.y][(int)map_coord.x];
	if (tile == '0')
		return (MINI_FLOO_COL);
	if (tile == '1')
		return (MINI_WALL_COL);
	if (tile == 'C' || tile == 'O')
		return (door_tile(map_coord, tile));
	return (MINI_VOID_COL);
}

static int	door_tile(t_vector map_coord, int tile)
{
	int	tile_x;
	int	tile_y;

	tile_x = (map_coord.x - (int)map_coord.x) * 10;
	tile_y = (map_coord.y - (int)map_coord.y) * 10;
	if (tile == 'O')
	{
		if ((tile_x >= 3 && tile_x <= 5) || (tile_y >= 3 && tile_y <= 5))
			return (MINI_FLOO_COL);
		return (MINI_WALL_COL);
	}
	if ((tile_x >= 3 && tile_x <= 5) || (tile_y >= 3 && tile_y <= 5))
		return (MINI_WALL_COL);
	return (MINI_FLOO_COL);
}

static void	draw_player(int cam_w, mlx_image_t *img)
{
	int	player_size;
	int	i;
	int	j;

	player_size = MINI_TILE / 2;
	i = (cam_w - player_size) / 2;
	if (i < 0)
		return ;
	while (i < (cam_w + player_size) / 2)
	{
		j = (cam_w - player_size) / 2;
		if (j < 0)
			return ;
		while (j < (cam_w + player_size) / 2)
		{
			mlx_put_pixel(img, i, j, MINI_PLAY_COL);
			j++;
		}
		i++;
	}
}

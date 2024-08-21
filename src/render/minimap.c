/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psacrist <psacrist@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:41:20 by jberdugo          #+#    #+#             */
/*   Updated: 2024/08/21 20:09:35 by psacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"
#include "libft.h"

#include <math.h>

static int	minimap_color(t_vector map_coord, char **map);
static void	draw_player(int cam_w, int cam_h, mlx_image_t *img);
t_vector	rot_map(t_vector map, t_vector dir, t_vector pos);

void	minimap(t_data *data)
{
	t_vector	map;
	int			i;
	int			j;
	int			cam_w;
	int			cam_h;

	cam_w = WIDTH / MINI_FRAC;
	cam_h = HEIGHT / MINI_FRAC;
	i = 0;
	while (i < cam_w) //mirar rendimiento
	{
		j = 0;
		while (j < cam_h)
		{
			map.x = data->player.position.x + \
				(i + 1 - (double)cam_w / 2) / MINI_TILE;
			map.y = data->player.position.y + \
				(j + 1 - (double)cam_h / 2) / MINI_TILE;
			map = rot_map(map, data->player.direction, data->player.position);
			if (pow(i - cam_w / 2, 2) + pow(j - cam_h / 2, 2) <= pow(cam_h / 2, 2))
				mlx_put_pixel(data->minimap, i, j, minimap_color(map, data->map));
			j++;
		}
		i++;
	}
	draw_player(cam_w, cam_h, data->minimap);
}

t_vector	rot_map(t_vector map, t_vector dir, t_vector pos)
{
	t_vector	centered;
	t_vector	transformed;
	(void)pos;
	centered = (t_vector){map.x - pos.x, map.y - pos.y};
	transformed.x = (- dir.x * centered.y - dir.y * centered.x) + pos.x;
	transformed.y = (dir.x * centered.x - dir.y * centered.y) + pos.y;
	return (transformed);
}

static int	minimap_color(t_vector map_coord, char **map)
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
	return (MINI_VOID_COL);
}

static void	draw_player(int cam_w, int cam_h, mlx_image_t *img)
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
		j = (cam_h - player_size) / 2;
		if (j < 0)
			return ;
		while (j < (cam_h + player_size) / 2)
		{
			mlx_put_pixel(img, i, j, MINI_PLAY_COL);
			j++;
		}
		i++;
	}
}

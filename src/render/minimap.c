/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:41:20 by jberdugo          #+#    #+#             */
/*   Updated: 2024/08/13 14:47:29 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"
#include "libft.h"

static int	minimap_color(t_vector map_coord, char **map);
static void	draw_player(int cam_w, int cam_h, mlx_image_t *img);

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
		map.x = data->player.position.x + \
			(i + 1 - (double)cam_w / 2) / MINI_TILE;
		j = 0;
		while (j < cam_h)
		{
			map.y = data->player.position.y + \
				(j + 1 - (double)cam_h / 2) / MINI_TILE;
			mlx_put_pixel(data->minimap, i, j, minimap_color(map, data->map));
			j++;
		}
		i++;
	}
	draw_player(cam_w, cam_h, data->minimap);
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

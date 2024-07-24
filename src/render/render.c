/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psacrist <psacrist@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:29:05 by psacrist          #+#    #+#             */
/*   Updated: 2024/07/24 12:57:40 by psacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "cub3d.h"
#include "parser.h"

void	draw_a_ray(t_ray *ray, int col, void *img, t_texture_paths colors);
int		select_color(t_ray *ray, int wall_y);
void	minimap(t_data *data);
int	minimap_color(t_vector map_coord, char **map);
int	len_2d_array(char **array);
int	create_images(t_data *data);
void	draw_player(int cam_w, int cam_h, mlx_image_t *img);

void	render(t_data *data, t_list *rays)
{
	t_ray		*ray;
	int			i;

	if (!data->scene)
	{
		if (!create_images(data))
			exit(EXIT_FAILURE);
	}
	i = 0;
	while (rays)
	{
		ray = (t_ray *)rays->content;
		draw_a_ray(ray, i, data->scene, *data->raw_textures);
		rays = rays->next;
		i++;
	}
	minimap(data);
}

int	create_images(t_data *data)
{
	data->scene = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->scene)
		return (0); //print error
	if (mlx_image_to_window(data->mlx, data->scene, 0, 0) < 0)
		return (0);
	data->minimap = mlx_new_image(data->mlx, WIDTH / MINI_FRAC, HEIGHT / MINI_FRAC);
	if (!data->minimap)
		return (0); //print error
	if (mlx_image_to_window(data->mlx, data->minimap, 0, 0) < 0)
		return (0);
	return (1);
}

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
		map.x = data->player.position.x + (i + 1 - (double)cam_w / 2) / MINI_TILE;
		j = 0;
		while (j < cam_h)
		{
			map.y = data->player.position.y + (j + 1 - (double)cam_h / 2) / MINI_TILE;
			mlx_put_pixel(data->minimap, i, j, minimap_color(map, data->map));
			j++;
		}
		i++;
	}
	draw_player(cam_w, cam_h, data->minimap);
}

void	draw_player(int cam_w, int cam_h, mlx_image_t *img)
{
	int	player_size;
	int	i;
	int j;

	player_size = MINI_TILE / 2;
	i = (cam_w - player_size) / 2;
	while (i < (cam_w + player_size) / 2)
	{
		j = (cam_h - player_size) / 2;
		while (j < (cam_h + player_size) / 2)
		{
			mlx_put_pixel(img, i, j, MINI_PLAY_COL);
			j++;
		}
		i++;
	}
}

int	minimap_color(t_vector map_coord, char **map)
{
	char	tile;

	if (map_coord.x < 0 || map_coord.y < 0)
		return (MINI_VOID_COL);
	if (map_coord.y > len_2d_array(map))
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

int	len_2d_array(char **array)
{
	int	len;

	len = 0;
	while (array[len])
		len++;
	return (len);
}

void	draw_a_ray(t_ray *ray, int col, void *img, t_texture_paths colors)
{
	int				start;
	int				end;
	int				i;

	start = (HEIGHT - ray->wall_len) / 2;
	end = start + ray->wall_len;
	if (start < 0)
		start = 0;
	if (end > HEIGHT)
		end = HEIGHT;
	i = 0;
	while (i < start)
	{
		mlx_put_pixel(img, col, i, colors.ceiling);
		i++;
	}
	while (i < end)
	{
		mlx_put_pixel(img, col, i, select_color(ray, i - (HEIGHT - ray->wall_len) / 2));
		i++;
	}
	while (end < HEIGHT)
	{
		mlx_put_pixel(img, col, end, colors.floor);
		end++;
	}
}

int	select_color(t_ray *ray, int wall_y)
{
	int	tex_x;
	int	tex_y;
	int	color;
	int	pixel_index;
	int	i;

	tex_x = ray->wall_tex->width * ray->wall_x;
	tex_y = (double)ray->wall_tex->height / (double)ray->wall_len * (double)wall_y;
	pixel_index = (tex_y * ray->wall_tex->width + tex_x) * ray->wall_tex->bytes_per_pixel;
	i = 0;
	while (i < ray->wall_tex->bytes_per_pixel)
	{
		color <<= 8;
		color += ray->wall_tex->pixels[pixel_index + i];
		i++;
	}
	return (color);
}

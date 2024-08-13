/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:29:05 by psacrist          #+#    #+#             */
/*   Updated: 2024/08/13 14:42:06 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "cub3d.h"
#include "parser.h"
#include "libft.h"

void	draw_a_ray(t_ray *ray, int col, void *img, t_texture_paths colors);
int		select_color(t_ray *ray, int wall_y);
int		create_images(t_data *data);

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
	data->minimap = mlx_new_image(data->mlx, WIDTH / MINI_FRAC, \
		HEIGHT / MINI_FRAC);
	if (!data->minimap)
		return (0); //print error
	if (mlx_image_to_window(data->mlx, data->minimap, MINI_TILE, MINI_TILE) < 0)
		return (0);
	return (1);
}

void	draw_a_ray(t_ray *ray, int col, void *img, t_texture_paths colors)
{
	int	start;
	int	end;
	int	i;

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
		mlx_put_pixel(img, col, i, \
			select_color(ray, i - (HEIGHT - ray->wall_len) / 2));
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
	tex_y = (double)ray->wall_tex->height / (double)ray->wall_len \
		* (double)wall_y;
	pixel_index = (tex_y * ray->wall_tex->width + tex_x) \
		* ray->wall_tex->bytes_per_pixel;
	i = 0;
	color = 0;
	while (i < ray->wall_tex->bytes_per_pixel)
	{
		color <<= 8;
		color += ray->wall_tex->pixels[pixel_index + i];
		i++;
	}
	return (color);
}

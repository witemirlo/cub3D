/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psacrist <psacrist@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:36:43 by psacrist          #+#    #+#             */
/*   Updated: 2024/08/27 16:34:11 by psacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "cub3d.h"
#include "libft.h"
#include "MLX42.h"
#include "texturer.h"

#include <math.h>

static int	select_color(double sp_x, double sp_y, mlx_texture_t *sprite);
void		*ft_lstget(t_list *list, unsigned int index);
t_vector	rotate_dis(t_vector	sprite, t_vector dir);
t_vector	*sort_sprites(t_vector *sprites, size_t n, t_vector pos);

#include <stdio.h>
void	render_sprites(t_data *data, t_list *rays)
{
	t_vector	*sprites; //ordenados

	t_vector	dis;
	double		wide_x;
	int			screen_x;
	int			line_h;
	int			sprite_width;
	int			color;
	size_t		index;

	if (!data->sprites)
		return ;
	sprites = sort_sprites(data->sprites, data->sprites_size, data->player.position);
	index = 0;
	while (index < data->sprites_size)
	{
		dis = (t_vector){sprites[index].x - data->player.position.x, - sprites[index].y + data->player.position.y};
		dis = rotate_dis(dis, data->player.direction);
		if (dis.y < 0)
		{
			index++;	
			continue ;
		}
		wide_x = dis.y * (double)4 / (double)3; //use camera
		screen_x = ((WIDTH / wide_x) * dis.x) + WIDTH / 2;
		sprite_width = (WIDTH / wide_x); //tiene que ser igual ma line_h?
		line_h = (HEIGHT) / dis.y;
		//printf("\tsprite size: w %d, h %d\n", sprite_width, line_h);
		//printf("wide_x %f\n", wide_x);
		//printf("\tsprite loc %d\n", screen_x);
		//printf("\tdistance to spr: x %f, y %f\n", dis.x, dis.y);
		for (int i = 0; i < sprite_width; i++)
		{
			int x = screen_x - (sprite_width / 2) + i;
			if (x < 0 || x >= WIDTH)
				continue;
			if ((double)HEIGHT / ((t_ray *)(ft_lstget(rays, x)))->wall_len < dis.y)
				continue;
			for (int j = 0; j < line_h; j++)
			{
				int y = (HEIGHT / 2) - (line_h / 2) + j;
				if (y < 0 || y >= HEIGHT)
					continue;
				color = select_color((double)i / sprite_width, (double)j / line_h, data->textures->sprite);
				if (color & 0xFF)
					mlx_put_pixel(data->scene, x, y, color);
			}
		}
		index++;
	}
	//TODO: fisheye
}

t_vector	rotate_dis(t_vector	sprite, t_vector dir)
{
	t_vector	transformed;

	transformed.x = (- dir.x * sprite.y - dir.y * sprite.x);
	transformed.y = (dir.x * sprite.x - dir.y * sprite.y);
	return (transformed);
}

t_vector	*sort_sprites(t_vector *sprites, size_t n, t_vector pos) //posible leaks
{
	size_t		i;
	size_t		j;
	t_vector	tmp;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (pow(sprites[i].x - pos.x, 2) + pow(sprites[i].y -pos.y, 2) < \
				pow(sprites[j].x - pos.x, 2) + pow(sprites[j].y -pos.y, 2))
			{
				tmp = sprites[j];
				sprites[j] = sprites[i];
				sprites[i] = tmp;
			}
			j++;
		}
		i++;
	}
	return (sprites);
}

void	*ft_lstget(t_list *list, unsigned int index)
{
	unsigned int	i;

	i = 0;
	if (!list)
		return (list);
	while (i != index)
	{
		if (!list->next)
			return (NULL);
		list = list->next;
		i++;
	}
	return (list->content);
}

static int	select_color(double sp_x, double sp_y, mlx_texture_t *sprite)
{
	int	tex_x;
	int	tex_y;
	int	color;
	int	pixel_index;
	int	i;

	tex_x = sprite->width * sp_x;
	tex_y = sprite->height * sp_y;
	pixel_index = (tex_y * sprite->width + tex_x) \
		* sprite->bytes_per_pixel;
	i = 0;
	color = 0;
	while (i < sprite->bytes_per_pixel)
	{
		color <<= 8;
		color += sprite->pixels[pixel_index + i];
		i++;
	}
	return (color);
}

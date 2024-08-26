/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psacrist <psacrist@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:36:43 by psacrist          #+#    #+#             */
/*   Updated: 2024/08/26 19:17:30 by psacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "cub3d.h"
#include "libft.h"
#include "MLX42.h"
#include "texturer.h"

static int	select_color(double sp_x, double sp_y, mlx_texture_t *sprite);
void		*ft_lstget(t_list *list, unsigned int index);
t_vector	rotate_dis(t_vector	sprite, t_vector dir);

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
	(void)rays;
	sprites = data->sprites;
	if (!sprites)
	{
		return ;
	}
	dis = (t_vector){sprites->x - data->player.position.x, - sprites->y + data->player.position.y};
	dis = rotate_dis(dis, data->player.direction);
	if (dis.y < 0)
		return ;
	wide_x = dis.y * 2 / 3; //camera
	screen_x = ((WIDTH / wide_x) * dis.x) + WIDTH / 2;
	sprite_width = (WIDTH / wide_x); //tiene que ser igual ma line_h
	line_h = (HEIGHT) / dis.y;
	if (line_h > HEIGHT)
		line_h = HEIGHT;
	//printf("\tsprite size: w %d, h %d\n", sprite_width, line_h);
	for (int i = 0; i < line_h; i++)
	{
		int x = screen_x - (line_h / 2) + i;
		if (/*HEIGHT / ((t_ray *)(ft_lstget(rays, i)))->wall_len < dis.y ||*/ x < 0 || x > WIDTH)
			continue;
		for (int j = 0; j < line_h; j++)
		{
			int y = (HEIGHT / 2) - (line_h / 2) + j;
			if (y < 0 || y > HEIGHT)
				continue;
			color = select_color((double)i / line_h, (double)j / line_h, data->textures->door);
			if (color & 0xFF)
				mlx_put_pixel(data->scene, x, y, color);
		}
	}
}

t_vector	rotate_dis(t_vector	sprite, t_vector dir)
{
	t_vector	transformed;

	transformed.x = (- dir.x * sprite.y - dir.y * sprite.x);
	transformed.y = (dir.x * sprite.x - dir.y * sprite.y);
	return (transformed);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_one_sprite.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psacrist <psacrist@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:00:31 by psacrist          #+#    #+#             */
/*   Updated: 2024/08/27 18:07:14 by psacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "cub3d.h"
#include "texturer.h"

static void	draw_sprite_col(t_data *data, t_sp_info info, int i, int x);
static void	*ft_lstget(t_list *list, unsigned int index);
static int	select_color(double sp_x, double sp_y, mlx_texture_t *sprite);

void	render_one_sprite(t_data *data, t_list *rays, t_sp_info info)
{
	int	x;
	int	i;

	i = -1;
	while (++i < info.sprite_w)
	{
		x = info.center_x - (info.sprite_w / 2) + i;
		if (x < 0 || x >= WIDTH)
			continue ;
		if ((double)HEIGHT / ((t_ray *)(ft_lstget(rays, x)))->wall_len < \
			info.dis.y)
			continue ;
		draw_sprite_col(data, info, i, x);
	}
}

static void	draw_sprite_col(t_data *data, t_sp_info info, int i, int x)
{
	int	y;
	int	color;
	int	j;

	j = -1;
	while (++j < info.sprite_h)
	{
		y = (HEIGHT / 2) - (info.sprite_h / 2) + j;
		if (y < 0 || y >= HEIGHT)
			continue ;
		color = select_color((double)i / info.sprite_w, \
			(double)j / info.sprite_h, data->textures->sprite);
		if (color & 0xFF)
			mlx_put_pixel(data->scene, x, y, color);
	}
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

static void	*ft_lstget(t_list *list, unsigned int index)
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

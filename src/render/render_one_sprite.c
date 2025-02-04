/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_one_sprite.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psacrist <psacrist@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:00:31 by psacrist          #+#    #+#             */
/*   Updated: 2024/08/28 13:00:58 by psacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "cub3d.h"
#include "texturer.h"

static void	draw_sprite_col(t_data *data, t_sp_info info, int i, int x);
static void	*ft_lstget(t_list *list, unsigned int index);

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
	int	tx_x;
	int	tx_y;

	j = -1;
	while (++j < info.sprite_h)
	{
		y = (HEIGHT / 2) - (info.sprite_h / 2) + j;
		if (y < 0 || y >= HEIGHT)
			continue ;
		tx_x = ((double)i / info.sprite_w) * data->textures->sprite->width / 4;
		tx_y = ((double)j / info.sprite_h) * data->textures->sprite->height;
		color = get_sprite_color(data->textures->sprite, data->anim_info.frame, \
			tx_x, tx_y);
		if (color & 0xFF)
			mlx_put_pixel(data->scene, x, y, color);
	}
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

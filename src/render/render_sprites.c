/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psacrist <psacrist@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:36:43 by psacrist          #+#    #+#             */
/*   Updated: 2024/08/27 18:09:32 by psacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "cub3d.h"
#include "libft.h"
#include "MLX42.h"
#include "texturer.h"

#include <math.h>

static t_vector	rotate_dis(t_vector	sprite, t_vector dir);
static t_vector	*sort_sprites(t_vector *sprites, size_t n, t_vector pos);

void	render_sprites(t_data *data, t_list *rays)
{
	t_vector	*sprites;
	size_t		index;
	t_sp_info	info;

	if (!data->sprites)
		return ;
	sprites = sort_sprites(data->sprites, data->sprites_size, \
		data->player.position);
	index = -1;
	while (++index < data->sprites_size)
	{
		info.dis = (t_vector){sprites[index].x - data->player.position.x, \
			- sprites[index].y + data->player.position.y};
		info.dis = rotate_dis(info.dis, data->player.direction);
		if (info.dis.y < 0)
			continue ;
		info.xy_prop = info.dis.y * (double)4 / (double)3;
		info.center_x = ((WIDTH / info.xy_prop) * info.dis.x) + WIDTH / 2;
		info.sprite_h = HEIGHT / info.dis.y;
		info.sprite_w = WIDTH / info.xy_prop;
		render_one_sprite(data, rays, info);
	}
}

static t_vector	rotate_dis(t_vector	sprite, t_vector dir)
{
	t_vector	transformed;

	transformed.x = -dir.x * sprite.y - dir.y * sprite.x;
	transformed.y = dir.x * sprite.x - dir.y * sprite.y;
	return (transformed);
}

static t_vector	*sort_sprites(t_vector *sprites, size_t n, t_vector pos)
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
			if (pow(sprites[i].x - pos.x, 2) + pow(sprites[i].y - pos.y, 2) < \
				pow(sprites[j].x - pos.x, 2) + pow(sprites[j].y - pos.y, 2))
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

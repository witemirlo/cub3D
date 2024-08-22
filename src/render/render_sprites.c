/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psacrist <psacrist@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:36:43 by psacrist          #+#    #+#             */
/*   Updated: 2024/08/22 18:09:03 by psacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "cub3d.h"
#include "libft.h"
#include "MLX42.h"

void	render_sprites(t_data *data, t_list *rays)
{
	t_vector	*sprites; //ordenados

	while (sprites)
	{
		t_vector	dis;
		int			start;
		int			end;
		int			sprite_height;

		dis = (t_vector){sprites->x - data->player.position.x, sprites->y - data->player.position.y};
		sprite_height = (HEIGHT / dis.y);
		start = (HEIGHT - sprite_height) / 2;
		end = start + sprite_height;
		//sacar x
		//comprobar la distancia del rayo
		//dibujar rayo sprite
			//vigilar vacios
			//ver que tenga sentido dibujarlo
	}
}

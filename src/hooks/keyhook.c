/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psacrist <psacrist@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 08:56:16 by psacrist          #+#    #+#             */
/*   Updated: 2024/07/20 09:22:46 by psacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"
#include "MLX42.h"
#include "cub3d.h"
#include <math.h>

void	more_keys(mlx_key_data_t keydata, t_data *param);
void	get_trig(double *my_sin, double *my_cos);

void	keyhook(mlx_key_data_t keydata, void* param)
{
	static double	sin_r;
	static double	cos_r;
	t_player		*player;

	if (!sin_r && !cos_r)
		get_trig(&sin_r, &cos_r);
	player = &((t_data *)param)->player;
	if (keydata.key == MLX_KEY_LEFT)
	{
		player->direction.x = cos_r * player->direction.x \
			- sin_r * player->direction.y;
		player->direction.y = sin_r * player->direction.x \
			+ cos_r * player->direction.y;
	}
	else if (keydata.key == MLX_KEY_RIGHT)
	{
		player->direction.x = cos_r * player->direction.x \
			+ sin_r * player->direction.y;
		player->direction.y = - sin_r * player->direction.x \
			+ cos_r * player->direction.y;
	}
	else
		more_keys(keydata, (t_data *)param);
}

void	more_keys(mlx_key_data_t keydata, t_data *param)
{
	(void)keydata;
	(void)param;
}

void	get_trig(double *my_sin, double *my_cos)
{
	*my_sin = sin(ROT_SPEED);
	*my_cos = cos(ROT_SPEED);
}

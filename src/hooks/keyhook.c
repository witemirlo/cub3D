/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psacrist <psacrist@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 08:56:16 by psacrist          #+#    #+#             */
/*   Updated: 2024/07/20 09:47:35 by psacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"
#include "MLX42.h"
#include "cub3d.h"
#include <math.h>

void	more_keys(mlx_key_data_t keydata, t_data *param);
void	get_trig(double *my_sin, double *my_cos);
void	new_camera(t_player *player);

#include <stdio.h>
void	keyhook(mlx_key_data_t keydata, void* param)
{
	static double	sin_r;
	static double	cos_r;
	t_player		*player;
	t_vector		old_dir;

	if (!sin_r && !cos_r)
		get_trig(&sin_r, &cos_r);
	player = &((t_data *)param)->player;
	old_dir = player->direction;
	if (keydata.key == MLX_KEY_RIGHT)
	{
		player->direction.x = cos_r * old_dir.x - sin_r * old_dir.y;
		player->direction.y = sin_r * old_dir.x + cos_r * old_dir.y;
		new_camera(player);
	}
	else if (keydata.key == MLX_KEY_LEFT)
	{
		player->direction.x = cos_r * old_dir.x + sin_r * old_dir.y;
		player->direction.y = - sin_r * old_dir.x + cos_r * old_dir.y;
		new_camera(player);
	}
	else
		more_keys(keydata, (t_data *)param);
	printf("dir_x: %f, dir_y: %f\n", player->direction.x, player->direction.y);
}

void	new_camera(t_player *player)
{
	player->camera.x = player->direction.y;
	player->camera.y = player->direction.x;
	if (player->camera.x)
		player->camera.x *= -1;
	else
		player->camera.y *= -1;
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

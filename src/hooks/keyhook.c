/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psacrist <psacrist@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 08:56:16 by psacrist          #+#    #+#             */
/*   Updated: 2024/08/26 13:10:00 by psacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"
#include "MLX42.h"
#include "cub3d.h"
#include <math.h>

void	more_keys(mlx_key_data_t keydata, t_data *param);
void	get_trig(double *my_sin, double *my_cos);
void	new_camera(t_player *player);
void	door_key(t_data *data);

void	keyhook(mlx_key_data_t keydata, void *param)
{
	static double	sin_r;
	static double	cos_r;
	t_player		*player;
	t_vector		old_dir;

	if (keydata.key == MLX_KEY_ESCAPE)
		closehook(param);
	if (keydata.action == MLX_RELEASE)
		return ;
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
		player->direction.y = -sin_r * old_dir.x + cos_r * old_dir.y;
		new_camera(player);
	}
	if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
		door_key(param);
	else
		more_keys(keydata, (t_data *)param);
}

void	door_key(t_data *data)
{
	int	target_x;
	int	target_y;

	target_x = data->player.position.x + data->player.direction.x;
	target_y = data->player.position.y + data->player.direction.y;
	if (data->map[target_y][target_x] == 'C')
		data->map[target_y][target_x] = 'O';
	else if (data->map[target_y][target_x] == 'O')
		data->map[target_y][target_x] = 'C';
}

void	more_keys(mlx_key_data_t keydata, t_data *data)
{
	t_vector	move;

	move = data->player.position;
	if (keydata.key == MLX_KEY_W)
	{
		move.x += data->player.direction.x * MV_FACTOR;
		move.y += data->player.direction.y * MV_FACTOR;
	}
	else if (keydata.key == MLX_KEY_S)
	{
		move.x -= data->player.direction.x * MV_FACTOR;
		move.y -= data->player.direction.y * MV_FACTOR;
	}
	else if (keydata.key == MLX_KEY_A)
	{
		move.x -= data->player.camera.x * MV_FACTOR;
		move.y -= data->player.camera.y * MV_FACTOR;
	}
	else if (keydata.key == MLX_KEY_D)
	{
		move.x += data->player.camera.x * MV_FACTOR;
		move.y += data->player.camera.y * MV_FACTOR;
	}
	if (data->map[(int)move.y][(int)move.x] == '0'
		|| data->map[(int)move.y][(int)move.x] == 'O')
		data->player.position = move;
}

void	new_camera(t_player *player)
{
	player->camera.x = player->direction.y * 2 / 3;
	player->camera.y = player->direction.x * 2 / 3;
	player->camera.x *= -1;
}

void	get_trig(double *my_sin, double *my_cos)
{
	*my_sin = sin(MY_PI / ROT_FACTOR);
	*my_cos = cos(MY_PI / ROT_FACTOR);
}

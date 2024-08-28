/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psacrist <psacrist@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 08:56:16 by psacrist          #+#    #+#             */
/*   Updated: 2024/08/28 14:33:34 by psacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"
#include "MLX42.h"
#include "cub3d.h"

#include <math.h>

static void	move_keys(mlx_key_data_t keydata, char **map, t_player *player);
static void	get_trig(double *my_sin, double *my_cos);
static void	door_key(t_data *data);
static void	rotate(int key, t_player *player, double cos_r, double sin_r);

void	keyhook(mlx_key_data_t keydata, void *param)
{
	static double	sin_r;
	static double	cos_r;
	t_player		*player;

	if (keydata.key == MLX_KEY_ESCAPE)
		closehook(param);
	if (keydata.action == MLX_RELEASE)
		return ;
	if (!sin_r && !cos_r)
		get_trig(&sin_r, &cos_r);
	if (keydata.key == MLX_KEY_C)
	{
		((t_data *)param)->mouse_movement ^= 1;
		return ;
	}
	player = &((t_data *)param)->player;
	if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT)
		rotate(keydata.key, player, cos_r, sin_r);
	if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
		door_key(param);
	else
		move_keys(keydata, ((t_data *)(param))->map, player);
}

static void	rotate(int key, t_player *player, double cos_r, double sin_r)
{
	t_vector		old_dir;

	old_dir = player->direction;
	if (key == MLX_KEY_RIGHT)
	{
		player->direction.x = cos_r * old_dir.x - sin_r * old_dir.y;
		player->direction.y = sin_r * old_dir.x + cos_r * old_dir.y;
	}
	else
	{
		player->direction.x = cos_r * old_dir.x + sin_r * old_dir.y;
		player->direction.y = -sin_r * old_dir.x + cos_r * old_dir.y;
	}
	player->camera.x = player->direction.y * 2 / 3;
	player->camera.y = player->direction.x * 2 / 3;
	player->camera.x *= -1;
}

static void	door_key(t_data *data)
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

static void	move_keys(mlx_key_data_t keydata, char **map, t_player *player)
{
	t_vector	move;

	if (keydata.key == MLX_KEY_W)
		move = (t_vector){player->direction.x, player->direction.y};
	else if (keydata.key == MLX_KEY_S)
		move = (t_vector){-player->direction.x, -player->direction.y};
	else if (keydata.key == MLX_KEY_A)
		move = (t_vector){player->direction.y, -player->direction.x};
	else if (keydata.key == MLX_KEY_D)
		move = (t_vector){-player->direction.y, player->direction.x};
	else
		return ;
	move.x = move.x * MV_FACTOR + player->position.x;
	move.y = move.y * MV_FACTOR + player->position.y;
	if ((map[(int)move.y][(int)move.x] == '0' \
		|| map[(int)move.y][(int)move.x] == 'O') \
		&& (map[(int)move.y][(int)player->position.x] == '0' \
		|| map[(int)move.y][(int)player->position.x] == 'O') \
		&& (map[(int)player->position.y][(int)move.x] == '0' \
		|| map[(int)player->position.y][(int)move.x] == 'O'))
		player->position = move;
}

static void	get_trig(double *my_sin, double *my_cos)
{
	*my_sin = sin(MY_PI / ROT_FACTOR);
	*my_cos = cos(MY_PI / ROT_FACTOR);
}

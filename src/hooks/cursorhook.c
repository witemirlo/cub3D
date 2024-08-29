/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursorhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:25:24 by psacrist          #+#    #+#             */
/*   Updated: 2024/08/29 19:11:33 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"
#include "MLX42.h"
#include "cub3d.h"

int	cursor_movement(void *param);

void	cursorhook(double xpos, double ypos, void *param)
{
	static double	last_x;
	mlx_key_data_t	keydata;
	t_data			*data;

	if (!cursor_movement(param))
		return ;
	data = param;
	keydata.modifier = 0;
	keydata.os_key = 0;
	keydata.action = MLX_PRESS;
	(void)ypos;
	if (xpos > last_x)
		keydata.key = MLX_KEY_RIGHT;
	else if (xpos < last_x)
		keydata.key = MLX_KEY_LEFT;
	else
	{
		last_x = xpos;
		return ;
	}
	last_x = xpos;
	keyhook(keydata, param);
}

int	cursor_movement(void *param)
{
	int	x;
	int	y;

	if (!((t_data *)(param))->mouse_movement)
		return (0);
	mlx_get_mouse_pos(((t_data *)(param))->mlx, &x, &y);
	if (x > WIDTH || x < 0)
		x = WIDTH / 2;
	mlx_set_mouse_pos(((t_data *)(param))->mlx, x, HEIGHT / 2);
	return (1);
}

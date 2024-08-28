/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursorhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psacrist <psacrist@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:25:24 by psacrist          #+#    #+#             */
/*   Updated: 2024/08/28 17:30:14 by psacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"
#include "MLX42.h"
#include "cub3d.h"

void	cursorhook(double xpos, double ypos, void *param)
{
	static double	last_x;
	mlx_key_data_t	keydata;
	t_data			*data;

	if (!(((t_data*)param)->mouse_movement))
		return ;
	data = param;
	keydata.modifier = 0;
	keydata.os_key = 0;
	keydata.action = MLX_PRESS;
	(void)ypos;
	if (xpos > last_x) //no me convence como control
		keydata.key = MLX_KEY_RIGHT;
	else if (xpos < last_x)
		keydata.key = MLX_KEY_LEFT;
	else
	{
		last_x = xpos;
		return ;
	}
	last_x = xpos;
	//mlx_set_mouse_pos(data->mlx, WIDTH / 2, ypos);
	keyhook(keydata, param);
}

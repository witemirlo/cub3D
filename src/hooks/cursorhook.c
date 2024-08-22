/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursorhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psacrist <psacrist@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:25:24 by psacrist          #+#    #+#             */
/*   Updated: 2024/08/22 12:50:15 by psacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"
#include "MLX42.h"
#include "cub3d.h"

void	cursorhook(double xpos, double ypos, void *param)
{
	mlx_key_data_t	keydata;
	t_data			*data;
	static double	last_x;

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

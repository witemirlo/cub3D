/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursorhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psacrist <psacrist@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:25:24 by psacrist          #+#    #+#             */
/*   Updated: 2024/08/21 14:19:22 by psacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"
#include "MLX42.h"
#include "cub3d.h"

void	cursorhook(double xpos, double ypos, void *param)
{
	mlx_key_data_t	keydata;
	static double	last_x;

	keydata.modifier = 0;
	keydata.os_key = 0;
	keydata.action = MLX_PRESS;
	(void)ypos;
	if (xpos > last_x) //tambien podria ser solo el last_x
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

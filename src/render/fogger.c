/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fogger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psacrist <psacrist@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:35:23 by psacrist          #+#    #+#             */
/*   Updated: 2024/08/28 18:46:22 by psacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"
#include "MLX42.h"
#include <stdio.h>
int	fogger(int ori_color, int dis, t_dis_type tp)
{
	double	fog_prop;
	int		result;

	fog_prop = 0;
	if (tp == CIEL_OR_FLOOR)
	{
		fog_prop = (HEIGHT / 2) - dis;
		//fog_prop = fog_prop / ((double)HEIGHT / 2);
		if (fog_prop < 0)
			fog_prop *= -1;
	}
	result = 0xFF;
	result += ((int)((int)(ori_color & 0xFF00) / fog_prop * FOG_MULT) & 0xFF00);
	result += ((int)((int)(ori_color & 0xFF0000) / fog_prop * FOG_MULT) & 0xFF0000);
	result += ((int)((int)(ori_color & 0xFF000000) / fog_prop * FOG_MULT) & 0xFF000000);
	//result += ((int)((int)(FOG_COL & 0xFF00) / (1 - fog_prop)) & 0xFF00);
	//result += ((int)((int)(FOG_COL & 0xFF0000) / (1 - fog_prop)) & 0xFF0000); 
	//result += ((int)((int)(FOG_COL & 0xFF000000) / (1 - fog_prop)) & 0xFF000000);
	return (result);
}

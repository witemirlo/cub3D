/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psacrist <psacrist@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:29:05 by psacrist          #+#    #+#             */
/*   Updated: 2024/07/16 11:59:17 by psacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "MLX42.h"
#include <math.h>

#define WIDTH 640
#define HEIGHT 360

#define PRES 100
#define FIELD 1
#define ANG M_PI / 2

void render(t_data *data)
{
	double x; //mover defines a otro sitio
	double y;

	x = data->player.position.x * PRES + (PRES / 2);
	y = data->player.position.y * PRES + (PRES / 2);

	
}

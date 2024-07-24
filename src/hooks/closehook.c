/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closehook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psacrist <psacrist@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:07:50 by psacrist          #+#    #+#             */
/*   Updated: 2024/07/24 10:16:49 by psacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"
#include "cub3d.h"
#include "parser.h"
#include "texturer.h"
#include "MLX42.h"

void	closehook(void *param)
{
	t_data *data;

	data = param;
	clear_parser(data);
	clear_texturer(&data->textures);
	mlx_delete_image(data->mlx, data->scene);
	mlx_delete_image(data->mlx, data->minimap);
	mlx_close_window(data->mlx);
	mlx_terminate(data->mlx);
	exit(EXIT_SUCCESS);
}

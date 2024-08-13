/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closehook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:07:50 by psacrist          #+#    #+#             */
/*   Updated: 2024/08/13 15:05:17 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"
#include "cub3d.h"
#include "parser.h"
#include "texturer.h"
#include "MLX42.h"

void	closehook(void *param)
{
	t_data	*data;

	data = param; //a lo mejor aqui solo hay que cerrar la imagen y poner el resto en main
	clear_parser(data);
	clear_texturer(&data->textures);
	mlx_delete_image(data->mlx, data->scene);
	mlx_delete_image(data->mlx, data->minimap);
	mlx_close_window(data->mlx);
	mlx_terminate(data->mlx);
	exit(EXIT_SUCCESS);
}

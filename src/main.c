/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psacrist <psacrist@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:35:49 by jberdugo          #+#    #+#             */
/*   Updated: 2024/08/28 19:36:13 by psacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "colors.h"
#include "libft.h"
#include "parser.h"
#include "texturer.h"
#include "raycaster.h"
#include "render.h"
#include "MLX42.h"
#include "hooks.h"

#include <stdio.h>

void	draw(void *param);

int	main(int argc, char *argv[])
{
	t_data	data;
	void	*mlx;

	if (argc != 2)
		return (ft_putendl_fd("usage: cub3D [PATH TO MAP]", 2), \
			EXIT_FAILURE);
	ft_memset(&data, 0, sizeof(t_data));
	if (!parser(&data, argv[1]))
		return (EXIT_FAILURE);
	if (!texturer(&data))
	{
		clear_parser(&data);
		return (EXIT_FAILURE);
	}
	mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (!mlx)
		return (EXIT_FAILURE);
	data.mlx = mlx;
	draw(&data);
	mlx_key_hook(mlx, keyhook, &data);
	mlx_loop_hook(mlx, draw, &data);
	mlx_close_hook(mlx, closehook, &data);
	mlx_cursor_hook(mlx, cursorhook, &data);
	mlx_loop(mlx);
	return (0);
}

void	draw(void *param)
{
	t_data	*data;
	t_list	*rays;

	data = (t_data *)param;
	rays = raycaster(data->player, data->map, *data->textures);
	if (!rays)
	{
		perror("Error: ");
		exit(EXIT_FAILURE);
	}
	render_walls(data, rays);
	if (data->anim_info.last_update >= ANIM_UPDATE)
	{
		data->anim_info.frame++;
		data->anim_info.frame = data->anim_info.frame % 4;
		data->anim_info.last_update = 0;
	}
	else
		data->anim_info.last_update++;
	render_sprites(data, rays);
	minimap(data);
	ft_lstclear(&rays, free);
}

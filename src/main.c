/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:35:49 by jberdugo          #+#    #+#             */
/*   Updated: 2024/07/11 19:54:15 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "colors.h"
#include "libft.h"
#include "parser.h"
#include "texturer.h"
#include "MLX42.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	mlx_t	*mlx = mlx_init(720, 720, "TESTING", false);
	t_data	data;

	if (argc < 2)
		return (ft_putendl_fd("Error: Too few arguments", 2), EXIT_FAILURE);
	ft_memset(&data, 0, sizeof(t_data));
	if (!parser(&data, argv[1]))
		return (EXIT_FAILURE);
	if (!texturer(&data))
	{
		clear_parser(&data);
		return (EXIT_FAILURE);
	}
// -----------------------------------------------------------------------------
	mlx_image_t	*img = mlx_new_image(mlx, 640, 640);

	int i, j;
	i = 0;
	while (i < 128) {
		j = 0;
		while (j < 128) {
			mlx_put_pixel(img, i, j, data.raw_textures->ceiling);
			j++;
		}
		i++;
	}
	while (i < 256) {
		j = 0;
		while (j < 128) {
			mlx_put_pixel(img, i, j, data.raw_textures->floor);
			j++;
		}
		i++;
	}
	mlx_image_t *img2 = mlx_texture_to_image(mlx, data.textures->north);
	

	mlx_image_to_window(mlx, img, 0, 0);
	mlx_image_to_window(mlx, img2, 0, 128);
	mlx_loop(mlx);

	return (0);
}

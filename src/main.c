/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:35:49 by jberdugo          #+#    #+#             */
/*   Updated: 2024/07/08 19:48:09 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "colors.h"
#include "MLX42.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_map_data	*data;

	if (argc < 2)
		return (ft_putendl_fd("Error: Too few arguments", 2), EXIT_FAILURE);
	data = (t_map_data *)(ft_calloc(1, sizeof(t_map_data *)));
	if (!data)
		return (perror(RED"Error"NC), EXIT_FAILURE);
	if (!parser(data, argv[1]))
		return (free(data), EXIT_FAILURE);
// -----------------------------------------------------------------------------
	printf("Ceiling (%3d, %3d, %3d)\n", ((data->texture_paths->ceiling >> 24) & 0xff), ((data->texture_paths->ceiling >> 16) & 0xff), ((data->texture_paths->ceiling >> 8) & 0xff));
	printf("Floor   (%3d, %3d, %3d)\n", ((data->texture_paths->floor >> 24) & 0xff), ((data->texture_paths->floor >> 16) & 0xff), ((data->texture_paths->floor >> 8) & 0xff));

	mlx_t	*mlx = mlx_init(1080, 720, "TESTING", false);
	mlx_image_t	*img = mlx_new_image(mlx, 640, 640);

	int i, j;
	i = 0;
	while (i < 128) {
		j = 0;
		while (j < 128) {
			mlx_put_pixel(img, i, j, data->texture_paths->ceiling);
			j++;
		}
		i++;
	}
	while (i < 256) {
		j = 0;
		while (j < 128) {
			mlx_put_pixel(img, i, j, data->texture_paths->floor);
			j++;
		}
		i++;
	}

	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);

	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psacrist <psacrist@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:35:49 by jberdugo          #+#    #+#             */
/*   Updated: 2024/07/20 08:48:02 by psacrist         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	t_data	data;
	t_list	*rays;
	void	*mlx;

	if (argc < 2)
		return (ft_putendl_fd(RED "Error: Too few arguments" NC, 2), EXIT_FAILURE);
	ft_memset(&data, 0, sizeof(t_data));
	if (!parser(&data, argv[1]))
		return (EXIT_FAILURE);
	if (!texturer(&data))
	{
		clear_parser(&data);
		return (EXIT_FAILURE);
	}
	rays = raycaster(data.player, data.map);
	if (!rays)
		return (EXIT_FAILURE); //malloc
	mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (!mlx)
		return (EXIT_FAILURE);
	render(data, rays, mlx);
	mlx_loop(mlx);
	clear_parser(&data);
	clear_texturer(&data.textures);
	return (0);
}

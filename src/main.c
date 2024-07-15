/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:35:49 by jberdugo          #+#    #+#             */
/*   Updated: 2024/07/15 10:31:20 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "colors.h"
#include "libft.h"
#include "parser.h"
#include "texturer.h"
#include "MLX42.h"

int	main(int argc, char *argv[])
{
	t_data	data;

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
	return (0);
}

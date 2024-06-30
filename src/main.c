/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:35:49 by jberdugo          #+#    #+#             */
/*   Updated: 2024/06/30 15:40:28 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "colors.h"
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

	return (0);
}

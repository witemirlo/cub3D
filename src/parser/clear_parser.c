/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:54:24 by jberdugo          #+#    #+#             */
/*   Updated: 2024/08/22 20:01:47 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

void	clear_parser(t_data *data)
{
	if (!data)
		return ;
	free(data->raw_textures->north);
	data->raw_textures->north = NULL;
	free(data->raw_textures->south);
	data->raw_textures->south = NULL;
	free(data->raw_textures->west);
	data->raw_textures->west = NULL;
	free(data->raw_textures->east);
	data->raw_textures->east = NULL;
	free(data->raw_textures->door);
	data->raw_textures->door = NULL;
	free(data->raw_textures->sprite);
	data->raw_textures->sprite = NULL;
	free(data->raw_textures);
	free(data->sprites);
	data->sprites = NULL;
	clear_2d_array(&data->map);
	data->raw_textures = NULL;
}

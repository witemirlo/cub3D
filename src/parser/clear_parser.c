/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:54:24 by jberdugo          #+#    #+#             */
/*   Updated: 2024/07/15 10:51:59 by jberdugo         ###   ########.fr       */
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
	free(data->raw_textures);
	clear_2d_array(&data->map);
	data->raw_textures = NULL;
}

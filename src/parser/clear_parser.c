/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:54:24 by jberdugo          #+#    #+#             */
/*   Updated: 2024/07/11 15:04:41 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	data->raw_textures = NULL;
}

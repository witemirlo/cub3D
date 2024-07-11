/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:03:13 by jberdugo          #+#    #+#             */
/*   Updated: 2024/07/11 14:29:50 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "cub3d.h"

int	parser(t_data *data, char *file_name)
{
	t_list	*raw_file;

	if (!check_file_type(file_name))
		return (0);
	raw_file = read_file(file_name);
	if (!raw_file)
		return (0);
	if (!check_file_content(raw_file))
		return (close_file(&raw_file), 0);
	data->map = generate_map(goto_map(raw_file));
	if (!data->map)
		return (close_file(&raw_file), 0);
	data->player = get_player(data->map);
	if (data->player.position.x == -1 || data->player.direction.x == -1)
		return (close_file(&raw_file), clear_2d_array(&data->map), 0);
	data->texture_paths = get_texture_paths(raw_file);
	if (!data->texture_paths)
		return (close_file(&raw_file), clear_2d_array(&data->map), 0);
	close_file(&raw_file);
	return (1);
}

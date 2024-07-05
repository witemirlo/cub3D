/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:03:13 by jberdugo          #+#    #+#             */
/*   Updated: 2024/07/05 11:58:51 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

int	parser(t_map_data *data, char const *file_name)
{
	t_list	*raw_file;

	(void)data;
	if (!check_file_type(file_name))
		return (0);
	raw_file = read_file(file_name);
	if (!raw_file)
		return (0);
	if (!check_file_content(raw_file))
		return (close_file(&raw_file), 0);
	data->map = generate_map(goto_map(raw_file));
	close_file(&raw_file);
	return (1);
}

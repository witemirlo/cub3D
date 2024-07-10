/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:54:24 by jberdugo          #+#    #+#             */
/*   Updated: 2024/07/10 19:01:45 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	clear_parser(t_data *data)
{
	if (!data)
		return ;
	free(data->texture_paths->north);
	data->texture_paths->north = NULL;
	free(data->texture_paths->south);
	data->texture_paths->south = NULL;
	free(data->texture_paths->west);
	data->texture_paths->west = NULL;
	free(data->texture_paths->east);
	data->texture_paths->east = NULL;
	free(data->texture_paths);
	data->texture_paths = NULL;
}

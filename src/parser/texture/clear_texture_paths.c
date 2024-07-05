/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_texture_paths.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:23:34 by jberdugo          #+#    #+#             */
/*   Updated: 2024/07/05 12:42:45 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// TODO: hacer que clear_2d_array tambien setee a null
void	clear_texture_paths(t_texture_paths **textures)
{
	if (!textures)
		return ;
	free((*textures)->north);
	(*textures)->north = NULL;
	free((*textures)->south);
	(*textures)->south = NULL;
	free((*textures)->west);
	(*textures)->west = NULL;
	free((*textures)->east);
	(*textures)->east = NULL;
	free(*textures);
	*textures = NULL;
}

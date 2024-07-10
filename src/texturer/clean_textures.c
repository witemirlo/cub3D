/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:10:26 by jberdugo          #+#    #+#             */
/*   Updated: 2024/07/10 15:14:29 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texturer.h"
#include "MLX42.h"

void	clean_textures(t_textures **textures)
{
	if (!*textures)
		return ;
	if ((*textures)->north)
	{
		mlx_delete_texture((*textures)->north);
		(*textures)->north = NULL;
	}
	if ((*textures)->south)
	{
		mlx_delete_texture((*textures)->south);
		(*textures)->south = NULL;
	}
	if ((*textures)->west)
	{
		mlx_delete_texture((*textures)->west);
		(*textures)->west = NULL;
	}
	if ((*textures)->east)
	{
		mlx_delete_texture((*textures)->east);
		(*textures)->east = NULL;
	}
	*textures = NULL;
}

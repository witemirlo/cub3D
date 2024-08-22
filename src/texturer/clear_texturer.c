/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_texturer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:10:26 by jberdugo          #+#    #+#             */
/*   Updated: 2024/08/22 18:37:07 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texturer.h"
#include "MLX42.h"
#include <stdlib.h>

void	clear_texturer2(t_textures **textures);

void	clear_texturer(t_textures **textures)
{
	if (!(*textures))
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
	clear_texturer2(textures);
	free(*textures);
	*textures = NULL;
}

void	clear_texturer2(t_textures **textures)
{
	if ((*textures)->door)
	{
		mlx_delete_texture((*textures)->door);
		(*textures)->door = NULL;
	}
	if ((*textures)->sprite)
	{
		mlx_delete_texture((*textures)->sprite);
		(*textures)->sprite = NULL;
	}
}

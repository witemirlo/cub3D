/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:28:24 by jberdugo          #+#    #+#             */
/*   Updated: 2024/08/24 15:03:12 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "texturer.h"
#include "error_flags.h"
#include "parser.h"
#include "colors.h"
#include "MLX42.h"
#include <stdio.h>

static mlx_texture_t	*get_texture(char *path, int *error, int n);
static void				error_loaded(int *error, int n);

int	texturer(t_data *data)
{
	int	error;

	data->textures = ft_calloc(1, sizeof(t_textures));
	if (!data->textures)
	{
		perror(RED"Error"NC);
		return (0);
	}
	error = 0;
	data->textures->north = get_texture(data->raw_textures->north, &error, 0);
	data->textures->south = get_texture(data->raw_textures->south, &error, 1);
	data->textures->west = get_texture(data->raw_textures->west, &error, 2);
	data->textures->east = get_texture(data->raw_textures->east, &error, 3);
	if (data->raw_textures->door)
		data->textures->door = get_texture(data->raw_textures->door, &error, 4);
	if (data->raw_textures->sprite)
		data->textures->sprite = get_texture(data->raw_textures->sprite, \
			&error, 5);
	if (error)
	{
		print_texturer_error(error);
		clear_texturer(&data->textures);
		return (0);
	}
	return (1);
}

static mlx_texture_t	*get_texture(char *path, int *error, int n)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
	{
		error_loaded(error, n);
		return (NULL);
	}
	if (n == 5 && ((texture->width < 4) || ((texture->width % 4) != 0)))
	{
		error_loaded(error, 6);
		return (NULL);
	}
	return (texture);
}

static void	error_loaded(int *error, int n)
{
	if (n == 0)
		*error |= F_NORTH;
	else if (n == 1)
		*error |= F_SOUTH;
	else if (n == 2)
		*error |= F_WEST;
	else if (n == 3)
		*error |= F_EAST;
	else if (n == 4)
		*error |= F_DOOR;
	else if (n == 5)
		*error |= F_SPRITE;
	else if (n == 6)
		*error |= F_SPRITE_SIZE;
}

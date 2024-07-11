/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:28:24 by jberdugo          #+#    #+#             */
/*   Updated: 2024/07/11 19:54:35 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "texturer.h"
#include "parser.h"
#include "colors.h"
#include "MLX42.h"
#include <stdio.h>

static mlx_texture_t *get_texture(char *path, int *error, int n);
static void	error_loaded(int *error, int n);
static void	error_size(int *error, int n);

int	texturer(t_data *data)
{
	int	error;

	data->textures = ft_calloc(1, sizeof(t_textures *));
	if (!data->textures)
	{
		perror(RED"Error"NC);
		return (0);
	}
	error = 0;
	data->textures->north = get_texture(data->raw_textures->north, &error, 0);
	data->textures->east = get_texture(data->raw_textures->east, &error, 1);
	data->textures->west = get_texture(data->raw_textures->west, &error, 2);
	data->textures->east = get_texture(data->raw_textures->east, &error, 3);
	if (error)
	{
		print_texturer_error(error);
		clean_textures(&data->textures);
		return (0);;
	}
	return (1);
}

static mlx_texture_t *get_texture(char *path, int *error, int n)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
	{
		error_loaded(error, n);
		return (NULL);
	}
	if (texture->height != TILE_SIZE || texture->width != TILE_SIZE)
		error_size(error, n);
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
}

static void	error_size(int *error, int n)
{
	if (n == 0)
		*error |= SIZE_NORTH;
	else if (n == 1)
		*error |= SIZE_SOUTH;
	else if (n == 2)
		*error |= SIZE_WEST;
	else if (n == 3)
		*error |= SIZE_EAST;
}

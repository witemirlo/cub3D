/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprite_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 10:52:31 by jberdugo          #+#    #+#             */
/*   Updated: 2024/08/25 23:38:24 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42.h>

/**
 * @brief Returns the color of a pixel in a sprite sheet
 *
 * @note Don't forget that the max value of x is width/4
 *
 * @param tex pointer to the sprite sheet texture
 * @param fr index of the sprite {0..3}
 * @param x position in horizontal axis
 * @param y position in vertical axis
 *
 * @return int with the color value in RGBA of the given coordinate
 */
int	get_sprite_color(mlx_texture_t *tex, int fr, int x, int y)
{
	int const	index = (tex->bytes_per_pixel * tex->width * y) + \
						((tex->bytes_per_pixel * x) + (tex->width * fr));
	int			color;
	int			i;

	i = 0;
	color = 0;
	while (i < tex->bytes_per_pixel)
	{
		color <<= 8;
		color |= tex->pixels[index + i] & 0xFF;
		i++;
	}
	return (color);
}

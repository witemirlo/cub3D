/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_sprite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 10:52:31 by jberdugo          #+#    #+#             */
/*   Updated: 2024/08/25 13:41:02 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42.h>
#include <stdint.h>

/**
 * @brief Returns the color of a pixel in a sprite sheet
 * @param tex pointer to the sprite sheet texture
 * @param fr index of the sprite {0..3}
 * @param x position in horizontal axis
 * @param y position in vertical axis
 */
int	get_sprite_px(mlx_texture_t *tex, int const fr, int const x, int const y)
{
	int	index;
	int	color;
	int	i;

	index = tex->bytes_per_pixel * y * (tex->width / 4);
	index += tex->bytes_per_pixel * x * (fr + 1);

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


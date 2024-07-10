/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:20:53 by jberdugo          #+#    #+#             */
/*   Updated: 2024/07/10 19:19:12 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURER_H
# define TEXTURER_H

# define TILE_SIZE 128

# include "cub3d.h"
# include "error_flags.h"
# include "MLX42.h"

typedef struct s_textures
{
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*west;
	mlx_texture_t	*east;
}	t_textures;

int			texturer(t_data *data);

void		print_texturer_error(t_error_flags flags);

void		clean_textures(t_textures **textures);

#endif

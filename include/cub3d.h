/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:12:46 by jberdugo          #+#    #+#             */
/*   Updated: 2024/08/27 14:48:36 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define WIDTH 1280
# define HEIGHT 720

# include "MLX42.h"

typedef struct s_texture_paths	t_texture_paths;
typedef struct s_textures		t_textures;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_player
{
	t_vector	position;
	t_vector	direction;
	t_vector	camera;
}	t_player;

typedef struct s_data
{
	t_texture_paths	*raw_textures;
	t_textures		*textures;
	t_player		player;
	char			**map;
	void			*mlx;
	mlx_image_t		*scene;
	mlx_image_t		*minimap;
	t_vector		*sprites;
	size_t			sprites_size;
	int				mouse_movement;
}	t_data;

#endif

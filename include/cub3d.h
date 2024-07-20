/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psacrist <psacrist@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:12:46 by jberdugo          #+#    #+#             */
/*   Updated: 2024/07/20 09:35:44 by psacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define WIDTH 640
# define HEIGHT 480

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
}	t_data;

#endif

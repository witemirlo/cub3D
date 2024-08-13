/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:48:50 by psacrist          #+#    #+#             */
/*   Updated: 2024/08/13 15:02:24 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_H
# define RAYCASTER_H

# include "cub3d.h"
# include "libft.h"
# include "MLX42.h"

# define MV_U 1
# define MV_D -1
# define MV_L -1
# define MV_R 1
# define HORI 0
# define VERT 1

typedef enum e_wall_dir
{
	N,
	S,
	W,
	E,
}	t_wall_dir;

typedef struct s_ray
{
	int				wall_len;
	double			wall_x;
	mlx_texture_t	*wall_tex;
	int				hit_dir;
	t_vector		ray_pos;
	t_vector		ray_dir;
	t_vector		ray_len;
	t_vector		advance;
}	t_ray;

t_list		*raycaster(t_player player, char **map, t_textures tex);

t_vector	first_iteration(t_player player, t_ray ray, t_vector move);
t_vector	get_ray_dir(int ray_num, t_player player);
t_vector	get_ray_mov(int ray_num, t_player player);
double		ft_dabs(double num);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psacrist <psacrist@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:48:50 by psacrist          #+#    #+#             */
/*   Updated: 2024/07/19 09:01:37 by psacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_H
# define RAYCASTER_H

# include "cub3d.h"
# include "libft.h"

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
	int			wall_len;
	t_wall_dir	wall_dir;
	t_vector	ray_pos;
	t_vector	ray_dir;
	t_vector	ray_len;
	t_vector	advance;
}	t_ray;

#endif

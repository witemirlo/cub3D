/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:12:46 by jberdugo          #+#    #+#             */
/*   Updated: 2024/07/10 15:03:30 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

typedef struct s_texture_paths t_texture_paths;
typedef struct s_textures t_textures;

typedef struct s_data
{
	t_texture_paths	*texture_paths;
	t_textures		*textures;
	char			**map;
}	t_data;

#endif

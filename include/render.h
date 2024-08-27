/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psacrist <psacrist@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:39:10 by psacrist          #+#    #+#             */
/*   Updated: 2024/08/27 18:05:47 by psacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cub3d.h"
# include "MLX42.h"
# include "libft.h"
# include "raycaster.h"

# define SWALLCOL 0x008080FF
# define NWALLCOL 0x008080FF
# define WWALLCOL 0x004040FF
# define EWALLCOL 0x00B0B0FF

# define MINI_FRAC 4
# define MINI_H 5	
# define MINI_W 10
# define MINI_TILE 20
# define MINI_WALL_COL 0x7A9CC6FF
# define MINI_FLOO_COL 0x9FBBCCFF
# define MINI_VOID_COL 0x9FBBCC80
# define MINI_PLAY_COL 0xBDE4A7FF

typedef struct s_sp_info
{
	t_vector	dis;
	double		xy_prop;
	int			center_x;
	int			sprite_h;
	int			sprite_w;
}	t_sp_info;

void	render_walls(t_data *data, t_list *rays);
void	minimap(t_data *data);
void	render_sprites(t_data *data, t_list *rays);
void	render_one_sprite(t_data *data, t_list *rays, t_sp_info info);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psacrist <psacrist@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:39:10 by psacrist          #+#    #+#             */
/*   Updated: 2024/07/19 11:24:36 by psacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cub3d.h"
# include "MLX42.h"
# include "libft.h"
# include "raycaster.h"

# define SWALLCOL 0xFF000000
# define NWALLCOL 0x00FF0000
# define WWALLCOL 0x0000FF00
# define EWALLCOL 0x00FFFF00

void	render(t_data data, t_list *rays, void *mlx);

#endif

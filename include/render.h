/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psacrist <psacrist@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:39:10 by psacrist          #+#    #+#             */
/*   Updated: 2024/07/20 12:10:13 by psacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cub3d.h"
# include "MLX42.h"
# include "libft.h"
# include "raycaster.h"

# define SWALLCOL 0x000F90FF
# define NWALLCOL 0x00FF00FF
# define WWALLCOL 0x0000FFFF
# define EWALLCOL 0x00FFFFFF

void	render(t_data data, t_list *rays, void *mlx);

#endif

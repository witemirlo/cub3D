/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psacrist <psacrist@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 08:56:27 by psacrist          #+#    #+#             */
/*   Updated: 2024/07/25 10:45:41 by psacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# define MY_PI 3.14159265358979323846
# define ROT_FACTOR 48
# define MV_FACTOR 0.2

# include "MLX42.h"

void	keyhook(mlx_key_data_t keydata, void *param);
void	closehook(void *param);
void	cursorhook(double xpos, double ypos, void *param);

#endif

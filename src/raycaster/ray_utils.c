/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psacrist <psacrist@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:41:29 by psacrist          #+#    #+#             */
/*   Updated: 2024/07/24 09:46:46 by psacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

/*
	Returns the abs value of a double
*/
double	ft_dabs(double num)
{
	if (num < 0)
		return (-num);
	return (num);
}

/*
	Calculates if the ray is moving up or down, left or right
	Args:	ray_num -> the column number in the screen
			player -> player info
	Return:
			a t_vector with the movement of the ray in the x and y axes
*/
t_vector	get_ray_mov(int ray_num, t_player player)
{
	double		offset;
	t_vector	move;

	offset = (2 * ray_num) / (double)WIDTH - 1;
	if (player.direction.x + player.camera.x * offset < 0)
		move.x = MV_D;
	else
		move.x = MV_U;
	if (player.direction.y + player.camera.y * offset < 0)
		move.y = MV_L;
	else
		move.y = MV_R;
	return (move);
}

/*
	Calculates the ray direction
	Args:	ray_num -> the column number in the screen
			player -> player info
	Return:
			a t_vector with the direcction of the ray
*/
t_vector	get_ray_dir(int ray_num, t_player player)
{
	double		offset;
	t_vector	ray_dir;

	offset = (2 * ray_num) / (double)WIDTH - 1;
	ray_dir.x = player.direction.x + player.camera.x * offset;
	ray_dir.y = player.direction.y + player.camera.y * offset;
	return (ray_dir);
}

/*
	Calculates the distance to the first hit of the ray
	Args:	pl -> player info
			ray -> ray info
			move -> if the ray is moving up or down, left or rigth		
	Return:
			a t_vector with the first distances
*/
t_vector	first_iteration(t_player pl, t_ray ray, t_vector move)
{
	t_vector	ray_1;

	if (move.x == -1)
		ray_1.x = (pl.position.x - ray.ray_pos.x) / ft_dabs(ray.ray_dir.x);
	else
		ray_1.x = (ray.ray_pos.x - pl.position.x + 1) / ft_dabs(ray.ray_dir.x);
	if (move.y == -1)
		ray_1.y = (pl.position.y - ray.ray_pos.y) / ft_dabs(ray.ray_dir.y);
	else
		ray_1.y = (ray.ray_pos.y - pl.position.y + 1) / ft_dabs(ray.ray_dir.y);
	return (ray_1);
}

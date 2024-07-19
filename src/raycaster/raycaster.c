/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psacrist <psacrist@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:48:31 by psacrist          #+#    #+#             */
/*   Updated: 2024/07/19 09:02:53 by psacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

/*
	Generates all the rays for an specific scene with a player and a map
	Args:	player -> the info of the player
			map -> a double array with the map
	Return:
			NULL if error
			A t_list with all the rays needed for the scene
*/
t_list	*raycaster(t_player player, char **map)
{
	t_list	*rays;
	t_list	*node;
	int		ray_num;

	ray_num = 0;
	while (ray_num < WIDTH)
	{
		node = ft_lstnew(cast_one_ray(player, map, ray_num));
		if (!node)
			return (NULL); //malloc y liberar
		if (!node->content)
			return (NULL); //malloc? liberar
		ft_lstadd_back(&rays, node);
		ray_num++;
	}
	return (rays);
}

t_ray	*cast_one_ray(t_player player, char **map, int ray_num)
{
	double		offset;
	t_vector	move;
	t_ray		*ray;

	ray = ft_calloc(1, sizeof (t_ray));
	if (!ray)
		return (NULL);
	ray->ray_pos = (t_vector){(int)player.position.x, (int)player.position.y};
	ray->ray_dir = get_ray_dir(ray_num, player);
	ray->advance = (t_vector){1 / ray->ray_dir.x, 1 / ray->ray_dir.y};//div by 0?
	move = get_ray_mov(ray_num, player);
	ray->ray_len = first_iteration(player, *ray, move);
	ray->wall_len = dda(ray, move, map);
	return (ray);
}

int	dda(t_ray *ray, t_vector move, char **map)
{
	int	hit_dir;

	while (42)
	{
		if (ray->ray_len.x < ray->ray_len.y)
		{
			ray->ray_len.x += ray->advance.x;
			ray->ray_pos.x += move.x;
			hit_dir = HORI;
		}
		else
		{
			ray->ray_len.y += ray->advance.y;
			ray->ray_pos.y += move.y;
			hit_dir = VERT;
		}
		if (map[(int)ray->ray_pos.x][(int)ray->ray_pos.y] == 1)
			break ;
	}
	if (hit_dir == HORI)
		return (HEIGHT / (ray->ray_len.x - ray->advance.x));
	else
		return (HEIGHT / (ray->ray_len.y - ray->advance.y));
}

t_vector	first_iteration(t_player player, t_ray ray, t_vector move)
{
	t_vector	ray_init;

	if (move.x == -1)
		ray_init.x = (player.position.x - ray.ray_pos.x) / ray.ray_dir.x;
	else
		ray_init.x = (ray.ray_pos.x - player.position.x + 1) / ray.ray_dir.x;
	if (move.y == -1)
		ray_init.y = (player.position.y - ray.ray_pos.y) / ray.ray_dir.y;
	else
		ray_init.y = (ray.ray_pos.y - player.position.y + 1) / ray.ray_dir.y;
	return (ray_init);
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

	offset = (2 * ray_num) / (double)WIDTH - 1;
	return ((t_vector){player.direction.x + player.camera.x * offset, \
		player.direction.y + player.camera.y * offset});
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

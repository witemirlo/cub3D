/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psacrist <psacrist@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:48:31 by psacrist          #+#    #+#             */
/*   Updated: 2024/08/26 13:03:56 by psacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"
#include "texturer.h"

t_ray	*cast_one_ray(t_player player, char **map, int ray_num, t_textures tex);
int		dda(t_ray *ray, t_vector move, char **map);
void	wall_hit_info(t_ray *ray, t_vector mv, t_player player, t_textures tex);

/**
 * @brief Generates all the rays for an specific scene with a player and a map
 *
 * @param player the info of the player
 * @param map a double array with the map
 * @param tex the different textures of the game
 *
 * @return a t_list with all the rays needed for the scene (or NULL if error)
 */
t_list	*raycaster(t_player player, char **map, t_textures tex)
{
	t_list	*rays;
	t_list	*node;
	int		ray_num;

	ray_num = 0;
	rays = NULL;
	while (ray_num < WIDTH)
	{
		node = ft_lstnew(cast_one_ray(player, map, ray_num, tex));
		if (!node)
			return (NULL); //malloc y liberar
		if (!node->content)
			return (NULL); //malloc? liberar
		if (!rays)
			rays = node;
		else
			ft_lstadd_back(&rays, node);
		ray_num++;
	}
	return (rays);
}

/**
 * @brief Calculates the information of 1 ray of the scene
 *
 * @param player the info of the player
 * @param map a double array with the map
 * @param ray_num the column of the screen correspondent to this ray
 * @param tex the different textures of the game
 *
 * @return a t_ray with all the info of the ray_num ray
 */
t_ray	*cast_one_ray(t_player player, char **map, int ray_num, t_textures tex)
{
	t_vector	move;
	t_ray		*ray;

	ray = ft_calloc(1, sizeof (t_ray));
	if (!ray)
		return (NULL);
	ray->ray_pos = (t_vector){(int)player.position.x, (int)player.position.y};
	ray->ray_dir = get_ray_dir(ray_num, player);
	ray->advance = (t_vector){ft_dabs(1 / ray->ray_dir.x), \
		ft_dabs(1 / ray->ray_dir.y)};
	move = get_ray_mov(ray_num, player);
	ray->ray_len = first_iteration(player, *ray, move);
	ray->wall_len = dda(ray, move, map);
	wall_hit_info(ray, move, player, tex);
	if (map[(int)ray->ray_pos.y][(int)ray->ray_pos.x] == 'C')
		ray->wall_tex = tex.door;
	return (ray);
}

/**
 * @brief Performs the dda algo for an specific ray
 *
 * @param ray a pointer to a t_ray with the starting ray_pos, 
 * the ray_len and advance parameters calculated
 * @param move a t_vector with the sign of the movement of the ray
 * @param map a double array with the map
 *
 * @return an int with the number of pixels that the wall 
 * hitted by this ray occupies on the screen
 * 
 * @note It also modifies the ray_pos, ray_len and hit_dir t_ray
 *  parameters to reflect the advancement of the ray
 */
int	dda(t_ray *ray, t_vector move, char **map)
{
	while (42)
	{
		if (ray->ray_len.x < ray->ray_len.y)
		{
			ray->ray_len.x += ray->advance.x;
			ray->ray_pos.x += move.x;
			ray->hit_dir = VERT;
		}
		else
		{
			ray->ray_len.y += ray->advance.y;
			ray->ray_pos.y += move.y;
			ray->hit_dir = HORI;
		}
		if (map[(int)ray->ray_pos.y][(int)ray->ray_pos.x] == '1'
			|| map[(int)ray->ray_pos.y][(int)ray->ray_pos.x] == 'C')
			break ;
	}
	if (ray->hit_dir == VERT)
		return (HEIGHT / (ray->ray_len.x - ray->advance.x));
	else
		return (HEIGHT / (ray->ray_len.y - ray->advance.y));
}

/**
 * @brief Recovers information of the wall hitted by the ray
 *
 * @param ray a pointer to a t_ray wich the dda function was applied to
 * @param mv a t_vector with the sign of the movement of the ray
 * @param player the info of the player
 * @param tex the different textures of the game
 * 
 * @note It stores a pointer to the correspondent wall texture in the 
 * wall_tex param of the ray. It also calculate where in the wall the ray 
 * hitted and stores it in the wall_x param
 */
void	wall_hit_info(t_ray *ray, t_vector mv, t_player player, t_textures tex)
{
	if (ray->hit_dir == HORI)
	{
		if (mv.y == -1)
			ray->wall_tex = tex.north;
		else
			ray->wall_tex = tex.south;
		ray->wall_x = player.position.x + \
			(ray->ray_len.y - ray->advance.y) * ray->ray_dir.x;
	}
	else
	{
		if (mv.x == -1)
			ray->wall_tex = tex.east;
		else
			ray->wall_tex = tex.west;
		ray->wall_x = player.position.y + \
			(ray->ray_len.x - ray->advance.x) * ray->ray_dir.y;
	}
	ray->wall_x -= (int)ray->wall_x;
	ray->wall_x = ft_dabs(ray->wall_x);
}

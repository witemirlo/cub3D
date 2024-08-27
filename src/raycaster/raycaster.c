/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psacrist <psacrist@student.42madrid.com    +#+  +:+       +#+        */
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

/*
	Generates all the rays for an specific scene with a player and a map
	Args:	player -> the info of the player
			map -> a double array with the map
	Return:
			NULL if error
			A t_list with all the rays needed for the scene
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

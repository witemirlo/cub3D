/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psacrist <psacrist@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:48:31 by psacrist          #+#    #+#             */
/*   Updated: 2024/07/18 11:29:29 by psacrist         ###   ########.fr       */
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
	t_vector	ray_len;
	t_vector	ray_advance;

	offset = (2 * ray_num) / (double)WIDTH - 1;
	move = get_ray_dir(ray_num, player);
}

t_vector	get_ray_dir(int ray_num, t_player player)
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

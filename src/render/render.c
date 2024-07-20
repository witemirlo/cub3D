/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psacrist <psacrist@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:29:05 by psacrist          #+#    #+#             */
/*   Updated: 2024/07/20 09:24:42 by psacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	draw_a_ray(t_ray *ray, int col, void *img);

void	render(t_data data, t_list *rays, void *mlx)
{
	mlx_image_t	*img;
	t_ray		*ray;
	int			i;

	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img)
		exit(EXIT_FAILURE); //print error
	
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		exit (EXIT_FAILURE);
	i = 0;
	while (rays)
	{
		ray = (t_ray *)rays->content;
		draw_a_ray(ray, i, img);
		rays = rays->next;
		i++;
	}
	ft_lstclear(&rays, free);
	(void)data;
}

void	draw_a_ray(t_ray *ray, int col, void *img)
{
	int	start;
	int	end;
	uint32_t color;

	start = (HEIGHT - ray->wall_len) / 2;
	end = start + ray->wall_len;
	if (ray->wall_dir == N)
		color = NWALLCOL;
	else if (ray->wall_dir == S)
		color = SWALLCOL;
	else if (ray->wall_dir == E)
		color = EWALLCOL;
	else
		color = WWALLCOL;
	while (start < end)
	{
		mlx_put_pixel(img, col, start, color);
		start++;
	}
}

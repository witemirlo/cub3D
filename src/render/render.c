/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psacrist <psacrist@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:29:05 by psacrist          #+#    #+#             */
/*   Updated: 2024/07/22 17:13:47 by psacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	draw_a_ray(t_ray *ray, int col, void *img);

void	render(t_data *data, t_list *rays, void *mlx)
{
	t_ray		*ray;
	int			i;

	if (!data->scene)
	{
		data->scene = mlx_new_image(mlx, WIDTH, HEIGHT);
		if (!data->scene)
			exit(EXIT_FAILURE); //print error
	}
	if (mlx_image_to_window(mlx, data->scene, 0, 0) < 0)
		exit (EXIT_FAILURE);
	i = 0;
	while (rays)
	{
		ray = (t_ray *)rays->content;
		draw_a_ray(ray, i, data->scene);
		rays = rays->next;
		i++;
	}
}

void	draw_a_ray(t_ray *ray, int col, void *img)
{
	int	start;
	int	end;
	uint32_t color;
	int	i;

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
	color += (int)(0xFF * ray->wall_x) << 24;
	i = 0;
	while (i < start)
	{
		mlx_put_pixel(img, col, i, 0x16E3CDFF);
		i++;
	}
	while (start < end)
	{
		mlx_put_pixel(img, col, start, color);
		start++;
	}
	while (end < HEIGHT)
	{
		mlx_put_pixel(img, col, end, 0x7B5A12FF);
		end++;
	}
}

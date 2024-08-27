/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psacrist <psacrist@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:08:50 by jberdugo          #+#    #+#             */
/*   Updated: 2024/08/26 14:12:50 by psacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"
#include <errno.h>

static size_t	get_size(char const **map);
static void		set_vectors(t_data *data);

int	get_sprites(t_data *data)
{
	data->sprites_size = get_size((char const **)(data->map));
	if (data->sprites_size == 0)
		return (1);
	data->sprites = ft_calloc(data->sprites_size, sizeof(t_vector));
	if (errno == ENOMEM)
		return (0);
	set_vectors(data);
	return (1);
}

static size_t	get_size(char const **map)
{
	size_t	i;
	size_t	j;
	size_t	size;

	size = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'A')
				size++;
			j++;
		}
		i++;
	}
	return (size);
}

static void	set_vectors(t_data *data)
{
	size_t	i;
	size_t	j;
	size_t	tmp;

	i = 0;
	tmp = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'A')
			{
				data->map[i][j] = '0';
				data->sprites[tmp] = (t_vector){j + 0.5, i + 0.5};
				tmp++;
			}
			j++;
		}
		i++;
	}
}

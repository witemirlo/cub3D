/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:50:58 by jberdugo          #+#    #+#             */
/*   Updated: 2024/07/09 14:35:37 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "colors.h"
#include "parser.h"
#include <stdio.h>

static t_list	*get_key(t_list *file, char const *key);
static int		set_color(char const *data, int *status);

// TODO: setear que imprima error cuando esta mal
int	get_colors_map(t_list *file, t_texture_paths *texture_paths)
{
	t_list	*tmp;
	int		status;

	tmp = get_key(file, "F ");
	if (!tmp)
		return (0);
	texture_paths->floor = set_color((((char *)(tmp->content)) + 1), &status);
	if (status == -1)
		return (0);
	tmp = get_key(file, "C ");
	if (!tmp)
		return (0);
	texture_paths->ceiling = set_color((((char *)(tmp->content)) + 1), &status);
	if (status == -1)
		return (0);
	return (1);
}

static t_list	*get_key(t_list *file, char const *key)
{
	while (file)
	{
		if (ft_strncmp(file->content, key, ft_strlen(key)) == 0)
			return (file);
		file = file->next;
	}
	return (NULL);
}

static int	set_color(char const *data, int *status)
{
	int		i;
	int		color;
	int		color_tmp;
	char	**splited;
	char	*tmp;

	splited = ft_split(data, ',');
	if (!splited)
		return (perror(RED"Error"NC), *status = -1, 0);
	if (size_2d_array((char const **)splited) != 3)
		return (clear_2d_array(&splited), *status = -1, 0);
	i = 0;
	color = 0;
	while (splited[i])
	{
		tmp = ft_strtrim(splited[i++], " ");
		if (!strisnum(tmp))
			return (perror(RED"Error"NC), free(tmp),\
			clear_2d_array(&splited), *status = -1, 0);
		color_tmp = atoi(tmp);
		free(tmp);
		if (color_tmp > 255)
			return (clear_2d_array(&splited), *status = -1, 0);
		color = ((color << 8) | (0xFF & color_tmp));
	}
	return (*status = 0, clear_2d_array(&splited),  (color << 8) | 0xff);
}

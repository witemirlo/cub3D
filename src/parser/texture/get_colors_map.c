/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:50:58 by jberdugo          #+#    #+#             */
/*   Updated: 2024/07/09 16:06:12 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "colors.h"
#include "parser.h"
#include <stdio.h>

static t_list	*get_key(t_list *file, char const *key);
static int		set_color(char const *data, int *color);

// TODO: setear que imprima error cuando esta mal
int	get_colors_map(t_list *file, t_texture_paths *texture_paths)
{
	t_list	*tmp;
	int		errors;

	errors = 0;
	tmp = get_key(file, "F ");
	if (!tmp)
		return (0);
	if (!set_color((((char *)(tmp->content)) + 1), &texture_paths->floor))
		errors |= F_FLOOR;
	tmp = get_key(file, "C ");
	if (!tmp)
		return (0);
	if (!set_color((((char *)(tmp->content)) + 1), &texture_paths->ceiling))
		errors |= F_CEILING;
	if (errors)
	{
		ft_putendl_fd(RED"Error: "NC, 2);
		if ((errors & F_FLOOR) == F_FLOOR)
			ft_putendl_fd("Bad input at floor instruction", 2);
		if ((errors & F_CEILING) == F_CEILING)
			ft_putendl_fd("Bad input at ceiling instruction", 2);
		return (0);
	}
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

static int	set_color(char const *data, int *color)
{
	int		i;
	int		color_tmp;
	char	**splited;
	char	*tmp;

	splited = ft_split(data, ',');
	if (!splited)
		return (perror(RED"Error"NC), 0);
	if (size_2d_array((char const **)splited) != 3)
		return (clear_2d_array(&splited), 0);
	i = 0;
	while (splited[i])
	{
		tmp = ft_strtrim(splited[i++], " ");
		if (!strisnum(tmp))
			return (perror(RED"Error"NC), free(tmp), \
			clear_2d_array(&splited), 0);
		color_tmp = atoi(tmp);
		free(tmp);
		if (color_tmp > 255)
			return (clear_2d_array(&splited), 0);
		*color = ((*color << 8) | (0xFF & color_tmp));
	}
	*color = ((*color << 8) | 0xff);
	return (clear_2d_array(&splited), 1);
}

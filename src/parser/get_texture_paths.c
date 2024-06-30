/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_paths.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:12:32 by jberdugo          #+#    #+#             */
/*   Updated: 2024/06/30 15:49:31 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*get_path(t_list *list, char const *key);

/* Creates a struct with all the paths of the textures 
   (don't check if correct) */
t_texture_paths	*get_texture_paths(t_list *raw_file)
{
	// TODO: colors
	t_texture_paths	*textures;

	textures = malloc(sizeof(t_texture_paths));
	if (!textures)
		return (NULL);
	textures->north = get_path(raw_file, "NO");
	textures->south = get_path(raw_file, "SO");
	textures->east = get_path(raw_file, "EA");
	textures->west = get_path(raw_file, "WE");
	// textures->floor = get_path(raw_file, "F");
	// textures->ceiling = get_path(raw_file, "C");
	if (!textures->north || !textures->south || !textures->east
		|| !textures->west/*  || !textures->ceiling || !textures->floor */)
	{
		free(textures->north);
		free(textures->south);
		free(textures->east);
		free(textures->west);
		// free(textures->ceiling);
		// free(textures->floor);
		free(textures);
		return (NULL);
	}
	return (textures);
}

static char	*get_path(t_list *list, char const *key)
{
	char	*tmp;
	int		i;

	while (list)
	{
		if (ft_strnstr(list->content, key, ft_strlen(key)))
		{
			tmp = list->content;
			i = ft_strlen(key);
			while (tmp[i] == ' ')
				i++;
			tmp = ft_substr(tmp, i, ft_strlen(tmp + i));
			if (!tmp)
				return (NULL);
			if (tmp[ft_strlen(tmp) - 1] == '\n')
				tmp[ft_strlen(tmp) - 1] = '\0';
			return (tmp);
		}
		list = list->next;
	}
	return (NULL);
}

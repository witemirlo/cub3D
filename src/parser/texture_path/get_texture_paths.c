/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_paths.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:12:32 by jberdugo          #+#    #+#             */
/*   Updated: 2024/07/11 17:54:16 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

static char	*get_path(t_list *list, char const *key);
static void	clear_texture_paths(t_texture_paths **textures);

/* Creates a struct with all the paths of the textures 
   (don't check if correct) */
t_texture_paths	*get_texture_paths(t_list *raw_file)
{
	t_texture_paths	*textures;

	textures = ft_calloc(1, sizeof(t_texture_paths));
	if (!textures)
		return (NULL);
	textures->north = get_path(raw_file, "NO");
	textures->south = get_path(raw_file, "SO");
	textures->east = get_path(raw_file, "EA");
	textures->west = get_path(raw_file, "WE");
	if (!textures->north || !textures->south || !textures->east
		|| !textures->west)
	{
		clear_texture_paths(&textures);
		return (NULL);
	}
	if (!get_colors_map(raw_file, textures))
	{
		clear_texture_paths(&textures);
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
			while (tmp[i] == ' ' || tmp[i] == '\t' || tmp[i] == '\r')
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

static void	clear_texture_paths(t_texture_paths **textures)
{
	if (!textures)
		return ;
	free((*textures)->north);
	(*textures)->north = NULL;
	free((*textures)->south);
	(*textures)->south = NULL;
	free((*textures)->west);
	(*textures)->west = NULL;
	free((*textures)->east);
	(*textures)->east = NULL;
	free(*textures);
	*textures = NULL;
}

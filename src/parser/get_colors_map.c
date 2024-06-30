/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:50:58 by jberdugo          #+#    #+#             */
/*   Updated: 2024/06/30 16:04:24 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

static t_list	*get_key(t_list *file, char const *key);
static int		set_color(char const *raw_data);

int	get_colors_map(t_list *file, t_texture_paths *texture_paths)
{
	t_list	*tmp;

	tmp = get_key(file, "F ");
	texture_paths->floor = set_color(tmp->content);
	tmp = get_key(file, "C ");
	texture_paths->ceiling = set_color(tmp->content);

	return (1);
}

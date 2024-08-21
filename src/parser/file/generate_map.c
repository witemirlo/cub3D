/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:42:48 by jberdugo          #+#    #+#             */
/*   Updated: 2024/08/21 17:15:46 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

char	**generate_map(t_list *list_map)
{
	char	**array_map;
	char	*tmp;
	size_t	i;

	array_map = ft_calloc((ft_lstsize(list_map) + 1), sizeof(char **));
	if (!array_map)
		return (NULL);
	i = 0;
	while (list_map)
	{
		tmp = (char *)(list_map->content);
		while (*tmp && ft_strchr(MAP_VALID_CHARS, *tmp))
			tmp++;
		if (*tmp != '\0')
			break ;
		array_map[i] = ft_strdup((char *)(list_map->content));
		if (!array_map[i])
		{
			clear_2d_array(&array_map);
			return (NULL);
		}
		i++;
		list_map = list_map->next;
	}
	return (array_map);
}

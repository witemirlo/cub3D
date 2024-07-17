/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:17:02 by jberdugo          #+#    #+#             */
/*   Updated: 2024/07/17 18:46:53 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_list	*search_key(t_list *file, char const *key)
{
	char	*tmp;

	while (file)
	{
		tmp = (char *)(file->content);
		if (ft_strncmp(tmp, key, ft_strlen(key)) == 0)
		{
			if (tmp[ft_strlen(key)] && ft_isspace(tmp[ft_strlen(key)]))
				return (file);
		}
		file = file->next;
	}
	return (NULL);
}

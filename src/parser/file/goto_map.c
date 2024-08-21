/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:51:59 by jberdugo          #+#    #+#             */
/*   Updated: 2024/08/06 16:53:26 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*goto_map(t_list *raw_list)
{
	char	*tmp;

	while (raw_list)
	{
		tmp = (char *)(raw_list->content);
		if (ft_strlen(tmp) > 0)
		{
			while (*tmp != '\0' && ft_strchr(" 01NSEW", *tmp))
				tmp++;
			if (*tmp == '\0')
				break ;
		}
		raw_list = raw_list->next;
	}
	return (raw_list);
}

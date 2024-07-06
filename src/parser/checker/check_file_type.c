/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:09:03 by jberdugo          #+#    #+#             */
/*   Updated: 2024/07/06 16:26:33 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Returns 1 if name has corrext type */
int	check_file_type(char const *name)
{
	size_t	size;

	if (!name)
		return (ft_putendl_fd("Error\nBad file type", 2), 0);
	size = ft_strlen(name);
	if (size < 5)
		return (ft_putendl_fd("Error\nBad file type", 2), 0);
	if (name[size - 4] != '.'
		|| name[size - 3] != 'c'
		|| name[size - 2] != 'u'
		|| name[size - 1] != 'b')
		return (ft_putendl_fd("Error\nBad file type", 2), 0);
	return (1);
}

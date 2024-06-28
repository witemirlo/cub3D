/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:09:03 by jberdugo          #+#    #+#             */
/*   Updated: 2024/06/28 17:44:12 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Returns 1 if name has corrext type */
int	check_file_type(char const *name)
{
	char	*tmp;
	size_t	size;

	if (!name)
		return (ft_putendl_fd("Error\nBad file type", 2), 0);
	size = ft_strlen(name);
	if (size < 5)
		return (ft_putendl_fd("Error\nBad file type", 2), 0);
	tmp = ft_strnstr(name, ".cub", size);
	if (!tmp)
		return (ft_putendl_fd("Error\nBad file type", 2), 0);
	if (ft_strlen(tmp) != 4)
		return (ft_putendl_fd("Error\nBad file type", 2), 0);
	return (1);
}

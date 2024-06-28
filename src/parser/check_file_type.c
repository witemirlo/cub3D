/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:09:03 by jberdugo          #+#    #+#             */
/*   Updated: 2024/06/28 14:23:15 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Returns 1 if name has corrext type */
int	check_file_type(char const *name)
{
	char	*tmp;
	size_t	size;

	if (!name)
		return (0);
	size = ft_strlen(name);
	if (size < 5)
		return (0);
	tmp = ft_strnstr(name, ".cub", size);
	if (!tmp)
		return (0);
	if (ft_strlen(tmp) != 4)
		return (0);
	return (1);
}

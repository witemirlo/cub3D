/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_2d_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:11:13 by jberdugo          #+#    #+#             */
/*   Updated: 2024/07/01 16:28:51 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	size_2d_array(char const **array)
{
	size_t	size;

	if (!array)
		return (0);
	size = 0;
	while (array[size] != NULL)
		size++;
	return (size);
}

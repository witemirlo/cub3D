/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_2d_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:11:44 by jberdugo          #+#    #+#             */
/*   Updated: 2024/07/05 12:49:30 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	clear_2d_array(char ***array)
{
	size_t	i;

	if (!array)
		return ;
	i = 0;
	while ((*array)[i])
	{
		ft_bzero((*array)[i], ft_strlen((*array)[i]));
		free((*array)[i]);
		(*array)[i] = NULL;
		i++;
	}
	free(*array);
	*array = NULL;
}

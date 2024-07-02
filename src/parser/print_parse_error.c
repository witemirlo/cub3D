/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parse_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:39:11 by jberdugo          #+#    #+#             */
/*   Updated: 2024/06/28 16:17:15 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "colors.h"
#include "parser.h"

void	print_parse_error(t_check_flags flags)
{
	ft_putendl_fd(RED "Error" NC, 2);
	if ((flags & REPEATED_TEXTURE) == REPEATED_TEXTURE)
		ft_putendl_fd("There is a more than one path for a texture", 2);
	if ((flags & ALL_TEXTURES) != ALL_TEXTURES)
	{
		if ((flags & F_NORTH) != F_NORTH)
			ft_putendl_fd("There is no North path", 2);
		if ((flags & F_SOUTH) != F_SOUTH)
			ft_putendl_fd("There is no South path", 2);
		if ((flags & F_WEST) != F_WEST)
			ft_putendl_fd("There is no West path", 2);
		if ((flags & F_EAST) != F_EAST)
			ft_putendl_fd("There is no East path", 2);
		if ((flags & F_FLOOR) != F_FLOOR)
			ft_putendl_fd("There is no Floor path", 2);
		if ((flags & F_CEILING) != F_CEILING)
			ft_putendl_fd("There is no Ceiling path", 2);
	}
}

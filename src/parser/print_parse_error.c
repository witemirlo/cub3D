/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parse_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:39:11 by jberdugo          #+#    #+#             */
/*   Updated: 2024/07/04 15:13:10 by jberdugo         ###   ########.fr       */
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
	if ((flags & WRONG_DATA) == WRONG_DATA)
		ft_putendl_fd("There is wrong data in the file", 2);
	if ((flags & BAD_SITE_MAP) == BAD_SITE_MAP)
		ft_putendl_fd("The map is not at the end of the file", 2);
	if ((flags & NO_MAP) == NO_MAP)
		ft_putendl_fd("No correct map was found", 2);
	if ((flags & FORBIDDEN_MAP) == FORBIDDEN_MAP)
		ft_putendl_fd("The map has forbidden char", 2);
	if ((flags & MAP_NOT_CLOSED) == MAP_NOT_CLOSED)
		ft_putendl_fd("The map is not closed", 2);
	if ((flags & REPEATED_PLAYER) == REPEATED_PLAYER)
		ft_putendl_fd("There is more than one player", 2);
	if ((flags & NO_PLAYER) == NO_PLAYER)
		ft_putendl_fd("There is no player", 2);
}

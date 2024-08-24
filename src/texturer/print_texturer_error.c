/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_texturer_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:52:29 by jberdugo          #+#    #+#             */
/*   Updated: 2024/08/24 15:10:50 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_flags.h"
#include "texturer.h"
#include "colors.h"
#include "libft.h"

void	print_texturer_error(t_error_flags flags)
{
	ft_putendl_fd(RED"Error:"NC, 2);
	if ((flags & F_NORTH) == F_NORTH)
		ft_putendl_fd("Failed to load north texture", 2);
	if ((flags & F_SOUTH) == F_SOUTH)
		ft_putendl_fd("Failed to load south texture", 2);
	if ((flags & F_WEST) == F_WEST)
		ft_putendl_fd("Failed to load west texture", 2);
	if ((flags & F_EAST) == F_EAST)
		ft_putendl_fd("Failed to load east texture", 2);
	if ((flags & F_DOOR) == F_DOOR)
		ft_putendl_fd("Failed to load door texture", 2);
	if ((flags & F_SPRITE) == F_SPRITE)
		ft_putendl_fd("Failed to load sprite texture", 2);
	if ((flags & F_SPRITE_SIZE) == F_SPRITE_SIZE)
		ft_putendl_fd("The sprite sheet has incorrect format\n"\
		"Correct format: | sprite 1 | sprite 2 | sprite 3 | sprite 4 |", 2);
}

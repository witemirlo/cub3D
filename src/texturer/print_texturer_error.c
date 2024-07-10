/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_texturer_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:52:29 by jberdugo          #+#    #+#             */
/*   Updated: 2024/07/10 19:44:53 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if ((flags & SIZE_NORTH) == SIZE_NORTH)
		ft_putendl_fd("north texture is not a 128x128 tile", 2);
	if ((flags & SIZE_SOUTH) == SIZE_SOUTH)
		ft_putendl_fd("south texture is not a 128x128 tile", 2);
	if ((flags & SIZE_WEST) == SIZE_WEST)
		ft_putendl_fd("west texture is not a 128x128 tile", 2);
	if ((flags & SIZE_EAST) == SIZE_EAST)
		ft_putendl_fd("east texture is not a 128x128 tile", 2);
}

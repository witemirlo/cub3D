/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_key_values.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 13:03:18 by jberdugo          #+#    #+#             */
/*   Updated: 2024/06/30 13:14:45 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Function to set the key values for searching functions */
void	set_map_key_values(char mem[6][4])
{
	ft_memset(mem[0], 0, 4);
	ft_memset(mem[1], 0, 4);
	ft_memset(mem[2], 0, 4);
	ft_memset(mem[3], 0, 4);
	ft_memset(mem[4], 0, 4);
	ft_memset(mem[5], 0, 4);
	ft_memcpy(mem[0], "NO ", 3);
	ft_memcpy(mem[1], "SO ", 3);
	ft_memcpy(mem[2], "WE ", 3);
	ft_memcpy(mem[3], "EA ", 3);
	ft_memcpy(mem[4], "F ", 2);
	ft_memcpy(mem[5], "C ", 2);
}

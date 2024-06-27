/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:10:55 by jberdugo          #+#    #+#             */
/*   Updated: 2024/06/27 19:23:42 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"

/******************************************************************************/
typedef struct s_texture_path
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;
}	t_texture_path;

/******************************************************************************/
/**
 * mask cheatsheet:
 *   00000000 00000001 -> 0x1        -> NORTH
 *   00000000 00000010 -> 0x2        -> SOUTH
 *   00000000 00000100 -> 0x4        -> WEST
 *   00000000 00001000 -> 0x8        -> EAST
 *   00000000 00010000 -> 0x10       -> FLOOR
 *   00000000 00100000 -> 0x20       -> CEILING
 *  -------------------
 *   00000000 00111111 -> 0x3F       -> ALL_TEXTURES

 *   100...........000 -> 0x80000000 -> FAILURE
 */
typedef enum e_check_flags
{
	F_NORTH = 0x1,
	F_SOUTH = 0x2,
	F_WEST = 0x4,
	F_EAST = 0x8,
	F_FLOOR = 0x10,
	F_CEILING = 0x20,
	ALL_TEXTURES = 0x3F,
	FAILURE = 0x80000000,
	//SUCCESS = 
}	t_check_flags;

/******************************************************************************/
int				check_correct_file_type(char const *name);
t_list			*read_map(char const *name);
int				check_file_content(t_list *file);
t_texture_path	*get_texture_path(t_list *raw_file);

#endif
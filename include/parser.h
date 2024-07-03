/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:10:55 by jberdugo          #+#    #+#             */
/*   Updated: 2024/07/02 18:53:42 by jberdugo         ###   ########.fr       */
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
	int		floor;
	int		ceiling;
}	t_texture_paths;

typedef struct s_map_data
{
	t_texture_paths	*texture_paths;
	char			**map;
}	t_map_data;

/******************************************************************************/
/*
   mask cheatsheet:
     00000000 00000000 0000000 00000001 -> 0x1        -> NORTH
     00000000 00000000 0000000 00000010 -> 0x2        -> SOUTH
     00000000 00000000 0000000 00000100 -> 0x4        -> WEST
     00000000 00000000 0000000 00001000 -> 0x8        -> EAST
     00000000 00000000 0000000 00010000 -> 0x10       -> FLOOR
     00000000 00000000 0000000 00100000 -> 0x20       -> CEILING

     00000000 00000000 0000000 00111111 -> 0x3F       -> ALL_TEXTURES
     00000000 00000000 0000000 10000000 -> 0x80       -> REPEATED_TEXTURE

     00100000 00000000 0000000 00000000 -> 0x20000000 -> WRONG_DATA

     00001000 00000000 0000000 00000000 -> 0x4000000  -> NO_MAP 
     00010000 00000000 0000000 00000000 -> 0x10000000 -> BAD_SITE_MAP
     01000000 00000000 0000000 00000000 -> 0x40000000 -> FAILURE
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
	FAILURE = 0x40000000,
	WRONG_DATA = 0x20000000,
	BAD_SITE_MAP = 0x10000000,
	NO_MAP = 0x4000000,
	REPEATED_TEXTURE = 0X80,
}	t_check_flags;

/******************************************************************************/
int				parser(t_map_data *data, char const *file_name);

t_list			*read_file(char const *name);
void			close_file(t_list **file);

void			set_map_key_values(char mem[6][4]);
int				check_file_type(char const *name);
int				check_file_content(t_list *file);

t_texture_paths	*get_texture_paths(t_list *raw_file);

t_check_flags	check_correct_data(t_list *raw_list);
void			print_parse_error(t_check_flags flags);

#endif

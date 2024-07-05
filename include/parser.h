/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:10:55 by jberdugo          #+#    #+#             */
/*   Updated: 2024/07/05 12:39:29 by jberdugo         ###   ########.fr       */
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
     00000000 00000000 00000000 00000001 -> 0x1        -> NORTH
     00000000 00000000 00000000 00000010 -> 0x2        -> SOUTH
     00000000 00000000 00000000 00000100 -> 0x4        -> WEST
     00000000 00000000 00000000 00001000 -> 0x8        -> EAST
     00000000 00000000 00000000 00010000 -> 0x10       -> FLOOR
     00000000 00000000 00000000 00100000 -> 0x20       -> CEILING
     00000000 00000000 00000000 00111111 -> 0x3F       -> ALL_TEXTURES

	 01000000 00000000 00000000 00000000 -> 0x40000000 -> FAILURE
     00100000 00000000 00000000 00000000 -> 0x20000000 -> WRONG_DATA
     00010000 00000000 00000000 00000000 -> 0x10000000 -> BAD_SITE_MAP
     00001000 00000000 00000000 00000000 -> 0x4000000  -> NO_MAP 
	 00000000 00000000 00000000 10000000 -> 0x80       -> REPEATED_TEXTURE
     00000000 00000000 00000001 00000000 -> 0x100      -> FORBIDDEN_MAP
     00000000 00000000 00000010 00000000 -> 0x200      -> MAP_NOT_CLOSED
     00000000 00000000 00000100 00000000 -> 0x400      -> REPEADED_PLAYER
     00000000 00000000 00001000 00000000 -> 0x800      -> NO_PLAYER
     00000000 00000000 00010000 00000000 -> 0x1000     -> MAP_BREAK
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
	REPEATED_TEXTURE = 0X80,
	WRONG_DATA = 0x20000000,
	NO_MAP = 0x4000000,
	BAD_SITE_MAP = 0x10000000,
	FORBIDDEN_MAP = 0x100,
	MAP_NOT_CLOSED = 0x200,
	REPEATED_PLAYER = 0x400,
	NO_PLAYER = 0x800,
	MAP_BREAK = 0x1000,
}	t_check_flags;

/******************************************************************************/
int				parser(t_map_data *data, char const *file_name);

t_list			*read_file(char const *name);
void			close_file(t_list **file);

int				check_file_type(char const *name);
int				check_file_content(t_list *file);

t_texture_paths	*get_texture_paths(t_list *raw_file);
int				get_colors_map(t_list *file, t_texture_paths *texture_paths);
void			clear_texture_paths(t_texture_paths **textures);

t_check_flags	check_correct_data(t_list *raw_list);
t_check_flags	check_map(t_list *map);

void			print_parse_error(t_check_flags flags);
char		 	**generate_map(t_list *map);
t_list			*goto_map(t_list *raw_list);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:10:55 by jberdugo          #+#    #+#             */
/*   Updated: 2024/08/21 17:11:27 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"
# include "cub3d.h"
# include "error_flags.h"

# define MAP_VALID_CHARS " 01NSEW"

/******************************************************************************/
typedef struct s_texture_paths
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		floor;
	int		ceiling;
}	t_texture_paths;

/******************************************************************************/
int				parser(t_data *data, char *file_name);
void			clear_parser(t_data *data);

t_list			*read_file(char *name);
void			close_file(t_list **file);

int				check_file_type(char const *name);
int				check_file_content(t_list *file);

t_texture_paths	*get_texture_paths(t_list *raw_file);
int				get_colors_map(t_list *file, t_texture_paths *texture_paths);
t_player		get_player(char **map);

t_error_flags	check_correct_data(t_list *raw_list);
t_error_flags	check_map(t_list *map);
t_error_flags	check_map_closed(char **map);

void			print_parse_error(t_error_flags flags);
char			**generate_map(t_list *map);
t_list			*goto_map(t_list *raw_list);
t_list			*search_key(t_list *file, char const *key);

#endif

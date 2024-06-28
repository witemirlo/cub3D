/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:35:49 by jberdugo          #+#    #+#             */
/*   Updated: 2024/06/28 14:43:17 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include <stdio.h> // NOTE: debug
int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Please, enter a map\n");
		return (EXIT_FAILURE);
	}

	printf("check_file_type: %d\n", check_file_type(argv[1]));
	t_list *tmp = read_file(argv[1]);
	printf("check_file_content: %x\n", check_file_content(tmp));

	// t_texture_path *paths = get_texture_path(tmp);
	// printf("North: %s\nSouth: %s\nWest: %s\nEast: %s\nFloor: %s\nCeiling: %s\n", paths->north, paths->south, paths->west, paths->east, paths->floor, paths->ceiling);

	// printf("File readed:\n");
	// while (tmp) {
	// 	printf("%s", (char *)tmp->content);
	// 	tmp = tmp->next;
	// }
	return (0);
}

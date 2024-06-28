/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:35:49 by jberdugo          #+#    #+#             */
/*   Updated: 2024/06/28 16:59:12 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "colors.h"

#include <stdio.h> // NOTE: debug
int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		ft_putendl_fd(RED "Error" NC, 2);
		ft_putendl_fd("Too few arguments", 2);
		return (EXIT_FAILURE);
	}
	return (0);
}

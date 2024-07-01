/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strisnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:27:27 by jberdugo          #+#    #+#             */
/*   Updated: 2024/07/01 16:30:45 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	strisnum(char const *str)
{
	if (!str)
		return (0);
	if (*str == '-')
		str++;
	while (str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

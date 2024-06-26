/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_strjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:59:36 by jberdugo          #+#    #+#             */
/*   Updated: 2024/03/13 14:26:58 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	total_size(char **src);

/**
 * Gets a char ** (NULL terminated) and return a string with all its content
 */
char	*var_strjoin(char **src)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*new_string;

	new_string = (char *)malloc(sizeof(char) * (total_size(src) + 1));
	if (new_string == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (src[i] != NULL)
	{
		j = 0;
		while (src[i][j] != '\0')
		{
			new_string[k] = src[i][j];
			j++;
			k++;
		}
		i++;
	}
	new_string[k] = '\0';
	return (new_string);
}

static size_t	total_size(char **src)
{
	size_t	i;
	size_t	j;
	size_t	size;

	i = 0;
	size = 0;
	while (src[i] != NULL)
	{
		j = 0;
		while (src[i][j] != '\0')
			j++;
		size += j;
		i++;
	}
	return (size);
}

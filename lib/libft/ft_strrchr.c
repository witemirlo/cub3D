/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:59:15 by jberdugo          #+#    #+#             */
/*   Updated: 2024/02/01 14:03:01 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	letter;
	char	*ptr;
	int		i;

	if (!s)
		return (NULL);
	letter = (char) c;
	ptr = (char *)s;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (*(ptr + i) == letter)
			return (ptr + i);
		i--;
	}
	return (00);
}

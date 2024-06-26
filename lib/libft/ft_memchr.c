/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:37:03 by jberdugo          #+#    #+#             */
/*   Updated: 2023/09/14 15:10:41 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	letter;
	size_t			i;

	ptr = (unsigned char *) s;
	letter = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (*ptr == letter)
			return (ptr);
		ptr++;
		i++;
	}
	return (00);
}

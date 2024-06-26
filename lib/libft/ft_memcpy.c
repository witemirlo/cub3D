/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:39:45 by jberdugo          #+#    #+#             */
/*   Updated: 2023/09/25 19:10:45 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*ptrdst;
	const unsigned char	*ptrsrc;
	size_t				i;

	if (dst == NULL && src == NULL)
		return (NULL);
	ptrdst = dst;
	ptrsrc = src;
	i = 0;
	while (i < n)
	{
		ptrdst[i] = ptrsrc[i];
		i++;
	}
	return (ptrdst);
}

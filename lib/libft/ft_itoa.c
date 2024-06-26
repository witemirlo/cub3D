/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:16:27 by jberdugo          #+#    #+#             */
/*   Updated: 2023/09/27 15:47:59 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	total_len(int n)
{
	int	len;

	if (n == 0)
		len = 1;
	else
	{
		len = 0;
		if (n < 0)
			len++;
		while (n)
		{
			len++;
			n /= 10;
		}
	}
	return (len);
}

static void	put_str(char *str, int len, int n)
{
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		while (--len > 0)
		{
			str[len] = ((n % 10) * -1) + '0';
			n /= 10;
		}
	}
	else
	{
		while (--len >= 0)
		{
			str[len] = n % 10 + '0';
			n /= 10;
		}
	}
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = total_len(n);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	put_str(str, len, n);
	return (str);
}

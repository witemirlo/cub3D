/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:25:52 by jberdugo          #+#    #+#             */
/*   Updated: 2023/11/06 18:39:57 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		if (n == -2147483648)
		{
			write(fd, "2", 1);
			n = 147483648;
		}
		else
			n *= -1;
	}
	if (n < 10)
		write(fd, &(char){n + '0'}, 1);
	else
	{
		ft_putnbr_fd(n / 10, fd);
		write(fd, &(char){n % 10 + '0'}, 1);
	}
}

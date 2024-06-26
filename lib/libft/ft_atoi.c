/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:59:07 by jberdugo          #+#    #+#             */
/*   Updated: 2023/09/19 19:05:29 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	char	*ptr;
	int		total;
	int		sign;

	ptr = (char *) str;
	total = 0;
	sign = 1;
	while (*ptr == ' ' || *ptr == '\t' || *ptr == '\v'
		|| *ptr == '\r' || *ptr == '\n' || *ptr == '\f')
		ptr++;
	if (*ptr == '-' || *ptr == '+')
	{
		if (*ptr == '-')
			sign *= -1;
		ptr++;
	}
	while (*ptr >= '0' && *ptr <= '9')
	{
		total = total * 10 + (*ptr - '0');
		ptr++;
	}
	return (total * sign);
}

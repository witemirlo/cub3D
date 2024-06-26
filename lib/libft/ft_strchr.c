/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:43:44 by jberdugo          #+#    #+#             */
/*   Updated: 2023/09/14 15:10:27 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char			letter;
	unsigned int	i;

	letter = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == letter)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == letter)
		return ((char *)&s[i]);
	return (00);
}

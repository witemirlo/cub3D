/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:47:16 by jberdugo          #+#    #+#             */
/*   Updated: 2023/09/29 16:36:53 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	arr_len(char *s1, char *s2)
{
	size_t	len;

	len = 1;
	while (s1 != s2)
	{
		len++;
		s1++;
	}
	return (len);
}

static int	check_set(char const s1, char const *set)
{
	while (*set)
	{
		if (*set == s1)
			return (1);
		set++;
	}
	return (0);
}

static void	put_str(const char *s1, char *str, int i, int j)
{
	int	k;

	k = 0;
	while (&s1[i] != &s1[j])
	{
		str[k] = s1[i];
		i++;
		k++;
	}
	str[k] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	if (!*s1)
	{
		str = ft_calloc(1, 1);
		return (str);
	}
	i = 0;
	while (check_set(s1[i], set))
		i++;
	j = ft_strlen(s1);
	while (check_set(s1[j - 1], set) && &s1[i] < &s1[j])
		j--;
	len = arr_len((char *)(s1 + i), (char *)(s1 + j));
	str = malloc(sizeof(char) * (len));
	if (!str)
		return (str);
	put_str(s1, str, i, j);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:28:41 by jberdugo          #+#    #+#             */
/*   Updated: 2023/10/02 19:50:48 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

static int	strptr_len(char const *s, char c)
{
	int			strp_len;
	char const	*aux;

	while (*s == c && *s)
		s++;
	if (*s == '\0')
		return (0);
	aux = s + ft_strlen(s) - 1;
	while (*aux == c)
		aux--;
	strp_len = 0;
	while (s <= aux && *s)
	{
		if (*s != c)
		{
			strp_len++;
			while (*s != c && s <= aux && *s)
				s++;
		}
		else
			while (*s == c && s < aux && *s)
				s++;
	}
	return (strp_len);
}

static void	alocate_mem(char **str, int strp_len, char const *s, char c)
{
	char const	*aux;
	int			i;
	int			len;

	while (*s == c)
		s++;
	aux = s + ft_strlen(s) - 1;
	while (*aux == c)
		aux--;
	i = 0;
	while (s <= aux && i < strp_len && *s)
	{
		len = 0;
		while (*s == c && s < aux && *s)
			s++;
		while (*s != c && s <= aux && *s)
		{
			len++;
			s++;
		}
		*(str + i) = malloc(sizeof(char) * (len + 1));
		i++;
	}
}

static int	check_alocate(char **str, int strp_len)
{
	int	bad_malloc;
	int	i;

	bad_malloc = 0;
	i = 0;
	while (i < strp_len)
	{
		if (!str[i])
			bad_malloc = 1;
		i++;
	}
	if (bad_malloc)
	{
		while (i--)
			free(str[i]);
		return (0);
	}
	else
		return (1);
}

static void	put_str(char **str, int strp_len, char const *s, char c)
{
	char const	*aux;
	int			i;
	int			j;

	while (*s == c && *s)
		s++;
	aux = s + ft_strlen(s) - 1;
	while (*aux == c)
		aux--;
	i = 0;
	while (s <= aux && strp_len && *s)
	{
		while (*s == c && s < aux && *s)
			s++;
		j = 0;
		while (*s != c && s <= aux && *s)
		{
			str[i][j] = *s;
			j++;
			s++;
		}
		str[i][j] = '\0';
		i++;
		strp_len--;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		strp_len;

	strp_len = strptr_len(s, c);
	str = malloc(sizeof(char *) * (strp_len + 1));
	if (!str)
		return (NULL);
	*(str + strp_len) = NULL;
	if (strp_len == 0)
		return (str);
	alocate_mem(str, strp_len, s, c);
	if (!check_alocate(str, strp_len))
	{
		free(str);
		return (NULL);
	}
	put_str(str, strp_len, s, c);
	return (str);
}

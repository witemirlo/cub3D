/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 18:13:27 by jberdugo          #+#    #+#             */
/*   Updated: 2024/06/28 19:10:57 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	extract_texture_paths(t_list **new_list, t_list *raw_list);
static void	extract_map(t_list **new_list, t_list *raw_list);
static int	count_blank_lines(t_list *raw_list);

t_list	*extract_data(t_list *raw_list)
{
	t_list	*new_list;

	new_list = NULL;
	extract_texture_paths(&new_list, raw_list);
	extract_map(&new_list, raw_list);

	return (new_list);
}

static void	extract_texture_paths(t_list **new_list, t_list *raw_list)
{
	t_list	*tmp;
	char	str[6][4];
	int		i;

	ft_memcpy(str[0], "NO \0", 4);
	ft_memcpy(str[1], "SO \0", 4);
	ft_memcpy(str[2], "WE \0", 4);
	ft_memcpy(str[3], "EA \0", 4);
	ft_memcpy(str[4], "F \0", 3);
	ft_memcpy(str[5], "C \0", 3);
	i = 0;
	while (i < 6)
	{
		tmp = raw_list;
		while (tmp)
		{
			if (ft_strncmp(tmp->content, str[i], ft_strlen(str[i])) == 0)
			{
				ft_lstadd_back(new_list, ft_lstnew(ft_strdup(tmp->content)));// TODO: la gestion de errores
				break;
			}
			tmp = tmp->next;
		}
		i++;
	}
}

static void	extract_map(t_list **new_list, t_list *raw_list)
{
	char	*tmp;
	t_list	*node;

	while (raw_list)
	{
		tmp = (char *)(raw_list->content);
		if (ft_strlen(tmp) > 0)
		{
			while (*tmp != '\0' && (*tmp == ' ' || *tmp == '1'))
				tmp++;
			if (*tmp == '\0')
				break ;
		}
		raw_list = raw_list->next;
	}
	while (raw_list)
	{
		tmp = ft_strdup(raw_list->content);
		node = ft_lstnew(tmp);
		ft_lstadd_back(new_list, node);
		raw_list = raw_list->next;
	}
}

static int	count_blank_lines(t_list *raw_list)
{
	int	count;

	count = 0;
	while (raw_list)
	{
		if (raw_list->content == '\0')
			count++;
		raw_list = raw_list->next;
	}
	return (count);
}

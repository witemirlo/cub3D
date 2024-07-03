/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_correct_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 18:13:27 by jberdugo          #+#    #+#             */
/*   Updated: 2024/07/02 14:53:55 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

static int				extract_texture_paths(t_list **new_list, t_list *raw_list);
static t_check_flags	extract_map(t_list **new_list, t_list *raw_list);
static t_list			*goto_map(t_list *raw_list);
static int				count_blank_lines(t_list *raw_list);

t_check_flags	check_correct_data(t_list *raw_list)
{
	t_list			*new_list;
	t_check_flags	mask;

	new_list = NULL;
	mask = 0;
	extract_texture_paths(&new_list, raw_list);
	extract_map(&new_list, raw_list);
	if (ft_lstsize(new_list) + count_blank_lines(raw_list)
		!= ft_lstsize(raw_list))
		mask = (FAILURE | WRONG_DATA);
	ft_lstclear(&new_list, free);
	return (mask);
}

static int	extract_texture_paths(t_list **new_list, t_list *raw_list)
{
	const char	str[6][4] = {"NO ", "SO ", "WE ", "EA ", "F ", "C "};
	int			i;
	t_list		*p;
	t_list		*node;
	char		*content;

	i = 0;
	while (i++ < 6)
	{
		p = raw_list;
		while (p)
		{
			if (ft_strncmp(p->content, str[i - 1], ft_strlen(str[i - 1])) == 0)
			{
				content = ft_strdup(p->content);
				node = ft_lstnew(content);
				if (!node || !content)
					return (free(content), ft_lstclear(new_list, free), 0);
				ft_lstadd_back(new_list, node);
			}
			p = p->next;
		}
	}
	return (1);
}

static t_check_flags	extract_map(t_list **new_list, t_list *raw_list)
{
	char	*tmp;
	t_list	*node;

	raw_list = goto_map(raw_list);
	if (!raw_list)
		return (FAILURE | NO_MAP);
	while (raw_list)
	{
		tmp = (char *)(raw_list->content);
		while (*tmp != '\0')
		{
			if (!ft_strrchr(" 01NSEW", *tmp))
				return (FAILURE | BAD_SITE_MAP);
			tmp++;
		}
		tmp = ft_strdup(raw_list->content);
		node = ft_lstnew(tmp);
		ft_lstadd_back(new_list, node);
		raw_list = raw_list->next;
	}
	return (0);
}

static t_list	*goto_map(t_list *raw_list)
{
	char	*tmp;

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
	return (raw_list);
}

static int	count_blank_lines(t_list *raw_list)
{
	int	count;

	count = 0;
	while (raw_list)
	{
		if (*(char *)(raw_list->content) == '\0')
			count++;
		raw_list = raw_list->next;
	}
	return (count);
}

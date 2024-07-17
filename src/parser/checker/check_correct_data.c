/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_correct_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 18:13:27 by jberdugo          #+#    #+#             */
/*   Updated: 2024/07/17 18:53:19 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

static int				extract_texture_paths(t_list **n_list, t_list *o_list);
static t_error_flags	extract_map(t_list **new_list, t_list *o_list);
static void				count_blank_lines(t_list *o_list, int *blank_lines);

t_error_flags	check_correct_data(t_list *o_list)
{
	t_list			*new_list;
	t_error_flags	mask;
	int				blank_lines;

	new_list = NULL;
	mask = 0;
	blank_lines = 0;
	count_blank_lines(o_list, &blank_lines);
	extract_texture_paths(&new_list, o_list);
	extract_map(&new_list, o_list);
	if (ft_lstsize(new_list) + blank_lines
		!= ft_lstsize(o_list))
		mask = (FAILURE | WRONG_DATA);
	ft_lstclear(&new_list, free);
	return (mask);
}

static int	extract_texture_paths(t_list **n_list, t_list *o_list)
{
	const char	str[6][3] = {"NO", "SO", "WE", "EA", "F", "C"};
	int			i;
	t_list		*p;
	t_list		*node;
	char		*content;

	i = 0;
	while (i < 6)
	{
		p = search_key(o_list, str[i]);
		if (p)
		{
			content = ft_strdup(p->content);
			node = ft_lstnew(content);
			if (!node || !content)
				return (free(content), ft_lstclear(n_list, free), 0);
			ft_lstadd_back(n_list, node);
		}
		i++;
	}
	return (1);
}

static t_error_flags	extract_map(t_list **new_list, t_list *o_list)
{
	char	*tmp;
	t_list	*node;

	o_list = goto_map(o_list);
	if (!o_list)
		return (FAILURE | NO_MAP);
	while (o_list)
	{
		tmp = (char *)(o_list->content);
		while (*tmp != '\0')
		{
			if (!ft_strrchr(" 01NSEW", *tmp))
				return (FAILURE | BAD_SITE_MAP);
			tmp++;
		}
		tmp = ft_strdup(o_list->content);
		node = ft_lstnew(tmp);
		ft_lstadd_back(new_list, node);
		o_list = o_list->next;
	}
	return (0);
}

static void	count_blank_lines(t_list *o_list, int *blank_lines)
{
	const t_list	*start_map = goto_map(o_list);
	char			*tmp;

	while (o_list != start_map)
	{
		if (*(char *)(o_list->content) == '\0')
			*blank_lines = *blank_lines + 1;
		o_list = o_list->next;
	}
	while (o_list)
	{
		tmp = (char *)(o_list->content);
		while (*tmp && ft_strchr(" 01NSEW", *tmp))
			tmp++;
		if (*tmp != '\0')
			break ;
		o_list = o_list->next;
	}
	while (o_list)
	{
		if (*(char *)(o_list->content) == '\0')
			*blank_lines = *blank_lines + 1;
		o_list = o_list->next;
	}
}

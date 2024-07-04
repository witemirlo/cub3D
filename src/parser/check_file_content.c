/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:42:25 by jberdugo          #+#    #+#             */
/*   Updated: 2024/07/04 15:41:46 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

static t_check_flags	check_correct_order(t_list *file);
static t_check_flags	check_all_textures(t_list *file);
static t_check_flags	check_unique_textures(t_list *file);
static t_list			*goto_map(t_list *raw_list);

/* check if the file has correct FORMAT (map correctness is not checked) */
int	check_file_content(t_list *file)
{
	t_check_flags	mask;

	mask = 0;
	mask |= check_correct_order(file);
	mask |= check_all_textures(file);
	mask |= check_unique_textures(file);
	mask |= check_correct_data(file);
	mask |= check_map(file);
	if (mask != ALL_TEXTURES)
	{
		print_parse_error(mask);
		return (0);
	}
	return (1);
}

/* check that exits one instruction per required texture */
static t_check_flags	check_all_textures(t_list *file)
{
	char			*tmp;
	t_check_flags	mask;

	mask = 0;
	while (file)
	{
		tmp = (char *)(file->content);
		if (ft_strncmp(tmp, "NO ", 3) == 0)
			mask |= F_NORTH;
		else if (ft_strncmp(tmp, "SO ", 3) == 0)
			mask |= F_SOUTH;
		else if (ft_strncmp(tmp, "WE ", 3) == 0)
			mask |= F_WEST;
		else if (ft_strncmp(tmp, "EA ", 3) == 0)
			mask |= F_EAST;
		else if (ft_strncmp(tmp, "F ", 2) == 0)
			mask |= F_FLOOR;
		else if (ft_strncmp(tmp, "C ", 2) == 0)
			mask |= F_CEILING;
		file = file->next;
	}
	if ((mask & ALL_TEXTURES) != ALL_TEXTURES)
		mask |= FAILURE;
	return (mask);
}

/* check that only exists one instance of each texture instrucction */
static t_check_flags	check_unique_textures(t_list *file)
{
	const char	str[6][4] = {"NO ", "SO ", "WE ", "EA ", "F ", "C "};
	int			i;
	int			count;
	t_list		*tmp;

	i = 0;
	while (i < 6)
	{
		count = 0;
		tmp = file;
		while (tmp)
		{
			if (ft_strncmp(tmp->content, str[i], ft_strlen(str[i])) == 0)
				count++;
			tmp = tmp->next;
		}
		if (count > 1)
			return (REPEATED_TEXTURE);
		i++;
	}
	return (0);
}

static t_check_flags	check_correct_order(t_list *file)
{
	char	*tmp;

	file = goto_map(file);
	if (!file)
		return (FAILURE | NO_MAP);
	while (file)
	{
		tmp = (char *)(file->content);
		while(*tmp != '\0')
		{
			if (!ft_strrchr(" 01NSEW", *tmp))
				return (FAILURE | BAD_SITE_MAP);
			tmp++;
		}
		file = file->next;
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

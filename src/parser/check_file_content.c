/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberdugo <jberdugo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:42:25 by jberdugo          #+#    #+#             */
/*   Updated: 2024/07/03 13:15:27 by jberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

static t_check_flags	check_correct_order(t_list *file);
static t_check_flags	check_all_textures(t_list *file);
static t_check_flags	check_unique_textures(t_list *file);

/* check if the file has correct FORMAT (map correctness is not checked) */
int	check_file_content(t_list *file)
{
	t_check_flags	mask;

	mask = 0;
	mask |= check_correct_order(file);
	mask |= check_all_textures(file);
	mask |= check_unique_textures(file);
	if (mask != ALL_TEXTURES)
		print_parse_error(mask);
	return (mask == ALL_TEXTURES);
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
	t_check_flags	mask;
	char			*tmp;

	mask = FAILURE;
	while (file || mask != 0)
	{
		tmp = (char *)(file->content);
		if (ft_strlen(tmp) > 0)
		{
			while (*tmp != '\0' && (*tmp == ' ' || *tmp == '1'))
				tmp++;
			if (*tmp == '\0')
				mask = 0;
		}
		file = file->next;
	}
	while (file)
	{
		tmp = (char *)(file->content);
		if (!ft_strrchr(" 01NSEW", *tmp))
			mask = FAILURE;
		file = file->next;
	}
	return (mask);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjankows <fjankows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:09:54 by luimarti          #+#    #+#             */
/*   Updated: 2020/03/08 22:08:44 by fjankows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "fillit.h"

static int		check_chars(char *line)
{
	while (*line)
	{
		if (*line != '.' && *line != '#')
			exit_error(2);
		line++;
	}
	return (1);
}

static void		parse_line(char *line, t_tet *t, int counter)
{
	int	pos;

	pos = 0;
	while (pos < 4)
	{
		t->t[counter][pos] = (*line == '#') ? 1 : 0;
		pos++;
		line++;
	}
}

static void		skip_line(char *line)
{
	if (ft_strlen(line) != 0)
		exit_error(2);
}

static t_tet	*read_file(int fd)
{
	char		*line;
	int			line_cnt;
	t_tet		*first;
	t_tet		*current;

	line_cnt = 0;
	(first = (t_tet *)ft_memalloc(sizeof(t_tet))) ?
				current = first : exit_error(2);
	while (get_next_line(fd, &line) > 0)
	{
		if ((ft_strlen(line) != 4 && (line_cnt % 5) != 4) || !check_chars(line))
			exit_error(2);
		if ((line_cnt % 5) == 4)
		{
			skip_line(line);
			(current->next = (t_tet *)ft_memalloc(sizeof(t_tet))) ?
				current = current->next : exit_error(2);
		}
		else if ((line_cnt % 5) < 4)
			parse_line(line, current, (line_cnt) % 5);
		current->index = line_cnt++ / 5;
	}
	if ((line_cnt % 5) != 4)
		exit_error(2);
	return (first);
}

t_tet			*parse_data(char *file_name)
{
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit_error(2);
	return (read_file(fd));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luimarti <luimarti@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:09:54 by luimarti          #+#    #+#             */
/*   Updated: 2020/03/08 17:29:30 by luimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "fillit.h"

static int	check_chars(char *line)
{
	while (*line)
	{
		if (*line != '.' && *line != '#')
			exit_error(2);
		line++;
	}
	return (1);
}

static void	parse_line(char *line, t_tetris *t, int counter)
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

static void	skip_line(int fd, char *line)
{
	if (ft_strlen(line) != 0)
		exit_error(2);
}

static t_tetris	*read_file(int fd)
{
	char		*line;
	int			counter;
	t_tetris	*first;
	t_tetris	*current;

	counter = 0;
	(first = (t_tetris *)ft_memalloc(sizeof(t_tetris))) ?
				current = first : exit_error(2);
	while (get_next_line(fd, &line) > 0)
	{
		if ((ft_strlen(line) != 4 && counter != 4) || !check_chars(line))
			exit_error(2);
		if (counter == 4)
		{
			skip_line(fd, line);
			counter = 0;
			(current->next = (t_tetris *)ft_memalloc(sizeof(t_tetris))) ?
				current = current->next : exit_error(2);
		}
		else if (counter < 4)
			parse_line(line, current, counter++);
	}
	if (counter != 4)
		exit_error(2);
	return (first);
}

t_tetris	*parse_data(char *file_name)
{
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit_error(2);
	return (read_file(fd));
}

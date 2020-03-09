/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjankows <fjankows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:09:54 by luimarti          #+#    #+#             */
/*   Updated: 2020/03/09 02:24:11 by fjankows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "fillit.h"

static int		check_chars(char *l)
{
	while (*l)
	{
		if (*l != '.' && *l != '#')
			return (0);
		l++;
	}
	return (1);
}

static void		parse_l(char *l, t_tet *t, int counter)
{
	int	pos;

	pos = 0;
	while (pos < 4)
	{
		t->t[counter][pos] = (*l == '#') ? 1 : 0;
		pos++;
		l++;
	}
}

static t_tet	*read_file(int fd)
{
	char		*l;
	int			l_cnt;
	t_tet		*first;
	t_tet		*cur;

	l_cnt = 0;
	(first = (t_tet *)ft_memalloc(sizeof(t_tet))) ?
				cur = first : exit_error(2, NULL);
	while (get_next_line(fd, &l) > 0)
	{
		if ((ft_strlen(l) != 4 && (l_cnt % 5) != 4) || !check_chars(l))
			exit_error(2, first);
		if ((l_cnt % 5) == 4)
			(ft_strlen(l) == 0 && 
				(cur->next = (t_tet *)ft_memalloc(sizeof(t_tet)))) ?
				cur = cur->next : exit_error(2, first);
		else if ((l_cnt % 5) < 4)
			parse_l(l, cur, (l_cnt) % 5);
		cur->index = l_cnt++ / 5;
		free(l);
	}
	if ((l_cnt % 5) != 4)
		exit_error(2, first);
	return (first);
}

t_tet			*parse_data(char *file_name)
{
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit_error(2, NULL);
	return (read_file(fd));
}

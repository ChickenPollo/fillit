/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjankows <fjankows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 17:28:21 by luimarti          #+#    #+#             */
/*   Updated: 2020/03/09 02:16:57 by fjankows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

void		print_map(char map[][MAP_MAX], int map_dim)
{
	int i;
	int j;

	i = 0;
	while (i < map_dim)
	{
		j = 0;
		while (j < map_dim)
		{
			if (map[i][j])
				ft_putchar(map[i][j]);
			else
				ft_putchar('.');
			++j;
		}
		ft_putchar('\n');
		++i;
	}
}

void		free_list(t_tet *tmino)
{
	t_tet	*next;

	while (tmino)
	{
		next = tmino->next;
		free(tmino);
		tmino = next;
	}
}

void		exit_error(int i, t_tet *tmino)
{
	free_list(tmino);
	ft_putendl("error");
	exit(i);
}

void		exit_usage(void)
{
	ft_putendl("usage: ./fillit <filename>");
	exit(2);
}

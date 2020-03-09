/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjankows <fjankows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 21:40:14 by fjankows          #+#    #+#             */
/*   Updated: 2020/03/08 22:57:45 by fjankows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

static int	get_neighbours(char t[4][4], int i, int j)
{
	int neighbours;

	neighbours = 0;
	if ((i >= 1) && (t[i - 1][j]))
		neighbours += 1;
	if ((i <= 2) && (t[i + 1][j]))
		neighbours += 1;
	if ((j >= 1) && (t[i][j - 1]))
		neighbours += 1;
	if ((j <= 2) && (t[i][j + 1]))
		neighbours += 1;
	return (neighbours);
}

static int	check_neighbours(char t[4][4], int i, int j, int count)
{
	static int	total_neighbour;
	int			neighbours;

	if (count == 0)
		total_neighbour = 0;
	neighbours = get_neighbours(t, i, j);
	if (neighbours >= 1 && neighbours <= 3)
		total_neighbour += neighbours;
	else
		exit_error(7);
	if (count != 3)
		return (1);
	if (!(total_neighbour == 6 || total_neighbour == 8))
		return (0);
	return (1);
}

static void	check_tet_valid(t_tet *tmino)
{
	int i;
	int j;
	int count;

	count = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tmino->t[i][j])
			{
				if (!(check_neighbours(tmino->t, i, j, count)))
					exit_error(5);
				count++;
			}
			++j;
		}
		++i;
	}
	if (count != 4)
		exit_error(6);
	if (tmino->next)
		check_tet_valid(tmino->next);
}

int			main(int argc, char *argv[])
{
	int		i;
	t_tet	*tminos;

	if (argc != 2)
		exit_error(1);
	tminos = parse_data(argv[1]);
	cornerizer(tminos);
	check_tet_valid(tminos);
	i = 1;
	while (++i <= MAP_MAX)
	{
		if (prep_backtrack(i, tminos))
		{
			exit(0);
		}
	}
	exit_error(255);
}

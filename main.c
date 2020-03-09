/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luimarti <luimarti@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 21:40:14 by fjankows          #+#    #+#             */
/*   Updated: 2020/03/08 20:39:13 by luimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

#include <stdio.h>

static int	check_placement(int pos, t_tetris *tetrimino, char map[][MAP_MAX], int map_dim)
{
	int i;
	int j;
	int x;
	int y;

	x = pos / map_dim;
	y = pos % map_dim;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetrimino->t[i][j])
			{
				//printf("checking %d, pos %d\n, x:%d,y:%d\n", tetrimino->index, pos, y + j, x + i);
				if ((y + j >= map_dim) || (x + i >= map_dim)) // Map out of bounds
				{
					//printf("OOB for  %d, at pos %d , x:%d,y:%d\n", tetrimino->index, pos, y + j, x + i);
					return (0);
				}
				if ((map[x + i][y + j]) > 0) // collision with previous object
				{
					//printf("x:%d,y:%d contains: %d\n", x + i, y + j, map[x + i][y + j]);
					return (0);
				}
			}
			++j;
		}
		++i;
	}
	return (1);
}

static void	place_in_map(int map_dim, int pos, t_tetris *tetrimino, char map[][MAP_MAX])
{
	int i;
	int j;
	int x;
	int y;

	x = pos / map_dim;
	y = pos % map_dim;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetrimino->t[i][j])
				map[x + i][y + j] = ('A' + (char)tetrimino->index);
			++j;
		}
		++i;
	}
	//printf("placed %d, pos %d\n", tetrimino->index, pos);
}

static void	remove_from_map(int map_dim, int pos, t_tetris *tetrimino, char map[][MAP_MAX])
{
	int i;
	int j;
	int x;
	int y;

	x = pos / map_dim;
	y = pos % map_dim;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetrimino->t[i][j])
				if (map[x + i][y + j] != ('A' + (char)tetrimino->index))
					exit_error(3);
				map[x + i][y + j] = 0;
			++j;
		}
		++i;
	}
	//printf("REMOVED %d, pos %d\n", tetrimino->index, pos);
}

int			backtrack(int map_dim, t_tetris *tetrimino, char map[][MAP_MAX])
{
	int		pos;

	pos = 0;
	while (pos < (map_dim * map_dim))
	{
		//printf("bt pos: %d\n", pos);
		if (check_placement(pos, tetrimino, map, map_dim))
		{
			place_in_map(map_dim, pos, tetrimino, map);
			//print_map(map, map_dim);
			if (!tetrimino->next)
				return (1);
			if (backtrack(map_dim, tetrimino->next, map))
				return (1);
			remove_from_map(map_dim, pos, tetrimino, map);
		}
		pos++;
	}
	return (0);
}

int			prep_backtrack(int map_dim, t_tetris *tetriminos)
{
	int i;
	int j;
	char	map[map_dim][MAP_MAX];

	i = 0;
	while (i < map_dim)
	{
		j = 0;
		while (j < map_dim)
		{
			map[i][j] = 0;
			++j;
		}
		++i;
	}
	if (!backtrack(map_dim, tetriminos, map))
		return (0);

	print_map(map, map_dim);
	return (1);
}

int			main(int argc, char *argv[])
{
	int			i;
	t_tetris	*tetriminos;

	// check args
	if (argc != 2)
		exit_error(1);
	// parse file
	tetriminos = parse_data(argv[1]);
	cornerizer(tetriminos);
	// iterate map size
	i = 1;
	while (++i <= MAP_MAX)
	{
		if (prep_backtrack(i, tetriminos))
		{
			//printf ("success: %dx%d", i, i);
			exit (0);
		}
	}
	exit_error(255);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjankows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 21:40:14 by fjankows          #+#    #+#             */
/*   Updated: 2020/03/07 23:11:31 by fjankows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

static int check_placement(int x, int y, t_tetris tetrimino)

int	backtrack(int map_dim, t_tetris *tetriminos, map)
{
	int		pos;

	pos = 0;
	while (pos < map_dim * map_dim)
	{
		check_placement;
		// if error: continue
		// place in map
		if (!tetrimino)
			return 
		// recurse
		// if applicable: return success
		// else: remove 
	}
	return (NULL);
}

int	prep_backtrack(int map_dim, t_tetris *tetriminos)
{
	char	map[map_dim][map_dim];

	backtrack(map_dim, tetriminos, map);

	// print result
}

int	main(int argc, char argv[][])
{
	int			i;
	char 		*map;
	t_tetris	*tetriminos;

	// check args
	if (argc != 2)
		exit_error(1);
	// parse file
	tetriminions = fillit_parse(argv[1]);
	// iterate map size
	i = 1;
	while (++i <= MAP_MAX)
	{
		if (prep_backtrack(i, tetriminos))
			break ;
	}

	// print result
}

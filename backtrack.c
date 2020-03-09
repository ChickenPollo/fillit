/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjankows <fjankows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 22:05:39 by fjankows          #+#    #+#             */
/*   Updated: 2020/03/08 22:06:33 by fjankows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

static int	pos_avail(int pos, t_tet *tmino, char map[][MAP_MAX], int mapsz)
{
	int i;
	int j;
	int x;
	int y;

	x = pos / mapsz;
	y = pos % mapsz;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tmino->t[i][j])
			{
				if ((y + j >= mapsz) || (x + i >= mapsz))
					return (0);
				if ((map[x + i][y + j]) > 0)
					return (0);
			}
			++j;
		}
		++i;
	}
	return (1);
}

static void	place_in_map(int mapsz, int pos, t_tet *tmino, char map[][MAP_MAX])
{
	int i;
	int j;
	int x;
	int y;

	x = pos / mapsz;
	y = pos % mapsz;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tmino->t[i][j])
				map[x + i][y + j] = ('A' + (char)tmino->index);
			++j;
		}
		++i;
	}
}

static void	rm_from_map(int mapsz, int pos, t_tet *tmino, char map[][MAP_MAX])
{
	int i;
	int j;
	int x;
	int y;

	x = pos / mapsz;
	y = pos % mapsz;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tmino->t[i][j])
			{
				if (map[x + i][y + j] != ('A' + (char)tmino->index))
					exit_error(3);
				map[x + i][y + j] = 0;
			}
			++j;
		}
		++i;
	}
}

static int	backtrack(int mapsz, t_tet *tmino, char map[][MAP_MAX])
{
	int		pos;

	pos = 0;
	while (pos < (mapsz * mapsz))
	{
		if (pos_avail(pos, tmino, map, mapsz))
		{
			place_in_map(mapsz, pos, tmino, map);
			if (!tmino->next)
				return (1);
			if (backtrack(mapsz, tmino->next, map))
				return (1);
			rm_from_map(mapsz, pos, tmino, map);
		}
		pos++;
	}
	return (0);
}

int			prep_backtrack(int mapsz, t_tet *tminos)
{
	int		i;
	int		j;
	char	map[mapsz][MAP_MAX];

	i = 0;
	while (i < mapsz)
	{
		j = 0;
		while (j < mapsz)
		{
			map[i][j] = 0;
			++j;
		}
		++i;
	}
	if (!backtrack(mapsz, tminos, map))
		return (0);
	print_map(map, mapsz);
	return (1);
}

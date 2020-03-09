/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cornerizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luimarti <luimarti@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 17:49:41 by luimarti          #+#    #+#             */
/*   Updated: 2020/03/08 20:42:36 by luimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

static void	delete_row(t_tetris *tet)
{
	int	col;
	int	row;

	col = 0;
	while (col < 4)
	{
		row = 1;
		while (row < 4)
		{
			tet->t[row - 1][col] = tet->t[row][col];
			row++;
		}
		tet->t[3][col] = 0;
		col++;
	}
}

static void	delete_col(t_tetris *tet)
{
	int	col;
	int	row;

	row = 0;
	while (row < 4)
	{
		col = 1;
		while (col < 4)
		{
			tet->t[row][col - 1] = tet->t[row][col];
			col++;
		}
		tet->t[row][3] = 0;
		row++;
	}
}

static void	check_row(t_tetris *tet, int tries)
{
	int	col;
	int res;

	col = 0;
	res = 0;
	while (col < 4)
	{
		res += tet->t[0][col];
		col++;
	}
	if (res == 0 && tries < 3)
	{
		delete_row(tet);
		check_row(tet, tries + 1);
	}
}

static void	check_col(t_tetris *tet, int tries)
{
	int row;
	int res;

	row = 0;
	res = 0;
	while (row < 4)
	{
		res += tet->t[row][0];
		row++;
	}
	if (res == 0 && tries < 3)
	{
		delete_col(tet);
		check_col(tet, tries + 1);
	}
}

void		cornerizer(t_tetris *first)
{
	t_tetris	*tet;

	tet = first;
	while (tet)
	{
		check_row(tet, 0);
		check_col(tet, 0);
		tet = tet->next;
	}
}

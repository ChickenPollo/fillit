/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjankows <fjankows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 21:40:14 by fjankows          #+#    #+#             */
/*   Updated: 2020/03/08 22:05:53 by fjankows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

int			main(int argc, char *argv[])
{
	int		i;
	t_tet	*tminos;

	if (argc != 2)
		exit_error(1);
	tminos = parse_data(argv[1]);
	cornerizer(tminos);
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

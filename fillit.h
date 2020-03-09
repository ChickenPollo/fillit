/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjankows <fjankows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 21:49:44 by luimarti          #+#    #+#             */
/*   Updated: 2020/03/08 22:07:02 by fjankows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define MAP_MAX 64

typedef struct	s_tetris
{
	char			t[4][4];
	struct s_tetris	*next;
	unsigned int	index;
}				t_tet;

void			exit_error(int i);
void			print_map(char map[][MAP_MAX], int map_dim);

t_tet			*parse_data(char *file_name);
void			cornerizer(t_tet *first);
int				prep_backtrack(int mapsz, t_tet *tminos);

#endif

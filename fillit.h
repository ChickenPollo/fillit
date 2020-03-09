/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luimarti <luimarti@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 21:49:44 by luimarti          #+#    #+#             */
/*   Updated: 2020/03/08 20:35:33 by luimarti         ###   ########.fr       */
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
}				t_tetris;

void			exit_error(int i);
void			print_map(char map[][MAP_MAX], int map_dim);

t_tetris		*parse_data(char *file_name);
void			cornerizer(t_tetris *first);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luimarti <luimarti@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 21:49:44 by luimarti          #+#    #+#             */
/*   Updated: 2020/03/07 22:11:13 by luimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define MAP_MAX 16

typedef struct	s_tetris
{
	char			t[4][4];
	struct s_tetris	*next;
}				t_tetris;

void		exit_error(int i);
t_tetris	*parse_data(char *file_name);

#endif

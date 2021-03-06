/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjankows <fjankows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 15:43:48 by fjankows          #+#    #+#             */
/*   Updated: 2020/02/22 17:59:25 by fjankows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int len;

	if (!s)
		return ;
	len = ft_strlen(s);
	ft_memset((void *)s, 0, len + 1);
}

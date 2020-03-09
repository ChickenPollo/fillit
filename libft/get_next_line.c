/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjankows <fjankows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:27:48 by luimarti          #+#    #+#             */
/*   Updated: 2020/03/09 02:32:25 by fjankows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

#define BUFF_SIZE 32

static int        ft_get_line(const int fd, char **line, char **fds, int ret)
{
    char    *temp;
    int        len;

    len = 0;
    while (fds[fd][len] != '\n' && fds[fd][len] != '\0')
        len++;
    if (fds[fd][len] == '\n')
    {
        *line = ft_strsub(fds[fd], 0, len);
        temp = ft_strdup(fds[fd] + len + 1);
        free(fds[fd]);
        fds[fd] = temp;
        if (fds[fd][0] == '\0')
            ft_strdel(&fds[fd]);
    }
    else if (fds[fd][len] == '\0')
    {
        if (ret == BUFF_SIZE)
            return (get_next_line(fd, line));
        *line = ft_strdup(fds[fd]);
        ft_strdel(&fds[fd]);
    }
    return (1);
}

int                get_next_line(const int fd, char **line)
{
    static char        *fds[OPEN_MAX];
    char            buf[BUFF_SIZE + 1];
    int                ret;
    char            *temp;

    if (fd < 0 || line == NULL || fd >= OPEN_MAX)
        return (-1);
    while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
    {
        buf[ret] = '\0';
        if (fds[fd] == NULL)
            fds[fd] = ft_strnew(1);
        temp = ft_strjoin(fds[fd], buf);
        free(fds[fd]);
        fds[fd] = temp;
        if (ft_strchr(buf, '\n'))
            break ;
    }
    if (ret < 0)
        return (-1);
    else if (ret == 0 && (fds[fd] == NULL || fds[fd][0] == '\0'))
        return (0);
    return (ft_get_line(fd, line, fds, ret));
}

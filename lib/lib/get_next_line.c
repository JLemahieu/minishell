/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 14:19:12 by jlemahie          #+#    #+#             */
/*   Updated: 2018/03/27 21:00:15 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static	char	*ft_strjoinf(char **s1, char **s2, int del)
{
	char	*dest;

	dest = ft_strjoin(*s1, *s2);
	if (del == 1)
		ft_strdel(s1);
	else if (del == 2)
	{
		ft_strdel(s1);
		ft_strdel(s2);
	}
	return (dest);
}

static	char	*ft_reste(char *str)
{
	int	n;

	n = 0;
	while (str[n] != 0)
	{
		if (str[n] == '\n')
			return (ft_strdup(str + n + 1));
		n++;
	}
	return (NULL);
}

static	int		ft_lecture(int fd, char **reste, char **str)
{
	char	*buf;
	int		a;

	if (*reste != NULL)
		*str = ft_strjoinf(reste, str, 2);
	if ((*reste = ft_reste(*str)) != NULL)
		return (0);
	if (!(buf = ft_strnew(BUFFGNL_SIZE)))
		return (-1);
	while ((a = read(fd, buf, BUFFGNL_SIZE)) >= 0)
	{
		*str = ft_strjoinf(str, &buf, 1);
		if ((*reste = ft_reste(*str)) != NULL)
			break ;
		ft_bzero(buf, BUFFGNL_SIZE);
		if (a == 0)
			break ;
	}
	ft_strdel(&buf);
	if (a < 0)
		return (-1);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	char		*str;
	static char	*reste;
	int			x;
	int			a;

	x = 0;
	a = 0;
	if (!(str = ft_strnew(BUFFGNL_SIZE)))
		return (-1);
	if (ft_lecture(fd, &reste, &str) == -1)
		return (-1);
	while (str[x] != 0 && str[x] != '\n')
		x++;
	if (str[x] == '\n')
	{
		str[x] = 0;
		a = 1;
	}
	*line = ft_strdup(str);
	ft_strdel(&str);
	if (ft_strcmp(*line, "") != 0 || a == 1)
		return (1);
	return (0);
}

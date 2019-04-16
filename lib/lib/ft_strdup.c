/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 20:08:29 by jlemahie          #+#    #+#             */
/*   Updated: 2017/11/27 19:58:55 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;
	int		x;

	x = 0;
	i = ft_strlen(s);
	dest = (char*)malloc(sizeof(char) * i + 1);
	if (dest == NULL)
		return (dest);
	while (s[x] != 0)
	{
		dest[x] = s[x];
		x++;
	}
	dest[x] = 0;
	return (dest);
}

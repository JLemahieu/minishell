/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 04:55:35 by jlemahie          #+#    #+#             */
/*   Updated: 2018/05/19 03:06:13 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strndup(const char *s, int i)
{
	char	*dest;
	int		x;

	x = 0;
	dest = (char*)malloc(sizeof(char) * i + 1);
	if (dest == NULL)
		return (dest);
	while (s[x] != 0 && x < i)
	{
		dest[x] = s[x];
		x++;
	}
	dest[x] = 0;
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:26:56 by jlemahie          #+#    #+#             */
/*   Updated: 2017/11/16 13:53:51 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = n;
	while (dest[i] != 0)
		i++;
	while (src[x] != 0 && x < y)
	{
		dest[i] = src[x];
		i++;
		x++;
	}
	dest[i] = 0;
	return (dest);
}

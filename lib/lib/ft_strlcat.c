/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:01:31 by jlemahie          #+#    #+#             */
/*   Updated: 2017/11/29 18:52:39 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	while (dst[i] != 0 && i < size)
	{
		i++;
		l++;
	}
	if (size == 0)
		return (0 + ft_strlen(src));
	while (i < size - 1 && src[i - l] != 0)
	{
		dst[i] = src[i - l];
		i++;
	}
	if (l < size)
		dst[i] = 0;
	return (l + ft_strlen(src));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:11:13 by jlemahie          #+#    #+#             */
/*   Updated: 2017/11/16 13:54:37 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	int	i;
	int	x;

	i = 0;
	x = n;
	while (i < x && src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < x)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}

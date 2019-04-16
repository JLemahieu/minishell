/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:48:31 by jlemahie          #+#    #+#             */
/*   Updated: 2017/11/16 12:50:01 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (dest[i] != 0)
		i++;
	while (src[n] != 0)
	{
		dest[i] = src[n];
		i++;
		n++;
	}
	dest[i] = 0;
	return (dest);
}

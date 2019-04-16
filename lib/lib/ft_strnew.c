/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 18:47:47 by jlemahie          #+#    #+#             */
/*   Updated: 2017/11/28 17:51:46 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	int		i;
	int		x;

	x = size;
	i = 0;
	str = malloc(x * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	while (i < x + 1)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

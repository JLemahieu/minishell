/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 18:13:07 by jlemahie          #+#    #+#             */
/*   Updated: 2017/11/29 19:15:39 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ss1;
	const unsigned char	*ss2;
	int					i;
	int					x;

	ss1 = s1;
	ss2 = s2;
	i = 0;
	x = n;
	if (n == 0)
		return (0);
	while (ss1[i] == ss2[i] && i < x)
	{
		if (i + 1 == x)
			return (0);
		i++;
	}
	return (ss1[i] - ss2[i]);
}

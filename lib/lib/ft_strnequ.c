/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 10:05:50 by jlemahie          #+#    #+#             */
/*   Updated: 2017/11/27 10:20:57 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	i;
	int	p;

	i = 0;
	p = n;
	while (i < p && s1[i] == s2[i])
	{
		if ((s1[i] == 0 && s2[i] == 0) || (i == p - 1))
			return (1);
		i++;
	}
	return (0);
}
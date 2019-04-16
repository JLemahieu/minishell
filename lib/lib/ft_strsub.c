/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 10:26:32 by jlemahie          #+#    #+#             */
/*   Updated: 2017/11/27 20:52:40 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	int		n;
	char	*r;

	i = 0;
	n = len;
	r = malloc(n * sizeof(char) + 1);
	if (r == NULL)
		return (NULL);
	while (i < n)
	{
		r[i] = s[start];
		i++;
		start++;
	}
	r[i] = 0;
	return (r);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:41:52 by jlemahie          #+#    #+#             */
/*   Updated: 2017/11/16 14:58:11 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		x;
	int		y;
	char	*ret;

	i = 0;
	ret = NULL;
	if (needle[0] == 0)
		return ((char*)&haystack[0]);
	while (haystack[i] != 0)
	{
		y = i;
		x = 0;
		while (haystack[y] == needle[x])
		{
			if (needle[x + 1] == 0)
				return ((char*)&haystack[i]);
			y++;
			x++;
		}
		i++;
	}
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 10:58:00 by jlemahie          #+#    #+#             */
/*   Updated: 2017/11/29 19:13:46 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strtrim(char const *s)
{
	int			i;
	int			l;
	char		*r;

	i = 0;
	if (s == NULL)
		return (NULL);
	l = ft_strlen(s);
	while ((s[l - 1] == ' ' || s[l - 1] == '\n' || s[l - 1] == '\t') && l > 0)
		l--;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		l--;
		i++;
	}
	l = (l <= 0 ? 0 : l);
	if ((r = (char*)malloc((l + 1) * sizeof(char))) == NULL)
		return (NULL);
	s = s + i;
	i = -1;
	while (++i < l)
		r[i] = *s++;
	r[i] = 0;
	return (r);
}

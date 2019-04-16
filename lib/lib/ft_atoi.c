/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:00:14 by jlemahie          #+#    #+#             */
/*   Updated: 2017/11/28 18:25:25 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_atoi(const char *nptr)
{
	int i;
	int result;
	int neg;

	i = 0;
	result = 0;
	neg = 1;
	while (nptr[i] == '\v' || nptr[i] == '\t' || nptr[i] == '\n' ||
			nptr[i] == '\r' || nptr[i] == '\f' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	if (nptr[i] < '0' || nptr[i] > '9')
		return (0);
	while (nptr[i] != 0 && nptr[i] > 47 && nptr[i] < 58)
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * neg);
}

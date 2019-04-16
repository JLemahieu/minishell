/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:01:27 by jlemahie          #+#    #+#             */
/*   Updated: 2017/11/28 17:19:58 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static char	*ft_putnbri(int i, int n, int neg, char *nbr)
{
	while (i >= 0)
	{
		nbr[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	if (neg == 1)
		nbr[0] = '-';
	return (nbr);
}

char		*ft_itoa(int n)
{
	char	*nbr;
	int		i;
	int		neg;

	neg = 0;
	if (n < 0)
		neg = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	i = ft_nbrlen(n);
	if ((nbr = (char *)malloc(sizeof(char) * i + 1)) == NULL)
		return (NULL);
	nbr[i] = 0;
	i--;
	if (n < 0)
		n = -n;
	nbr = ft_putnbri(i, n, neg, nbr);
	return (nbr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 06:35:30 by jlemahie          #+#    #+#             */
/*   Updated: 2018/05/25 04:11:45 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_wnstrl(wchar_t *str, int n)
{
	int	i;
	int size;

	i = 0;
	size = 0;
	while (size < n && str[i] != 0)
	{
		size = size + ft_wcharlen(str[i]);
		if (size > n)
			return (size - ft_wcharlen(str[i]));
		i++;
	}
	return (size);
}

int	ft_putnwstrb(t_flagpf *flags, wchar_t *str, int n)
{
	int	i;
	int size;
	int o;

	i = 0;
	size = 0;
	o = ft_wnstrl(str, n);
	while (o < n)
	{
		ft_putcharb(flags, ' ');
		o++;
	}
	o--;
	while (size < n && str[i] != 0)
	{
		size = size + ft_wcharlen(str[i]);
		if (size <= n)
			ft_putwcharb(flags, str[i]);
		else
			return (n);
		i++;
	}
	return (n);
}

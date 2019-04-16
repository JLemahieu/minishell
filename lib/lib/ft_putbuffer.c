/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbuffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 09:47:53 by jlemahie          #+#    #+#             */
/*   Updated: 2018/05/27 01:37:55 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/includepf.h"

void	ft_putcharb(t_flagpf *flags, char c)
{
	if (flags->i == BUFFPF_MAX)
		ft_putbuff(flags, flags->i);
	flags->buff[flags->i] = c;
	flags->i++;
}

void	ft_putstrb(t_flagpf *flags, const char *str)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(str);
	if (size + flags->i > BUFFPF_MAX)
		ft_putbuff(flags, flags->i);
	while (str[i] != 0)
	{
		flags->buff[flags->i] = str[i];
		flags->i++;
		i++;
	}
}

int		ft_putnstrb(t_flagpf *flags, const char *str, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (str[i] != 0 && i != n)
	{
		ft_putcharb(flags, str[i]);
		i++;
	}
	return (i);
}

void	ft_putnbrb(t_flagpf *flags, int n)
{
	if (n == -2147483648)
		ft_putstrb(flags, "-2147483648");
	if (n < 0 && n > -2147483648)
	{
		ft_putcharb(flags, '-');
		n = -n;
	}
	if (n >= 0 && n <= 9)
		ft_putcharb(flags, n + '0');
	if (n > 9)
	{
		ft_putnbrb(flags, n / 10);
		ft_putnbrb(flags, n % 10);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 03:13:17 by jlemahie          #+#    #+#             */
/*   Updated: 2018/05/27 02:06:45 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/includepf.h"
#include "../../include/libft.h"

void		ft_nbr(intmax_t n, t_flagpf *flags)
{
	if (n >= 0 && flags->indic.sign == 1)
		ft_putcharb(flags, '+');
	else if (n >= 0 && flags->indic.space == 1)
		ft_putcharb(flags, ' ');
	else if (n < 0)
		ft_putcharb(flags, '-');
}

int			ft_nbrllen(intmax_t n)
{
	int			l;

	l = 1;
	if (n < 0)
	{
		n = -n;
		l++;
	}
	while (n > 9)
	{
		n = n / 10;
		l++;
	}
	return (l);
}

static	int	ft_elsupp(t_flagpf *flags, int i, intmax_t n, int preci)
{
	if (flags->preci == -1)
	{
		ft_nbr(n, flags);
		i = ft_fill(i, flags->large - preci, flags->indic.zero, flags);
	}
	else
	{
		i = ft_fill(i, flags->large - preci, ' ', flags);
		ft_nbr(n, flags);
	}
	return (i);
}

static	int	ft_suppd(t_flagpf *flags, int i, int size, intmax_t n)
{
	int	preci;

	flags->indic.diese = 0;
	if (n < 0 || (flags->indic.space == 1 || flags->indic.sign == 1))
		flags->indic.diese = 1;
	if (n == 0 && flags->preci == 0)
		preci = 0;
	else
		preci = size;
	if (size - flags->indic.diese < flags->preci)
		preci = flags->preci + flags->indic.diese;
	if (flags->indic.left == 0 && flags->indic.zero == ' ')
	{
		i = ft_fill(i, flags->large - preci, flags->indic.zero, flags);
		ft_nbr(n, flags);
	}
	else if (flags->indic.left == 0 && flags->indic.zero == '0')
		i = i + ft_elsupp(flags, i, n, preci);
	else
		ft_nbr(n, flags);
	return (i);
}

int			ft_print_d(va_list *args, t_flagpf *flags)
{
	int			i;
	intmax_t	n;
	int			o;
	int			size;

	i = 0;
	o = 0;
	n = ft_taillnbr(args, flags);
	size = ft_nbrllen(n);
	if (n >= 0 && (flags->indic.space == 1 || flags->indic.sign == 1))
		size++;
	i = i + ft_suppd(flags, i, size, n);
	while (o + (size - flags->indic.diese) < flags->preci)
	{
		ft_putcharb(flags, '0');
		o++;
		i++;
	}
	if (n == 0 && flags->preci == 0)
		i = i + 1 - 1;
	else
		i = i + ft_putnstrb(flags, ft_putnbru(n), ft_strlen(ft_putnbru(n)));
	if (flags->indic.left == 1)
		i = ft_fill(i, flags->large - flags->indic.diese, ' ', flags);
	return (i + flags->indic.diese);
}

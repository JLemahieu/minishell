/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_oct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 02:59:56 by jlemahie          #+#    #+#             */
/*   Updated: 2018/05/27 02:00:03 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/includepf.h"
#include "../../include/libft.h"

static	int	ft_suppo(t_flagpf *flags, int i, int size, char c)
{
	int	preci;
	int	o;

	o = 0;
	if (flags->preci != -1)
		flags->indic.zero = ' ';
	if (flags->preci > size)
		preci = flags->preci;
	else
		preci = size;
	if (flags->indic.diese == 1 && flags->indic.zero == '0' && c != '0')
		i = i + ft_putnstrb(flags, "0", 1);
	if (flags->indic.left == 0)
		i = i + ft_fill(0, flags->large - preci, flags->indic.zero, flags);
	if (flags->indic.diese == 1 && flags->indic.zero == ' ' && c != '0')
		i = i + ft_putnstrb(flags, "0", 1);
	while (o + size < flags->preci)
	{
		ft_putcharb(flags, '0');
		o++;
		i++;
	}
	return (i);
}

int			ft_print_o(va_list *args, t_flagpf *flags)
{
	int			i;
	char		*str;
	int			size;
	uintmax_t	n;

	i = 0;
	n = ft_taillnbru(args, flags);
	str = ft_itoabase(n, "01234567");
	if (str[0] == '0' && flags->preci == 0)
		str = "";
	if (str[0] == '0')
		size = 1;
	else
		size = ft_strlen(str) + (flags->indic.diese);
	i = i + ft_suppo(flags, i, size, str[0]);
	i = i + ft_putnstrb(flags, str, ft_strlen(str));
	i = flags->indic.left ? ft_fill(i, flags->large, ' ', flags) : i;
	return (i);
}

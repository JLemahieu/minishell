/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 06:26:03 by jlemahie          #+#    #+#             */
/*   Updated: 2018/05/25 05:38:06 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/includepf.h"
#include "../../include/libft.h"

static	int	ft_suppu(t_flagpf *flags, int i, int size)
{
	int	preci;

	if (flags->preci > size)
		preci = flags->preci;
	else
		preci = size;
	if (flags->indic.left == 0)
	{
		if (flags->preci == -1)
			i = i + ft_fill(0, flags->large - preci, flags->indic.zero, flags);
		else
			i = i + ft_fill(0, flags->large - preci, ' ', flags);
	}
	return (i);
}

int			ft_print_u(va_list *args, t_flagpf *flags)
{
	int			i;
	char		*str;
	int			size;
	uintmax_t	n;
	int			o;

	i = 0;
	o = 0;
	n = ft_taillnbru(args, flags);
	str = ft_itoabase(n, "0123456789");
	if (str[0] == '0' && flags->preci == 0)
		str = "";
	size = ft_strlen(str);
	i = i + ft_suppu(flags, i, size);
	while (o + size < flags->preci)
	{
		ft_putcharb(flags, '0');
		o++;
		i++;
	}
	i = i + ft_putnstrb(flags, str, ft_strlen(str));
	i = flags->indic.left ? ft_fill(i, flags->large, ' ', flags) : i;
	return (i);
}

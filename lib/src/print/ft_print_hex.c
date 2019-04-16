/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 23:52:31 by jlemahie          #+#    #+#             */
/*   Updated: 2018/05/27 01:58:07 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/includepf.h"
#include "../../include/libft.h"

static	int	ft_suppx(t_flagpf *flags, int i, int size, char c)
{
	int	preci;
	int	o;

	o = 0;
	if (flags->preci != -1)
		flags->indic.zero = ' ';
	if (flags->preci > size)
		preci = flags->preci + (flags->indic.diese * 2);
	else
		preci = size + (flags->indic.diese * 2);
	if ((flags->indic.diese == 1 && flags->indic.zero == '0' && c != 0\
			&& c != '0') || (flags->ptr == 1 && flags->indic.zero == '0'))
		i = i + ft_putnstrb(flags, "0x", 2);
	if (flags->indic.left == 0)
		i = i + ft_fill(0, flags->large - preci, flags->indic.zero, flags);
	if ((flags->indic.diese == 1 && flags->indic.zero == ' ' && c != 0\
			&& c != '0') || (flags->ptr == 1 && flags->indic.zero == ' '))
		i = i + ft_putnstrb(flags, "0x", 2);
	while (o + size < flags->preci)
	{
		ft_putcharb(flags, '0');
		o++;
		i++;
	}
	return (i);
}

int			ft_print_x(va_list *args, t_flagpf *flags)
{
	int			i;
	char		*str;
	int			size;
	uintmax_t	n;

	i = 0;
	n = ft_taillnbru(args, flags);
	str = ft_itoabase(n, "0123456789abcdef");
	if (str[0] == '0' && flags->preci == 0)
	{
		flags->indic.diese = 0;
		str = "";
	}
	if (str[0] == '0')
	{
		flags->indic.diese = flags->ptr ? 1 : 0;
		size = 1;
	}
	else
		size = ft_strlen(str);
	i = i + ft_suppx(flags, i, size, str[0]);
	i = i + ft_putnstrb(flags, str, ft_strlen(str));
	i = flags->indic.left ? ft_fill(i, flags->large, ' ', flags) : i;
	return (i);
}

static	int	ft_suppxx(t_flagpf *flags, int i, int size, char c)
{
	int	preci;
	int o;

	o = 0;
	if (flags->preci != -1)
		flags->indic.zero = ' ';
	if (flags->preci > size)
		preci = flags->preci + (flags->indic.diese * 2);
	else
		preci = size + (flags->indic.diese * 2);
	if (flags->indic.diese == 1 && flags->indic.zero == '0' && c != 0\
			&& c != '0')
		i = i + ft_putnstrb(flags, "0X", 2);
	if (flags->indic.left == 0)
		i = i + ft_fill(0, flags->large - preci, flags->indic.zero, flags);
	if (flags->indic.diese == 1 && flags->indic.zero == ' ' && c != 0\
			&& c != '0')
		i = i + ft_putnstrb(flags, "0X", 2);
	while (o + size < flags->preci)
	{
		ft_putcharb(flags, '0');
		i++;
		o++;
	}
	return (i);
}

int			ft_print_xx(va_list *args, t_flagpf *flags)
{
	int			i;
	char		*str;
	int			size;
	uintmax_t	n;

	i = 0;
	n = ft_taillnbru(args, flags);
	str = ft_itoabase(n, "0123456789ABCDEF");
	if (str[0] == '0' && flags->preci == 0)
	{
		flags->indic.diese = 0;
		str = "";
	}
	if (str[0] == '0')
	{
		flags->indic.diese = 0;
		size = 1;
	}
	else
		size = ft_strlen(str);
	i = i + ft_suppxx(flags, i, size, str[0]);
	i = i + ft_putnstrb(flags, str, ft_strlen(str));
	i = flags->indic.left ? ft_fill(i, flags->large, ' ', flags) : i;
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 23:49:52 by jlemahie          #+#    #+#             */
/*   Updated: 2018/05/27 01:51:50 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/includepf.h"
#include "../../include/print.h"
#include "../../include/libft.h"

int	ft_print_cc(va_list *args, t_flagpf *flags)
{
	int		i;
	wchar_t	c;
	int		size;

	if (flags->taille == 'h')
		return (ft_print_c(args, flags));
	c = (wchar_t)va_arg(*args, wchar_t);
	i = 0;
	size = ft_wcharlen(c);
	if (size == -1 && (c > 255 || c < 0))
		return (-1);
	if (flags->indic.left == 0)
		i = ft_fill(i, flags->large - size, flags->indic.zero, flags);
	ft_putwcharb(flags, c);
	if (flags->indic.left == 1)
		i = ft_fill(i, flags->large - size, ' ', flags);
	return (i + size);
}

int	ft_print_c(va_list *args, t_flagpf *flags)
{
	int i;

	if (flags->taille == 'l')
		return (ft_print_cc(args, flags));
	i = 0;
	if (flags->indic.left == 0)
		i = ft_fill(i, flags->large - 1, flags->indic.zero, flags);
	ft_putcharb(flags, (int)va_arg(*args, int));
	if (flags->indic.left == 1)
		i = ft_fill(i, flags->large - 1, ' ', flags);
	return (i + 1);
}

int	ft_print_perc(va_list *args, t_flagpf *flags)
{
	int i;

	i = 0;
	if (flags->indic.left == 0)
		i = ft_fill(i, flags->large - 1, flags->indic.zero, flags);
	ft_putcharb(flags, '%');
	if (flags->indic.left == 1)
		i = ft_fill(i, flags->large - 1, ' ', flags);
	if (i == -1)
		va_arg(*args, int);
	return (i + 1);
}

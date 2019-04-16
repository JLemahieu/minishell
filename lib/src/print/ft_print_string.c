/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 23:49:42 by jlemahie          #+#    #+#             */
/*   Updated: 2018/09/19 14:48:56 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/includepf.h"
#include "../../include/print.h"
#include "../../include/libft.h"

int	ft_print_s(va_list *args, t_flagpf *flags)
{
	int		i;
	char	*str;
	int		size;

	if (flags->taille == 'l')
		return (ft_print_ss(args, flags));
	i = 0;
	str = va_arg(*args, char*);
	if (str == NULL)
		str = "(null)";
	size = ft_strlen(str);
	if (size > flags->preci && flags->preci != -1)
		size = flags->preci;
	if (flags->indic.left == 0)
		i = ft_fill(i, flags->large - size, flags->indic.zero, flags);
	i = i + ft_putnstrb(flags, str, size);
	if (flags->indic.left == 1)
		i = ft_fill(i, flags->large, ' ', flags);
	return (i);
}

int	ft_print_ss(va_list *args, t_flagpf *flags)
{
	int		i;
	wchar_t	*str;
	int		size;

	if (flags->taille == 'h')
		return (ft_print_s(args, flags));
	i = 0;
	str = va_arg(*args, wchar_t*);
	if (str == NULL)
		str = L"(null)";
	size = ft_wstrlen(str, flags);
	if (size == -1)
		return (-1);
	size = ft_wnstrl(str, size);
	if (flags->indic.left == 0)
		i = ft_fill(0, flags->large - size, flags->indic.zero, flags);
	i = i + ft_putnwstrb(flags, str, size);
	if (flags->indic.left == 1)
		i = ft_fill(i, flags->large, ' ', flags);
	return (i);
}

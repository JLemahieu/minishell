/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_inv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 01:34:12 by jlemahie          #+#    #+#             */
/*   Updated: 2018/05/25 04:14:53 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/includepf.h"
#include "../../include/libft.h"

int	ft_print_inv(va_list *args, t_flagpf *flags)
{
	int i;

	i = 0;
	if (flags->indic.left == 0)
		i = ft_fill(i, flags->large - 1, flags->indic.zero, flags);
	ft_putcharb(flags, flags->ptr);
	if (flags->indic.left == 1)
		i = ft_fill(i, flags->large - 1, ' ', flags);
	if (i == -1)
		va_arg(*args, int);
	return (i + 1);
}

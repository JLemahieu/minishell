/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 03:42:51 by jlemahie          #+#    #+#             */
/*   Updated: 2018/05/24 07:11:27 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/includepf.h"
#include "../../include/print.h"
#include "../../include/libft.h"

int	ft_print_oo(va_list *args, t_flagpf *flags)
{
	flags->taille = 'l';
	return (ft_print_o(args, flags));
}

int	ft_print_uu(va_list *args, t_flagpf *flags)
{
	flags->taille = 'l';
	return (ft_print_u(args, flags));
}

int	ft_print_dd(va_list *args, t_flagpf *flags)
{
	flags->taille = 'l';
	return (ft_print_d(args, flags));
}

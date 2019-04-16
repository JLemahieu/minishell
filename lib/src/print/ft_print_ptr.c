/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 04:25:04 by jlemahie          #+#    #+#             */
/*   Updated: 2018/05/24 07:10:18 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/includepf.h"
#include "../../include/print.h"
#include "../../include/libft.h"

int	ft_print_p(va_list *args, t_flagpf *flags)
{
	flags->indic.diese = 1;
	flags->taille = 'z';
	flags->ptr = 1;
	return (ft_print_x(args, flags));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 22:02:41 by jlemahie          #+#    #+#             */
/*   Updated: 2018/05/25 05:14:01 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includepf.h"
#include "../include/libft.h"

int			ft_patoi(char *str)
{
	int	ret;

	ret = ft_atoi(str);
	free(str);
	return (ret);
}

void		ft_set_flags(t_flagpf *flags)
{
	flags->large = 0;
	flags->preci = -1;
	flags->taille = 0;
	flags->flag = 0;
	flags->indic.space = 0;
	flags->indic.sign = 0;
	flags->indic.left = 0;
	flags->indic.zero = ' ';
	flags->indic.diese = 0;
	flags->ptr = 0;
}

int			ft_fill(int i, int size, char sym, t_flagpf *flags)
{
	while (i < size)
	{
		ft_putcharb(flags, sym);
		i++;
	}
	return (i);
}

uintmax_t	ft_taillnbru(va_list *args, t_flagpf *flags)
{
	uintmax_t	n;

	n = va_arg(*args, uintmax_t);
	if (flags->taille == 'j')
		return ((uintmax_t)n);
	else if (flags->taille == 'z')
		return ((size_t)n);
	else if (flags->taille == 'h')
		return ((short unsigned int)n);
	else if (flags->taille == 'H')
		return ((unsigned char)n);
	else if (flags->taille == 'l')
		return ((long unsigned int)n);
	else if (flags->taille == 'L')
		return ((long long unsigned int)n);
	else
		return ((unsigned int)n);
	return (n);
}

intmax_t	ft_taillnbr(va_list *args, t_flagpf *flags)
{
	intmax_t	n;

	n = va_arg(*args, intmax_t);
	if (flags->taille == 'j')
		return ((intmax_t)n);
	else if (flags->taille == 'z')
		return ((size_t)n);
	else if (flags->taille == 'h')
		return ((short int)n);
	else if (flags->taille == 'H')
		return ((char)n);
	else if (flags->taille == 'l')
		return ((long)n);
	else if (flags->taille == 'L')
		return ((long long)n);
	else
		return ((int)n);
	return (n);
}

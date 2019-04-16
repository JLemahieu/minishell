/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 04:43:55 by jlemahie          #+#    #+#             */
/*   Updated: 2018/05/24 07:06:04 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putwcharb(t_flagpf *flags, wchar_t c)
{
	if (c <= 255)
		ft_putcharb(flags, c);
	else if (c <= 0x7FF)
	{
		ft_putcharb(flags, (c >> 6) + 0xC0);
		ft_putcharb(flags, (c & 0x3F) + 0x80);
	}
	else if (c <= 0xFFFF)
	{
		ft_putcharb(flags, (c >> 12) + 0xE0);
		ft_putcharb(flags, ((c >> 6) & 0x3F) + 0x80);
		ft_putcharb(flags, (c & 0x3F) + 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		ft_putcharb(flags, (c >> 18) + 0xF0);
		ft_putcharb(flags, ((c >> 12) & 0x3F) + 0x80);
		ft_putcharb(flags, ((c >> 6) & 0x3F) + 0x80);
		ft_putcharb(flags, (c & 0x3F) + 0x80);
	}
}

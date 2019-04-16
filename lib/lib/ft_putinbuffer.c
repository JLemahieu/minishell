/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putinbuffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 09:48:35 by jlemahie          #+#    #+#             */
/*   Updated: 2018/05/27 01:38:18 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/includepf.h"

void	ft_putbuff(t_flagpf *flags, unsigned int n)
{
	unsigned int	i;

	if (flags->i > n)
		i = n;
	else
		i = flags->i;
	write(1, flags->buff, i);
	flags->i = 0;
	flags->backup = 0;
}

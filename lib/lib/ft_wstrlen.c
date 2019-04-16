/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 06:35:42 by jlemahie          #+#    #+#             */
/*   Updated: 2018/05/27 01:38:34 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/includepf.h"

int	ft_wstrlen(wchar_t *str, t_flagpf *flags)
{
	int	i;
	int	ret;
	int size;

	ret = 0;
	i = 0;
	while (str[i] != 0)
	{
		size = ft_wcharlen(str[i]);
		if (size == -1 && (str[i] > 255 || str[i] < 0))
			return (-1);
		ret = ret + size;
		if (ret >= flags->preci && flags->preci != -1)
			return (flags->preci);
		i++;
	}
	return (ret);
}

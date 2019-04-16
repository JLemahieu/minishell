/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mallocheck.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 02:05:02 by jlemahie          #+#    #+#             */
/*   Updated: 2018/05/03 02:10:05 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_mallocheck(size_t size)
{
	void	*x;

	x = malloc(size);
	if (x == NULL)
	{
		ft_putendl("Erreur malloc");
		exit(0);
	}
	return (x);
}

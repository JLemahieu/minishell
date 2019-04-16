/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 03:10:25 by jlemahie          #+#    #+#             */
/*   Updated: 2018/09/20 00:49:50 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/incshell.h"

int	bi_myecho(t_shell *shell)
{
	int	i;

	i = 1;
	while (shell->tabline[i])
	{
		ft_printf("%s", shell->tabline[i]);
		i++;
		if (shell->tabline[i])
			ft_putchar(' ');
	}
	ft_putchar('\n');
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 09:53:29 by jlemahie          #+#    #+#             */
/*   Updated: 2018/09/25 02:29:38 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/incshell.h"

int	bi_exit(t_shell *shell)
{
	if (shell->tmp == 0)
	{
		ft_freeshell(shell);
		exit(0);
	}
	else
		ft_printf("env: exit: No such file or directory\n");
	return (-1);
}

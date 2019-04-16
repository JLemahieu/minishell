/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usages.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 16:26:31 by jlemahie          #+#    #+#             */
/*   Updated: 2018/09/18 17:47:33 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/incshell.h"

int	us_unsetenv(int u, char *str)
{
	if (u == 3)
		ft_putstr_fd("env: ", 2);
	if (u >= 2)
	{
		ft_putstr_fd("unsetenv ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": Invalid argument\n", 2);
	}
	if (u == 0)
	{
		ft_putstr_fd("unsetenv: option requires an argument\n", 2);
		ft_putstr_fd("usage: unsetenv [name ...]\n", 2);
	}
	else if (u == 1)
	{
		ft_putstr_fd("env: option requires an argument -- u\n", 2);
		ft_putstr_fd("usage: env [-i] [-u name] [name=value ...]\n", 2);
		ft_putstr_fd("		[utility [argument ...]]\n", 2);
	}
	return (-1);
}

int	us_env(t_shell *shell, char c)
{
	ft_freeshell(shell);
	ft_putstr_fd("env: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\nusage: env [-i] [u name] [name=value ...]\n", 2);
	ft_putstr_fd("		[utility [argument ...]]\n", 2);
	return (-1);
}

int	us_setenv(t_shell *shell, char *str)
{
	if (str == NULL)
	{
		ft_putstr_fd("setenv: option requires an argument\n", 2);
		ft_putstr_fd("usage: setenv [name [value]]\n", 2);
	}
	else
	{
		if (shell->tmp == 1)
			ft_putstr_fd("env: ", 2);
		ft_putstr_fd("setenv ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": Invalid argument\n", 2);
	}
	return (-1);
}

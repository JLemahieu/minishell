/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 05:47:58 by jlemahie          #+#    #+#             */
/*   Updated: 2018/09/24 23:05:35 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/incshell.h"

int		ft_freetmpenv(t_shell *shell)
{
	int i;

	i = 0;
	if (shell->tmpenv)
	{
		while (shell->tmpenv[i])
		{
			ft_strdel(&shell->tmpenv[i]);
			i++;
		}
		free(shell->tmpenv[i]);
		free(shell->tmpenv);
		shell->tmpenv = NULL;
	}
	return (-2);
}

void	ft_freetabline(t_shell *shell)
{
	int	i;

	i = 0;
	if (shell->tabline)
	{
		if (shell->tmp == 0)
		{
			while (i != shell->sizetab)
			{
				free(shell->tabline[i]);
				i++;
			}
		}
		else
		{
			while (shell->tabline[i])
			{
				free(shell->tabline[i]);
				i++;
			}
		}
		free(shell->tabline[i]);
		free(shell->tabline);
		shell->tabline = NULL;
	}
}

void	ft_freeenv(t_shell *shell)
{
	int	i;

	i = 0;
	if (shell->env)
	{
		while (shell->env[i])
		{
			ft_strdel(&shell->env[i]);
			i++;
		}
		free(shell->env[i]);
		free(shell->env);
		shell->env = NULL;
	}
}

int		ft_freeshell(t_shell *shell)
{
	ft_strdel(&shell->home);
	ft_strdel(&shell->path);
	ft_freetabline(shell);
	ft_freeenv(shell);
	return (-2);
}

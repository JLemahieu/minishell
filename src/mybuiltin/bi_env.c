/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 08:39:35 by jlemahie          #+#    #+#             */
/*   Updated: 2018/09/24 23:13:10 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/incshell.h"

int	ft_affenv(t_shell *shell)
{
	int i;

	i = 0;
	while (shell->env[i])
	{
		ft_printf("%s\n", shell->env[i]);
		i++;
	}
	return (0);
}

int	ft_parseuenv(t_shell *shell, t_shell *tmpshell)
{
	int ret;

	while (shell->tabline[shell->en] && shell->tabline[shell->en][0] == '-')
	{
		if (ft_strcmp(shell->tabline[shell->en], "-i") == 0 ||
			ft_strcmp(shell->tabline[shell->en], "-") == 0)
		{
			if ((ret = ft_unsetall(tmpshell)) < 0)
				return (ft_freeshell(tmpshell));
		}
		else if (ft_strcmp(shell->tabline[shell->en], "-u") == 0)
		{
			if ((ret = ft_unsetenv(tmpshell, shell->tabline[++shell->en],
				1)) < 0)
			{
				ft_freeshell(tmpshell);
				return ((ret == -1) ? -1 : -2);
			}
		}
		else
			return (us_env(tmpshell, shell->tabline[shell->en][1]));
		shell->en++;
	}
	return (0);
}

int	ft_parsesenv(t_shell *shell, t_shell *tmpshell)
{
	int ret;

	while (shell->tabline[shell->en] &&
		ft_strchr(shell->tabline[shell->en], '='))
	{
		if ((ret = ft_setenv(tmpshell,
			ft_strdup(shell->tabline[shell->en]))) < 0)
		{
			ft_freeshell(tmpshell);
			return ((ret == -1) ? -1 : -2);
		}
		shell->en++;
	}
	if (!(tmpshell->tabline = ft_tabdup(shell->tabline, shell->en)))
		return (ft_freeshell(tmpshell));
	return (0);
}

int	ft_tmpmain(t_shell *shell, t_shell *tmpshell)
{
	int ret;

	if (ft_dupenv(tmpshell, shell->env) == -2)
		return (-2);
	if ((ret = ft_parseuenv(shell, tmpshell)) < 0)
		return ((ret == -1) ? -1 : -2);
	if ((ret = ft_parsesenv(shell, tmpshell)) < 0)
		return ((ret == -1) ? -1 : -2);
	if (!(tmpshell->tabline[0]))
		ft_affenv(tmpshell);
	else
	{
		if (ft_getpath(tmpshell) == -1)
			return (ft_freeshell(tmpshell));
		if (ft_gethome(tmpshell) == -1)
			return (ft_freeshell(tmpshell));
		if (ft_checkmi(tmpshell, tmpshell->tabline[0]) == -2)
			return (ft_freeshell(tmpshell));
	}
	ft_freeshell(tmpshell);
	return (0);
}

int	bi_env(t_shell *shell)
{
	t_shell tmpshell;

	if (!(shell->tabline[1]))
		return (ft_affenv(shell));
	else
	{
		tmpshell.tmp = 1;
		shell->en = 1;
		tmpshell.path = NULL;
		tmpshell.home = NULL;
		tmpshell.tabline = NULL;
		return (ft_tmpmain(shell, &tmpshell));
	}
}

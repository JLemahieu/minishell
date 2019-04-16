/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 07:31:34 by jlemahie          #+#    #+#             */
/*   Updated: 2018/09/18 17:47:15 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/incshell.h"

int	ft_unsetall(t_shell *shell)
{
	ft_freeenv(shell);
	if (!(shell->env = malloc(1 * sizeof(char*))))
		return (-2);
	shell->env[0] = NULL;
	return (0);
}

int	ft_isuenv(t_shell *shell, char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (shell->env[i])
	{
		if (!(tmp = ft_strtronc(shell->env[i], '=')))
			return (-2);
		if (ft_strcmp(tmp, str) == 0)
		{
			ft_strdel(&tmp);
			return (i);
		}
		ft_strdel(&tmp);
		i++;
	}
	return (-1);
}

int	ft_uenv(t_shell *shell, int u)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (shell->env[i])
	{
		if (i != u)
		{
			if (!(shell->tmpenv[x] = ft_strdup(shell->env[i])))
				return (ft_freetmpenv(shell));
			x++;
		}
		i++;
	}
	shell->tmpenv[x] = NULL;
	return (ft_swapenv(shell));
}

int	ft_unsetenv(t_shell *shell, char *str, int x)
{
	int u;
	int l;

	l = 0;
	if (str == 0)
		return (us_unsetenv(x, NULL));
	if (str[0] == '=')
		return (us_unsetenv(x + 2, str));
	u = ft_isuenv(shell, str);
	if (u == -2)
		return (-2);
	if (u == -1)
		return (0);
	while (shell->env[l])
		l++;
	if (!(shell->tmpenv = malloc((l) * sizeof(char *))))
		return (-2);
	return (ft_uenv(shell, u));
}

int	bi_unsetenv(t_shell *shell)
{
	int i;
	int ret;

	i = 1;
	while (shell->tabline[i])
	{
		if ((ret = ft_unsetenv(shell, shell->tabline[i], 0)) < 0)
			return (ret);
		i++;
	}
	if (i == 1)
		return (us_unsetenv(0, NULL));
	return (0);
}

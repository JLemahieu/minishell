/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 12:41:00 by jlemahie          #+#    #+#             */
/*   Updated: 2018/09/18 17:46:56 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/incshell.h"

int	ft_senv(t_shell *shell, char *str)
{
	int l;
	int i;
	int ret;

	l = 0;
	ret = 0;
	while (shell->env[l])
		l++;
	if (!(shell->tmpenv = malloc((l + 2) * sizeof(char*))))
		ret = ft_freetmpenv(shell);
	i = 0;
	while (ret == 0 && shell->env[i])
	{
		if (!(shell->tmpenv[i] = ft_strdup(shell->env[i])))
			ret = ft_freetmpenv(shell);
		i++;
	}
	if ((ret != 0) || (!(shell->tmpenv[i] = ft_strdup(str))))
		ret = ft_freetmpenv(shell);
	i++;
	if (ret == 0)
		shell->tmpenv[i] = NULL;
	ft_strdel(&str);
	return ((ret != 0) ? ret : ft_swapenv(shell));
}

int	ft_setenv(t_shell *shell, char *str)
{
	char	*tmp;
	int		u;
	int		ret;

	if ((!str) || str[0] == '=')
	{
		ret = (!str) ? -2 : us_setenv(shell, str);
		ft_strdel(&str);
		return (ret);
	}
	if (!(tmp = ft_strtronc(str, '=')))
	{
		ft_strdel(&str);
		return (-2);
	}
	u = ft_unsetenv(shell, tmp, 0);
	ft_strdel(&tmp);
	if (u == -2)
	{
		ft_strdel(&str);
		return (-2);
	}
	ret = ft_senv(shell, ft_strdup(str));
	ft_strdel(&str);
	return (ret);
}

int	bi_setenv(t_shell *shell)
{
	int i;
	int ret;

	i = 1;
	while (shell->tabline[i])
	{
		if (shell->tabline[i + 1])
		{
			if ((ret = (ft_setenv(shell, ft_strjoinsep(shell->tabline[i],
				'=', shell->tabline[i + 1])))) < 0)
				return (ret);
			i++;
		}
		else
		{
			if ((ret = ft_setenv(shell, ft_strjoin(shell->tabline[i],
				"="))) < 0)
				return (ret);
		}
		i++;
	}
	if (i == 1)
		return (us_setenv(shell, NULL));
	return (0);
}

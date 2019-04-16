/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 08:28:14 by jlemahie          #+#    #+#             */
/*   Updated: 2018/09/25 04:20:36 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/incshell.h"

char	**ft_tabdup(char **tab, int st)
{
	int		i;
	int		o;
	char	**ret;

	i = st;
	o = 0;
	while (tab[i])
		i++;
	if (!(ret = malloc((i - st + 1) * sizeof(char*))))
		return (NULL);
	i = i - st;
	while (o != i)
	{
		if (!(ret[o] = ft_strdup(tab[st])))
		{
			while (o != -1)
				ft_strdel(&ret[o--]);
			free(ret);
			return (ret = NULL);
		}
		st++;
		o++;
	}
	ret[o] = 0;
	return (ret);
}

int		ft_dupenv(t_shell *shell, char **env)
{
	int i;
	int l;

	l = 0;
	while (env[l])
		l++;
	if (!(shell->env = malloc((l + 1) * sizeof(char *))))
		return (-2);
	i = 0;
	while (env[i])
	{
		if (!(shell->env[i] = ft_strdup(env[i])))
		{
			while (i != -1)
				ft_strdel(&shell->env[i--]);
			free(shell->env);
			shell->env = NULL;
			return (-2);
		}
		i++;
	}
	shell->env[i] = NULL;
	return (1);
}

int		ft_swapenv(t_shell *shell)
{
	int i;
	int ret;

	i = 0;
	ft_freeenv(shell);
	ret = ft_dupenv(shell, shell->tmpenv);
	ft_freetmpenv(shell);
	return (ret);
}

int		ft_envshr(t_shell *shell, char *var)
{
	int	i;
	int	l;

	i = 0;
	l = ft_strlen(var);
	while (shell->env[i])
	{
		if (ft_strncmp(shell->env[i], var, l) == 0)
			return (i);
		i++;
	}
	return (-1);
}

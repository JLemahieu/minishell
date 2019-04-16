/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varsh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 23:57:27 by jlemahie          #+#    #+#             */
/*   Updated: 2018/09/25 04:34:05 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/incshell.h"

static int	ft_parsevar(t_shell *shell, int i, int x)
{
	int		a;
	char	*tmp;
	char	*t2;

	if (!(tmp = ft_strtronc(&shell->tabline[i][x + 1], ' ')))
		return (-1);
	a = ft_envshr(shell, tmp);
	ft_strdel(&tmp);
	if (!(t2 = ft_strtronc(shell->tabline[i], '$')))
		return (-1);
	tmp = (a > -1) ? ft_strjoin(t2, ft_strchr(shell->env[a], '=')
		+ 1) : ft_strdup(t2);
	while (shell->tabline[i][x] && shell->tabline[i][x] != ' ')
		x++;
	ft_strdel(&t2);
	if (tmp == NULL)
		return (-1);
	t2 = ft_strjoin(tmp, &shell->tabline[i][x]);
	ft_strdel(&shell->tabline[i]);
	if (t2 == NULL)
		return (-1);
	shell->tabline[i] = ft_strdup(t2);
	ft_strdel(&tmp);
	ft_strdel(&t2);
	return ((shell->tabline[i] != NULL) ? 0 : -1);
}

static int	ft_dolnovar(t_shell *shell, int i, int x)
{
	char	*tmp;
	char	*t2;

	tmp = ft_strndup(shell->tabline[i], x - 1);
	t2 = ft_strdup(&shell->tabline[i][x]);
	ft_strdel(&shell->tabline[i]);
	if (tmp != NULL && t2 != NULL)
		shell->tabline[i] = ft_strjoin(tmp, t2);
	ft_strdel(&tmp);
	ft_strdel(&t2);
	return ((shell->tabline[i] != NULL) ? 0 : -1);
}

int			ft_varsh(t_shell *shell)
{
	int	i;
	int	x;

	i = 0;
	while (shell->tabline[i])
	{
		x = 0;
		while (shell->tabline[i][x])
		{
			if (shell->tabline[i][x] == '$' && shell->tabline[i][x - 1] != '\\')
			{
				if (ft_parsevar(shell, i, x) == -1)
					return (ft_printnret(-1, "Erreur memoire parsing\n"));
			}
			else if (shell->tabline[i][x] == '$' &&
				shell->tabline[i][x - 1] == '\\')
			{
				if (ft_dolnovar(shell, i, x) == -1)
					return (ft_printnret(-1, "Erreur memoire parsing\n"));
			}
			x++;
		}
		i++;
	}
	return (0);
}

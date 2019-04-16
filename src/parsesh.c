/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsesh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 19:19:44 by jlemahie          #+#    #+#             */
/*   Updated: 2018/09/24 23:57:52 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/incshell.h"

static int	ft_dquote(t_shell *shell, int x, int i)
{
	char	*l2;
	char	*tmp;

	while (x % 2 != 0)
	{
		l2 = NULL;
		ft_printf("dquote>");
		get_next_line(0, &l2);
		tmp = ft_strdup(shell->line);
		ft_strdel(&shell->line);
		if (tmp != NULL && l2 != NULL)
			shell->line = ft_strjoinsep(tmp, '\n', l2);
		free(tmp);
		free(l2);
		if (shell->line == NULL)
			return (ft_printnret(-1, "Erreur memoire parsing\n"));
		while (shell->line[i])
		{
			if (shell->line[i] == '"' && shell->line[i - 1] != '\\')
				x++;
			i++;
		}
	}
	return (0);
}

static int	ft_getprimline(t_shell *shell)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	if (get_next_line(0, &shell->line) <= 0)
		return (ft_printnret(-1, "Erreur memoire parsing\n"));
	if (ft_strlen(shell->line) == 0)
		return (-1);
	while (shell->line[i])
	{
		if (shell->line[i] == '"' && shell->line[i - 1] != '\\')
			x++;
		i++;
	}
	return (ft_dquote(shell, x, i));
}

static int	ft_homesh(t_shell *shell)
{
	int		i;
	char	*tmp;

	i = 0;
	while (shell->tabline[i])
	{
		if (shell->tabline[i][0] == '~')
		{
			if (shell->home == NULL)
				return (ft_printnret(-1, "No $HOME variable set\n"));
			if (!(tmp = ft_strjoin(shell->home, &shell->tabline[i][1])))
				return (ft_printnret(-1, "Erreur memoire parsing\n"));
			ft_strdel(&shell->tabline[i]);
			if (!(shell->tabline[i] = ft_strdup(tmp)))
			{
				ft_strdel(&tmp);
				return (ft_printnret(-1, "Erreur memoire parsing\n"));
			}
			ft_strdel(&tmp);
		}
		i++;
	}
	return (0);
}

int			ft_parse_sh(t_shell *shell)
{
	shell->sizetab = 0;
	if (ft_getprimline(shell) < 0)
		return (42);
	if (ft_strsplitsh(shell) < 0)
		return (42);
	if (ft_homesh(shell) < 0)
		return (42);
	if (ft_sanquo(shell) < 0)
		return (42);
	if (ft_varsh(shell) < 0)
		return (42);
	return (0);
}

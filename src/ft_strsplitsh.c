/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitsh.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 22:49:26 by jlemahie          #+#    #+#             */
/*   Updated: 2018/09/25 02:19:53 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/incshell.h"

static int	ft_carg(char *line)
{
	int i;
	int ret;
	int q;

	q = 0;
	i = 0;
	ret = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	while (line[i])
	{
		if (line[i] == '"' && line[i - 1] != '\\')
			q = (q == 0) ? 1 : 0;
		if (line[i] != ' ' && line[i] != '\t')
		{
			if ((line[i + 1] == ' ' || line[i + 1] == '\t' || line[i + 1] == 0)
				&& q == 0)
				ret++;
		}
		i++;
	}
	return (ret);
}

static int	ft_countlsh(char *line)
{
	int ret;
	int q;
	int l;

	ret = 0;
	q = 0;
	l = 0;
	while (line[l] == ' ' || line[l] == '\t')
		l++;
	while (line[l])
	{
		if (line[l] == '"' && line[l - 1] != '\\')
			q = (q == 0) ? 1 : 0;
		if ((line[l] == ' ' || line[l] == '\t') && q == 0)
			return (ret);
		ret++;
		l++;
	}
	return (ret);
}

int			ft_strsplitsh(t_shell *shell)
{
	int nbarg;
	int i;
	int x;
	int nbl;

	nbarg = ft_carg(shell->line);
	if (!(shell->tabline = malloc((nbarg + 1) * sizeof(char *))))
		return (ft_printnret(-1, "Erreur memoire parsing\n"));
	i = 0;
	x = 0;
	while (shell->line[x] == '\t' || shell->line[x] == ' ')
		x++;
	while (i != nbarg)
	{
		nbl = ft_countlsh(&shell->line[x]);
		if (!(shell->tabline[i] = ft_strndup(&shell->line[x], nbl)))
			return (ft_printnret(-1, "Erreur memoire parsing\n"));
		x += nbl;
		while (shell->line[x] == '\t' || shell->line[x] == ' ')
			x++;
		i++;
	}
	shell->sizetab = (i > 0) ? i - 1 : 0;
	shell->tabline[i] = 0;
	return (0);
}

static int	ft_shdupsan(t_shell *shell, int i, int l)
{
	char	*tmp;
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (!(tmp = ft_strnew(l)))
		return (-1);
	while (shell->tabline[i][x])
	{
		if (shell->tabline[i][x] != '"')
		{
			if (shell->tabline[i][x] == '\\' && shell->tabline[i][x + 1] == '"')
				tmp[y] = '"';
			else
				tmp[y] = shell->tabline[i][x];
			y++;
		}
		x++;
	}
	ft_strdel(&shell->tabline[i]);
	shell->tabline[i] = ft_strdup(tmp);
	ft_strdel(&tmp);
	return ((shell->tabline[i] == NULL) ? -1 : 0);
}

int			ft_sanquo(t_shell *shell)
{
	int i;
	int l;
	int x;

	i = 0;
	while (shell->tabline[i])
	{
		l = 0;
		x = 0;
		while (shell->tabline[i][x])
		{
			if (shell->tabline[i][x] != '"')
				l++;
			x++;
		}
		if (x != l)
		{
			if (ft_shdupsan(shell, i, l) == -1)
				return (ft_printnret(-1, "Erreur memoire parsing\n"));
		}
		i++;
	}
	return (0);
}

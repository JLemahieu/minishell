/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 17:58:21 by jlemahie          #+#    #+#             */
/*   Updated: 2018/09/24 23:47:40 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/incshell.h"

int	ft_access(char *apath)
{
	struct stat	ch;
	char		*buf;

	buf = ft_strnew(500);
	if ((buf = getcwd(buf, 500)) == NULL)
	{
		free(buf);
		ft_printf("cd: %s: Not a directory\n", apath);
		return (-1);
	}
	free(buf);
	if (lstat(apath, &ch) == -1)
		return (ft_printnret(-1, "cd: No such file or directory: %s\n", apath));
	if ((ch.st_mode & S_IFMT) != S_IFDIR)
		return (ft_printnret(-1, "cd: Not a directory: %s\n", apath));
	if ((ch.st_mode & S_IXUSR) == 0)
		return (ft_printnret(-1, "cd: Permission denied: %s\n", apath));
	return (-1);
}

int	ft_cd(t_shell *shell, char *path)
{
	char	*tmp;
	int		i;
	int		ret;

	tmp = NULL;
	ret = 0;
	tmp = getcwd(tmp, 0);
	if (chdir(path) == -1)
		ret = ft_access(path);
	if (ret >= 0 && (i = ft_envshr(shell, "OLDPWD=")) != -1)
		ret = ft_setenv(shell, ft_strjoin("OLDPWD=", tmp));
	free(tmp);
	tmp = NULL;
	tmp = getcwd(tmp, 0);
	if (ret >= 0 && (i = ft_envshr(shell, "PWD=")) != -1)
		ret = ft_setenv(shell, ft_strjoin("PWD=", tmp));
	free(tmp);
	return (ret);
}

int	bi_cd(t_shell *shell)
{
	int i;

	if (shell->tmp == 1)
		return (0);
	if (!(shell->tabline[1]))
	{
		if ((i = ft_envshr(shell, "HOME=")) != -1 && shell->env[i][5] != 0)
			return (ft_cd(shell, shell->env[i] + 5));
		else
			return (ft_printnret(-1, "cd: HOME not set\n"));
	}
	if (ft_strcmp(shell->tabline[1], "-") == 0)
	{
		if ((i = ft_envshr(shell, "OLDPWD=")) != -1 && shell->env[i][7] != 0)
			return (ft_cd(shell, shell->env[i] + 7));
		else
			return (0);
	}
	return (ft_cd(shell, shell->tabline[1]));
}

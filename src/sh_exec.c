/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 23:54:41 by jlemahie          #+#    #+#             */
/*   Updated: 2018/10/01 23:48:30 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/incshell.h"

char	*ft_patsh(char *s1, char *s2)
{
	char	*ret;
	char	*tmp;

	if (!(tmp = ft_strtronc(s1, ':')))
		return (NULL);
	ret = ft_strjoinsep(tmp, '/', s2);
	ft_strdel(&tmp);
	return (ret);
}

int		ft_execbi(t_shell *shell, char *com)
{
	int		ret;
	pid_t	proc;

	ret = 0;
	if (access(com, X_OK) != 0)
		return (ft_printnret(-1, "minishell: permission denied: %s\n", com));
	if ((proc = fork()) == -1)
		return (ft_printnret(-1, "Erreur memoire\n"));
	if (proc == 0)
		ret = execve(com, shell->tabline, shell->env);
	else
		waitpid(proc, NULL, 0);
	return (ret);
}

int		ft_checkbi(t_shell *shell, char *com)
{
	char	*tmpath;
	char	*name;
	int		ret;

	if (shell->path == NULL || com[0] == 0)
		return (ft_error(shell));
	tmpath = shell->path;
	while (tmpath)
	{
		if ((name = ft_patsh(tmpath, com)) == NULL)
			return (ft_printnret(-1, "Erreur memoire\n"));
		if (access(name, F_OK) == 0)
		{
			ret = ft_execbi(shell, name);
			free(name);
			return (ret);
		}
		free(name);
		tmpath = (ft_strchr(tmpath, ':')) ? ft_strchr(tmpath, ':') + 1 : NULL;
	}
	return (ft_error(shell));
}

int		ft_checkex(t_shell *shell, char *s)
{
	struct stat	ch;

	if (ft_strchr(s, '/') != NULL)
	{
		if (access(s, F_OK) == 0)
		{
			lstat(s, &ch);
			if ((ch.st_mode & S_IFMT) == S_IFDIR)
				return (ft_printnret(-1, "minishell: %s: Is a directory\n", s));
			return (ft_execbi(shell, s));
		}
		else
			return (ft_printnret(-1, "minishell: No such file or directory\n"));
	}
	else
		return (ft_checkbi(shell, s));
}

int		ft_checkmi(t_shell *shell, char *com)
{
	ft_getpath(shell);
	if (!(com))
		return (0);
	if (ft_strcmp(com, "echo") == 0)
		return (bi_myecho(shell));
	else if (ft_strcmp(com, "cd") == 0)
		return (bi_cd(shell));
	else if (ft_strcmp(com, "env") == 0)
		return (bi_env(shell));
	else if (ft_strcmp(com, "setenv") == 0)
		return (bi_setenv(shell));
	else if (ft_strcmp(com, "unsetenv") == 0)
		return (bi_unsetenv(shell));
	else if (ft_strcmp(com, "exit") == 0)
		return (bi_exit(shell));
	return (ft_checkex(shell, com));
}

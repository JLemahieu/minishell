/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 18:55:15 by jlemahie          #+#    #+#             */
/*   Updated: 2018/10/01 23:48:18 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/incshell.h"

int	ft_error(t_shell *shell)
{
	if (shell->tmp == 0)
		ft_printf("minishell: command not found: %s\n", shell->tabline[0]);
	else
		ft_printf("env: %s: No such file or directory\n", shell->tabline[0]);
	return (-1);
}

int	ft_getpath(t_shell *shell)
{
	int i;

	i = 0;
	shell->path = NULL;
	while (shell->env[i])
	{
		if (ft_strncmp(shell->env[i], "PATH=", 5) == 0)
		{
			if (!(shell->path = ft_strdup(shell->env[i] + 5)))
				return (ft_printnret(-1, "Getpath erreur memoire\n"));
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_gethome(t_shell *shell)
{
	int i;

	i = 0;
	shell->home = NULL;
	shell->path = NULL;
	while (shell->env[i])
	{
		if (ft_strncmp(shell->env[i], "HOME=", 5) == 0)
		{
			if (!(shell->home = ft_strdup(shell->env[i] + 5)))
				return (ft_printnret(-1, "Gethome erreur memoire\n"));
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(void)
{
	t_shell		shell;
	int			ret;
	extern char	**environ;

	shell.tmp = 0;
	shell.tabline = NULL;
	ft_printf("$>");
	if (ft_dupenv(&shell, environ) == -2)
		exit(0);
	ft_gethome(&shell);
	while ((ret = ft_parse_sh(&shell)) >= 0)
	{
		if (ret != 42)
			if (shell.tabline != NULL)
				if (ft_checkmi(&shell, shell.tabline[0]) == -2)
					ft_printf("Erreur memoire\n");
		ft_freetabline(&shell);
		ft_strdel(&shell.path);
		ft_strdel(&shell.line);
		if (shell.env == NULL)
			bi_exit(&shell);
		ft_printf("$>");
	}
	return (0);
}

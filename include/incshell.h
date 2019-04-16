/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incshell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 18:54:45 by jlemahie          #+#    #+#             */
/*   Updated: 2018/10/01 23:58:02 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCSHELL_H

# define INCSHELL_H
# include "../lib/include/inclib.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct	s_shell
{
	char	*path;
	char	**tabline;
	char	*line;
	int		en;
	int		sizetab;
	int		tmp;
	char	**env;
	char	**tmpenv;
	char	*home;
}				t_shell;

int				ft_varsh(t_shell *shell);
int				ft_sanquo(t_shell *shell);
int				ft_strsplitsh(t_shell *shell);
int				ft_parse_sh(t_shell *shell);
int				ft_checkmi(t_shell *shell, char *com);
int				ft_envshr(t_shell *shell, char *var);
int				bi_cd(t_shell *shell);
int				us_setenv(t_shell *shell, char *str);
int				us_unsetenv(int u, char *str);
int				us_env(t_shell *shell, char c);
char			**ft_tabdup(char **tab, int st);
int				ft_setenv(t_shell *shell, char *str);
int				ft_unsetall(t_shell *shell);
int				bi_env(t_shell *shell);
int				ft_freetmpenv(t_shell *shell);
int				bi_setenv(t_shell *shell);
int				ft_freeshell(t_shell *shell);
int				bi_exit(t_shell *shell);
int				ft_dupenv(t_shell *shell, char **env);
void			ft_freeenv(t_shell *shell);
void			ft_freetabline(t_shell *shell);
int				ft_swapenv(t_shell *shell);
int				ft_unsetenv(t_shell *shell, char *str, int x);
int				bi_unsetenv(t_shell *shell);
int				ft_error(t_shell *shell);
int				bi_myecho(t_shell *shell);
int				ft_affenv(t_shell *shell);
int				ft_getpath(t_shell *shell);
int				ft_gethome(t_shell *shell);

#endif

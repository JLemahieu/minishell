/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:05:35 by jlemahie          #+#    #+#             */
/*   Updated: 2018/03/30 00:02:28 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static	int		ft_count_words(char const *str, char c)
{
	int	i;
	int	ct;

	i = 0;
	ct = 0;
	while (str[i] != 0)
	{
		if (str[i] != c)
		{
			if (str[i + 1] == c || str[i + 1] == 0)
				ct++;
		}
		i++;
	}
	return (ct);
}

static	int		ft_count_letters(char const *str, int nb, char c)
{
	int	i;
	int	ct;
	int	l;

	i = 0;
	l = 0;
	ct = 0;
	while (ct != nb)
	{
		if (str[i] != c)
		{
			if (str[i + 1] == c || str[i + 1] == 0)
				ct++;
		}
		i++;
	}
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i] != 0)
	{
		i++;
		l++;
	}
	return (l);
}

static	char	*ft_set(char const *str, int nb, int nbl, char c)
{
	int		i;
	int		ct;
	int		l;
	char	*word;

	i = 0;
	ct = 0;
	l = 0;
	word = malloc(nbl + 1 * sizeof(char));
	while (ct != nb)
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == 0))
			ct++;
		i++;
	}
	while (str[i] == c)
		i++;
	while (l < nbl)
	{
		word[l] = str[i];
		i++;
		l++;
	}
	word[l] = 0;
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tabstr;
	int		nbw;
	int		a;
	int		nbl;

	a = 0;
	nbw = ft_count_words(s, c);
	if ((tabstr = malloc((nbw + 1) * sizeof(char *))) == NULL)
		return (NULL);
	while (a < nbw)
	{
		nbl = ft_count_letters(s, a, c);
		tabstr[a] = ft_set(s, a, nbl, c);
		a++;
	}
	tabstr[a] = 0;
	return (tabstr);
}

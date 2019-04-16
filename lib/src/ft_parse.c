/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 03:15:25 by jlemahie          #+#    #+#             */
/*   Updated: 2018/05/27 02:23:33 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includepf.h"
#include "../include/libft.h"

char	*ft_parse_indic(char **format, t_flagpf *flags)
{
	if (**format != ' ' && **format != '+' && **format != '-'
			&& **format != '0' && **format != '#')
		return (*format);
	else
	{
		if (**format == ' ')
			flags->indic.space = 1;
		else if (**format == '+')
			flags->indic.sign = 1;
		else if (**format == '-')
			flags->indic.left = 1;
		else if (**format == '0')
			flags->indic.zero = '0';
		else if (**format == '#')
			flags->indic.diese = 1;
		(*format)++;
		return (ft_parse_indic(format, flags));
	}
	return (NULL);
}

char	*ft_parse_large(char **format, t_flagpf *flags, va_list *args)
{
	if (**format == '*' || ft_isdigit(**format) == 1)
	{
		if (**format == '*')
		{
			flags->large = va_arg(*args, int);
			if (flags->large < 0)
			{
				flags->large = -flags->large;
				flags->indic.left = 1;
			}
			(*format)++;
			return (*format);
		}
		else
		{
			flags->large = ft_patoi(ft_strndup((*format), 10));
			(*format) = (*format) + ft_nbrlen(flags->large);
			return (*format);
		}
	}
	return (*format);
}

char	*ft_parse_preci(char **format, t_flagpf *flags, va_list *args)
{
	if (**format == '.')
	{
		(*format)++;
		if (**format == '*' || ft_isdigit(**format) == 1)
		{
			if (**format == '*')
			{
				flags->preci = va_arg(*args, int);
				if (flags->preci < 0)
					flags->preci = -1;
				(*format)++;
				return (*format);
			}
			else
			{
				flags->preci = ft_patoi(ft_strndup((*format), 10));
				(*format) = (*format) + ft_nbrlen(flags->preci);
				return (*format);
			}
		}
		else
			flags->preci = 0;
	}
	return (*format);
}

char	*ft_parse_taille(char **format, t_flagpf *flags)
{
	if (**format == 'j' || **format == 'z')
	{
		flags->taille = **format;
		(*format)++;
		return (*format);
	}
	if (**format == 'h' || **format == 'l')
	{
		flags->taille = **format;
		(*format)++;
		if (**format == flags->taille)
		{
			flags->taille = flags->taille - 32;
			(*format)++;
		}
		return (*format);
	}
	return (*format);
}

char	*ft_parse_flag(char **format, t_flagpf *flags, char *test)
{
	int				i;

	i = 0;
	while (test[i] != 0)
	{
		if (test[i] == **format)
		{
			flags->flag = i;
			return (*format);
		}
		i++;
	}
	if (**format == '%')
	{
		flags->flag = i;
		return (*format);
	}
	else
	{
		flags->flag = i + 1;
		flags->ptr = **format;
		return (*format);
	}
	return (NULL);
}
